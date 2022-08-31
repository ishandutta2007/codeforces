#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
ll a[maxN], b[maxN];
int n, m;
void solve() {
    cin >> n >> m;
    vector < pair < int, int > > all;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        all.emplace_back(b[i], a[i]);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    vector < int > aa;
    for (int i = 1; i <= m; i++) {
        b[i] = all[i - 1].first;
        a[i] = all[i - 1].second;
        aa.emplace_back(a[i]);
    }
    sort(aa.begin(), aa.end());
    reverse(aa.begin(), aa.end());
    ll best = 0;
    if (n <= m) {
        for (int i = 0; i < n; i++) {
            best += aa[i];
        }
    }
    reverse(aa.begin(), aa.end());
    vector < ll > suf(m + 1);
    suf[m] = 0;
    for (int i = m - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + aa[i];
    }
    if (n >= 2) {
        for (int i = 1; i <= m; i++) {
            int where = lower_bound(aa.begin(), aa.end(), b[i]) - aa.begin();
            // where .. m - 1
            where = max(where, m - n + 1);
            if (where < m && a[i] >= aa[where]) {
                best = max(best, n * b[i] + suf[where] - (m - where) * b[i]);
            }
            else {
                best = max(best, n * b[i] + suf[where] + a[i] - (m - where + 1) * b[i]);
            }
        }
    }
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
      solve();
    }
    return 0;
}