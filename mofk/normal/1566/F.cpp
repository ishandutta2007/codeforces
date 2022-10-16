#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = 1e18;
int n, m;
int a[200005];
pair<int, int> s[200005];
pair<int, int> t[200005];
vector<int> chunk[200005];
vector<pair<int, int>> item[200005];

bool anzzz(pair<int, int> t) {
    int pos = lower_bound(a + 1, a + n + 1, t.first) - a;
    if (pos <= n && a[pos] <= t.second) return true;
    return false;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int m3, m2;
        cin >> n >> m3;
        m2 = 0;
        a[0] = -inf;
        a[n + 1] = inf;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m3; ++i) {
            pair<int, int> tmp;
            cin >> tmp.first >> tmp.second;
            if (anzzz(tmp)) continue;
            s[++m2] = tmp;
        }
        sort(s + 1, s + m2 + 1);
        m = 0;
        for (int i = 1; i <= m2; ++i) {
            pair<int, int> tmp = s[i];
            if (m && t[m].first == tmp.first) continue;
            while (m && t[m].second >= tmp.second) --m;
            t[++m] = tmp;
        }

        for (int i = 0; i <= n; ++i) chunk[i].clear();
        for (int i = 0; i <= n; ++i) item[i].clear();
        for (int i = 1; i <= m; ++i) {
            int pos = lower_bound(a + 1, a + n + 1, t[i].second) - a - 1;
            chunk[pos].push_back(i);
        }

        for (int i = 0; i <= n; ++i) {
            if (chunk[i].empty()) item[i].push_back({0, 0});
            else {
                for (int j = -1; j < chunk[i].size(); ++j) {
                    int l = (j == -1) ? a[i] : t[chunk[i][j]].first;
                    int r = (j == (int)chunk[i].size() - 1) ? a[i + 1] : t[chunk[i][j+1]].second;
                    item[i].push_back({ l - a[i], a[i + 1] - r });
                }
            }
        }

        int best_f1 = 0, best_f2 = 0, ans = inf;
        for (int i = 0; i <= n; ++i) {
            int g1 = best_f1, g2 = best_f2;
            best_f1 = inf, best_f2 = inf;
            for (auto it: item[i]) {
                    //cout << it.first << ' ' << it.second << endl;
                int f = min(g1 + it.first, g2 + 2 * it.first);
                best_f1 = min(best_f1, f + 2 * it.second);
                best_f2 = min(best_f2, f + it.second);
                if (i == n) ans = f;
            }
        }
        cout << ans << endl;
    }
    return 0;
}