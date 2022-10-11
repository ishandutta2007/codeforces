#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2) for (auto &x : s) x ^= '0' ^ '1';

    int take = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (take == k) break;
        if (s[i] == '0') {
            ans[i]++;
            take++;
            s[i] ^= '0' ^ '1';
        }
    }

    if ((k - take) % 2) {
        take++;
        ans.back()++;
        s.back() ^= '0' ^ '1';
    }
    ans[0] += k - take;
    cout << s << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}