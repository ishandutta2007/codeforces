#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a + b) % 2) {
            if (a || d)
                cout << "Ya ";
            else
                cout << "Tidak ";
            if (b || c)
                cout << "Ya ";
            else
                cout << "Tidak ";
            cout << "Tidak Tidak\n";
        }
        else {
            cout << "Tidak Tidak ";
            if (b || c)
                cout << "Ya ";
            else
                cout << "Tidak ";
            if (a || d)
                cout << "Ya\n";
            else
                cout << "Tidak\n";
        }
    }

    return 0;
}