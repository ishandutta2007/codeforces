
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll r, g, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> r >> g >> b;
        cout << (r <= g + b + 1 && g <= r + b + 1 && b <= r + g + 1 ? "Yes" : "No") << endl;
    }
}