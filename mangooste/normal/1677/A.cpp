#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) cin >> x, x--;

    vector pref(n + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        for (int j = p[i]; j < n; j++) {
            pref[i + 1][j]++;
        }
    }

    ll ans = 0;
    for (int b = 0; b < n; b++) {
        for (int c = b + 1; c < n; c++) {
            ans += pref[b][p[c]] * (pref[n][p[b]] - pref[c + 1][p[b]]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}