#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    ll value;
    cin >> value;

    ll x = value, p2 = 2;
    while (x % 2 == 0) {
        x /= 2;
        p2 *= 2;
    }

    if (p2 <= 1e9 + 228 && p2 * (p2 + 1) / 2 <= value) {
        cout << p2 << '\n';
    } else if (x == 1) {
        cout << "-1\n";
    } else {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}