#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int x, y;
    cin >> x >> y;

    if (x > y)
        cout << x + y << '\n';
    else if (x == y)
        cout << x << '\n';
    else
        cout << ((y / x) * x + y) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}