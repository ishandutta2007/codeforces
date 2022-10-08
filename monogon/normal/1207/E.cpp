
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll num1, num2;

int main() {
    ios::sync_with_stdio(false);
    cout << "?";
    for(int i = 0; i < 100; i++) {
        cout << " " << i;
    }
    cout << endl << flush;
    cin >> num1;
    cout << "?";
    for(int i = 1; i <= 100; i++) {
        cout << " " << (i << 7);
    }
    cout << endl << flush;
    cin >> num2;
    cout << "! " << ((num1 >> 7) << 7) + (num2 % (1 << 7)) << endl;
}