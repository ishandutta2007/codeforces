#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100000 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((a % 2) != (b % 2)) {
            cout << "-1\n";
            continue;
        }
        if (a == 0 && b == 0) {
            cout << "0\n";
            continue;
        }
        if (a == b) {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
}