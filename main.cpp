#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the basic set of components
struct Component {
    string description;
    double price;
};

unordered_map<string, Component> basicComponents = {
    {"A1", {"Compact", 75.00}},
    {"A2", {"Tower", 150.00}},
    {"B1", {"8 GB RAM", 79.99}},
    {"B2", {"16 GB RAM", 149.99}},
    {"B3", {"32 GB RAM", 299.99}},
    {"C1", {"1 TB HDD", 49.99}},
    {"C2", {"2 TB HDD", 89.99}},
    {"C3", {"4 TB HDD", 129.99}}
};

// Function to display menu and get user input
string displayMenu(const unordered_map<string, Component>& items, const string& category) {
    cout << "\n" << category << " Options:\n";
    for (const auto& item : items) {
        cout << item.first << ": " << item.second.description << " - $" << item.second.price << endl;
    }

    string choice;
    cout << "Choose a " << category << " item code: ";
    cin >> choice;

    while (items.find(choice) == items.end()) {
        cout << "Invalid choice. Please try again.\n";
        cout << "Choose a " << category << " item code: ";
        cin >> choice;
    }

    return choice;
}

// Task 1 - Setting up the system and ordering main items
void task1() {
    cout << "Welcome to the Online Computer Shop!\n";

    // Choose case, RAM, and Main HDD
    string caseChoice = displayMenu(basicComponents, "Case");
    string ramChoice = displayMenu(basicComponents, "RAM");
    string hddChoice = displayMenu(basicComponents, "Main HDD");

    // Calculate the price of the computer
    double computerPrice = basicComponents[caseChoice].price + basicComponents[ramChoice].price +
                          basicComponents[hddChoice].price + 200.0;

    // Output the chosen items and the price of the computer
    cout << "\nChosen Items:\n";
    cout << "Case: " << basicComponents[caseChoice].description << endl;
    cout << "RAM: " << basicComponents[ramChoice].description << endl;
    cout << "Main HDD: " << basicComponents[hddChoice].description << endl;
    cout << "\nPrice of the computer: $" << computerPrice << endl;
}

// Task 2 - Ordering additional items
void task2() {
    task1();  // Perform Task 1 first to choose main items
    int computerPrice,chosenItems;
    // Choose additional items
    string additionalChoice;
    cout << "\nDo you want to purchase additional items? (yes/no): ";
    cin >> additionalChoice;

    while (additionalChoice == "yes") {
        string categoryChoice;
        cout << "Choose a category (HDD/SSD): ";
        cin >> categoryChoice;

        string itemChoice = displayMenu(basicComponents, categoryChoice);

        // Update the price of the computer
        double additionalPrice = basicComponents[itemChoice].price;
        computerPrice =computerPrice + additionalPrice;

        // Output the additional items and the new price of the computer
        cout << "\nChosen Items:\n";
        cout << categoryChoice << ": " << basicComponents[itemChoice].description << endl;
        cout << "\nNew price of the computer: $" << computerPrice << endl;

        cout << "\nDo you want to purchase more additional items? (yes/no): ";
        cin >> additionalChoice;
    }
}

// Task 3 - Offering discounts
void task3() {
    task2();  // Perform Task 2 first to choose additional items
    int chosenItems,computerPrice;
    // Apply discounts based on the number of additional items
    int numAdditionalItems = chosenItems- 3;  // Deduct main items (case, RAM, Main HDD)

    double discount = (numAdditionalItems == 1) ? 0.05 : ((numAdditionalItems >= 2) ? 0.10 : 0);
    double discountAmount = computerPrice * discount;
    double discountedPrice = computerPrice - discountAmount;

    // Output the amount of money saved and the new price of the computer after the discount
    cout << "\nCongratulations! You have saved $" << discountAmount << " with the discount.\n";
    cout << "Discounted price of the computer: $" << discountedPrice << endl;
}

int main() {
    task3();  // Uncomment to run Task 3
    return 0;
}
