#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2e5 + 10;
int a[maxN];
int l[maxN], r[maxN];
int mx[maxN];
int nxt[maxN];
vector<int> all[maxN];
void solve() {
    cin >> n >> m;
    vector<int> gg;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        gg.emplace_back(a[i]);
        all[i].clear();
    }
    sort(gg.begin(), gg.end());
    gg.erase(unique(gg.begin(), gg.end()), gg.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(gg.begin(), gg.end(), a[i]) - gg.begin() + 1;
        all[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        mx[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        mx[l[i]] = max(mx[l[i]], r[i]);
    }
    for (int i = 2; i <= n; i++) {
        mx[i] = max(mx[i], mx[i - 1]);
    }
    int at_most_l = n + 1;
    int at_least_r = 1;
    for (int i = 1; i <= n; i++) {
        nxt[i] = -1;
    }
    set<int> min_r;
    for (int i = 1; i <= n; i++) {
        for (int ptr = 0; ptr < all[i].size(); ptr++) {
            int x = all[i][ptr];
            int t = upper_bound(all[i].begin(), all[i].end(), mx[x]) - all[i].begin();
            if (t <= ptr) continue;
            t -= 1;
            if (t <= ptr) continue;
            at_most_l = min(at_most_l, all[i][ptr + 1]);
            at_least_r = max(at_least_r, all[i][t - 1]);
            nxt[x] = all[i][t];
            min_r.insert(x);
        }
    }
    if (at_most_l == n + 1) {
        cout << 0 << '\n';
    }
    else {
        int best = n;
        for (int i = 1; i <= at_most_l; i++) {
            best = min(best, max(*(--min_r.end()), at_least_r) - i + 1);
            if (nxt[i] != -1) {
                min_r.erase(i);
                min_r.insert(nxt[i]);
            }
        }
        cout << best << '\n';
    }
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