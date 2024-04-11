#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 105;
int cnt[maxN][maxN];
int val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            cnt[i][x]++;
        }
    }
    vector<vector<int>> ans;

    //make distinct
    while (true) {
        vector<pair<int, int>> dif;
        for (int i = 1; i <= n; i++) {
            pair<int, int> mx = make_pair(0, 0);
            for (int j = 1; j <= n; j++) {
                mx = max(mx, {cnt[i][j], j});
            }
            if (mx.first > 1) {
                dif.emplace_back(i, mx.second);
            }
        }
        if (dif.empty()) break;
        for (int z = 0; z < dif.size(); z++) {
            int from = dif[z].first;
            int to = dif[(z + 1) % dif.size()].first;
            if (from >= to) {
                to += n;
            }
            to--;
            for (int x = from; x <= to; x++) {
                val[(x > n ? x - n : x)] = dif[z].second;
            }
        }
        vector<int> t;
        for (int i = 1; i <= n; i++) {
            t.emplace_back(val[i]);
            cnt[i][val[i]]--;
            cnt[i % n + 1][val[i]]++;
        }
        ans.emplace_back(t);
    }

    while (true) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (cnt[i][i] != n) ok = false;
        }
        if (ok) break;
        vector<int> who;
        for (int i = 1; i <= n; i++) {
            for (int j = (i + n - 2) % n + 1; ; j = (j + n - 2) % n + 1) {
                if (cnt[i][j]) {
                    who.emplace_back(j);
                    break;
                }
            }
        }
        ans.emplace_back(who);
        for (int z = 0; z < n; z++) {
            cnt[z + 1][who[z]]--;
            cnt[(z + 1) % n + 1][who[z]]++;
        }
    }
    cout << ans.size() << '\n';
    for (auto& it : ans) {
        for (auto& pit : it) cout << pit << " ";
        cout << '\n';
    }
    return 0;
}