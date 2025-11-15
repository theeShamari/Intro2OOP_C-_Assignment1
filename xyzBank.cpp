#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    double balance;

    // contruct initial balance
public: 
    Account(double init_balance){
        if (init_balance >= 1000.00) {
            balance = init_balance;
        } else {
            balance = 0;
            cout << "Initial balance invalid. Setting balance to $0.00" << endl;
        }
    }

    // deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Succeffully deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // withdraw function
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds resquested: $" << amount << endl;
            return false;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
            return false;
        } else {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
            return true;
        }
    }
    // get balance function
    double getBalance() const {
        return balance;
    }
};

int main() {
    double initialDeposit;
    cout << "Enter initial account balance: ";
    cin >> initialDeposit;

    Account myAccount(initialDeposit);

    int choice;
    do {
        cout << "\n===== XYZ Bank ATM Menu =====\n";
        cout << "1. Check Account Balance\n";
        cout << "2. Deposit Funds\n";
        cout << "3. Withdraw Funds\n";
        cout << "4. Exit\n";
        cout << "Choose an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current Balance: $" << myAccount.getBalance() << endl;
                break;
            case 2: {
                double depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                myAccount.deposit(depositAmount);
                break;
            }
            case 3: {
                double withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                myAccount.withdraw(withdrawAmount);
                break;
            }
            case 4:
                cout << "Thank you for using XYZ Bank ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}