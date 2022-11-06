#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    n %= 6;
    if (x == 0) {
        if (n % 6 == 0 || n % 6 == 5) {
            cout << 0;
            return 0;
        }
        if (n % 6 == 1 || n % 6 == 2) {
            cout << 1;
            return 0;
        }
        cout << 2;
        return 0;
    }

    if (x == 1) {
        if (n % 6 == 1 || n % 6 == 4) {
            cout << 0;
            return 0;
        }
        if (n % 6 == 0 || n % 6 == 3) {
            cout << 1;
            return 0;
        }
        cout << 2;
        return 0;
    }


    if (x == 2) {
        if (n % 6 == 2 || n % 6 == 3) {
            cout << 0;
            return 0;
        }
        if (n % 6 == 4 || n % 6 == 5) {
            cout << 1;
            return 0;
        }
        cout << 2;
        return 0;
    }
    return 0;
}