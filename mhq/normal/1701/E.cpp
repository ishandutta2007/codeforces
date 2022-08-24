#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 5005;
int m;
int pref[maxN][maxN];
int suf[maxN][maxN];
void solve() {
    cin >> n >> m;
    string s, t;
    cin >> t >> s;
    if (n == m) {
        if (s == t) {
            cout << 0 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
        return;
    }
    const int INF = 1e8;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n + 1; j++) {
            pref[i][j] = INF;
            suf[i][j] = -INF;
        }
    }
    pref[0][0] = 0;
    for (int i = 0; i <= n - m; i++) {
        for (int j = i; j < n; j++) {
            if (pref[i][j] > INF / 2) continue;
            int pos = j - i;
            if (i + 1 <= n - m) {
                pref[i + 1][j + 1] = min(pref[i + 1][j + 1], j);
            }
            if (pos < m && s[pos] == t[j]) {
                pref[i][j + 1] = min(pref[i][j + 1], pref[i][j]);
            }
        }
    }
    suf[0][n] = INF;
    for (int i = 0; i <= n - m; i++) {
        for (int j = n; j > 0; j--) {
            if (suf[i][j] < 0) continue;
            int pos = m - (n + 1 - j) + i;
            if (i + 1 <= n - m) {
                suf[i + 1][j - 1] = max(suf[i + 1][j - 1], j - 1);
            }
            if (pos < m && pos >= 0 && s[pos] == t[j - 1]) {
                suf[i][j - 1] = max(suf[i][j - 1], suf[i][j]);
            }
        }
    }
    int best = INF;
    for (int split = 0; split <= n - m; split++) {
        for (int x = 0; x <= n; x++) {
            if (pref[split][x] > INF / 2 || suf[n - m - split][x] < 0) continue;
            if (split == 0) {
                int cost = n - suf[n - m - split][x];
                best = min(best, cost);
            }
            else {
                int cost = max(0, n - suf[n - m - split][x]) + 1 + split + pref[split][x] + 1;
                best = min(best, cost);
            }
        }
    }
    if (best > INF / 2) best = -1;
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}