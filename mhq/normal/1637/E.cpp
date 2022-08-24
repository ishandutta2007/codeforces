#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int a[maxN];
int val[maxN];
int cnt[maxN];
vector<int> g[maxN];
vector<int> bycnt[maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        map<int,int> mp;
        vector<int> vals;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vals.emplace_back(a[i]);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
        }
        for (int i = 0; i < vals.size(); i++) {
            val[i + 1] = vals[i];
        }
        int T = vals.size();
        for (int i = 1; i <= T; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        vector<int> nonz;
        for (int i = 1; i <= T; i++) {
            if (cnt[i] > 0) nonz.emplace_back(cnt[i]);
        }
        sort(nonz.begin(), nonz.end());
        nonz.erase(unique(nonz.begin(), nonz.end()), nonz.end());
        ll best = -1e18;
        for (int i = 1; i <= n; i++) {
            bycnt[i].clear();
        }
        for (int i = T; i >= 1; i--) {
            if (cnt[i] > 0) bycnt[cnt[i]].emplace_back(i);
        }
        for (int i = 1; i <= T; i++) g[i].clear();
        while (m--) {
            int x, y;
            cin >> x >> y;
            x = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            y = lower_bound(vals.begin(), vals.end(), y) - vals.begin() + 1;
//            cout << x << " " << y << " ? " << endl;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        for (int i = 1; i <= T; i++) g[i].emplace_back(i);
        for (int i = 1; i <= T; i++) {
            if (cnt[i] > 0) {
                for (int id : g[i]) used[id] = true;
                for (int x : nonz) {
                    for (int who : bycnt[x]) {
                        if (!used[who]) {
                            best = max(best, (1LL * cnt[i] + x) * (val[i] + val[who]));
                            break;
                        }
                    }
                }
                for (int id : g[i]) used[id] = false;
            }
        }
        cout << best << '\n';

    }
    return 0;
}