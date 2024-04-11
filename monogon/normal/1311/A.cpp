
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << (a == b ? 0 : (a > b) ^ (a % 2) ^ (b % 2) ? 1 : 2) << endl;
    }
}