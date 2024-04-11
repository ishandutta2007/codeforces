#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> good(n, true);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        good[b - 1] = false;
    }

    int c = 0;
    while (!good[c])
        c++;

    for (int i = 0; i < n; i++)
        if (i != c)
            cout << i + 1 << ' ' << c + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}