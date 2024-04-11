#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e6 + 10;
int a[maxN];
vector < int > by[maxN];

int pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("gem.in", "r", stdin);
//    freopen("gem.out", "w", stdout);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        vector < int > gg;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            gg.emplace_back(a[i]);
        }
        sort(gg.begin(), gg.end());
        gg.erase(unique(gg.begin(), gg.end()), gg.end());
        for (int i = 1; i <= n + 5; i++) {
            by[i].clear();
            pref[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(gg.begin(), gg.end(), a[i]) - gg.begin() + 1;
        }

        vector<int> vals;
        for (int i = 1; i <= n; i++) {
            vals.emplace_back(a[i]);
            by[a[i]].emplace_back(i);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int best = n;
        int r = 0;
        pref[0] = 0;
        for (int i = 0; i < vals.size(); i++) pref[i + 1] = pref[i] + by[vals[i]].size();
        for (int i = 0; i < vals.size(); i++) {
            best = min(best, n - (int) by[vals[i]].size());
            r = max(r, i);
            while (r + 1 < vals.size() && by[vals[r + 1]][0] >= by[vals[r]].back()) r++;
            int tot = pref[r + 1] - pref[i];
            if (i > 0) {
                int c = lower_bound(by[vals[i - 1]].begin(), by[vals[i - 1]].end(), by[vals[i]][0]) -
                        by[vals[i - 1]].begin();
                tot += c;
            }
            if (r + 1 < vals.size()) {
                int c = lower_bound(by[vals[r + 1]].begin(), by[vals[r + 1]].end(), by[vals[r]].back()) -
                        by[vals[r + 1]].begin();
                tot += by[vals[r + 1]].size() - c;
            }
            best = min(best, n - tot);
            //take [i .. r]
        }
        for (int i = 0; i + 1 < vals.size(); i++) {
            for (int sz_pref = 1; sz_pref <= by[vals[i]].size(); sz_pref++) {
                int c = lower_bound(by[vals[i + 1]].begin(), by[vals[i + 1]].end(), by[vals[i]][sz_pref - 1]) -
                        by[vals[i + 1]].begin();
                int tot = (int) by[vals[i + 1]].size() - c + sz_pref;
                best = min(best, n - tot);
            }
        }
        cout << best << '\n';
    }
    return 0;
}