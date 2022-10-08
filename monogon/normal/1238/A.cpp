
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll t, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << (x == y + 1 ? "NO" : "YES") << endl;
    }
}