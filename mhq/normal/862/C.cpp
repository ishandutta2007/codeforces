#include <bits/stdc++.h>
using namespace std;
vector <int> g[100000 + 3];
const int T = 1000000;
int pow ( int x ) {
    int a = 1;
    while ( a <= x) {
        a = a * 2;
    }
    return a;
}
int main() {
    int n, x;
    cin >> n >> x;
    if ( n == 2 && x == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    if ( n % 4 == 1 ) {
        for ( int i = 0; i < n/4; i++) {
            cout << T - 4 *i - 1 << " " << T - 4 * i - 2 << " " << T - 4 * i - 3 << " " << T - 4 * i - 4 << " ";
        }
        cout << x;
        return 0;
    }
    if ( n % 4 == 0) {
        for ( int i = 0; i < n/4 - 1; i++) {
            cout << T - 4 *i - 1 << " " << T - 4 * i - 2 << " " << T - 4 * i - 3 << " " << T - 4 * i - 4 << " ";
        }
        cout << 2 * pow(x) << " " << 2 * pow(x) + pow(x) << " " << pow(x) << " " << x;
        return 0;
    }
    if ( n % 4 == 2) {
        if ( n == 2) {
            cout << 0 << " " << x;
            return 0;
        }
        for ( int i = 0; i < n/4 - 1; i++) {
            cout << T - 4 *i - 1 << " " << T - 4 * i - 2 << " " << T - 4 * i - 3 << " " << T - 4 * i - 4 << " ";
        }
        int r = max(pow(x), 16);
        cout << x << " " << 2 * r  + 1 << " " << 2 * r + 2 << " " << 2 * r + 3 << " " << 2 * r + r << " " << r;
        return 0;
    }
    if ( n % 4 == 3) {
        for ( int i = 0; i < n/4; i++) {
            cout << T - 4 *i - 1 << " " << T - 4 * i - 2 << " " << T - 4 * i - 3 << " " << T - 4 * i - 4 << " ";
        }
        int r = max(pow(x),16);
        cout << 2 * r + r << " " << r + x << " " << 2 * r;
    }

    return 0;
}