#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, x;
vector < pair < int, int > > f[2];
const int maxN = 2005;
bool used[2][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int h, m;
        cin >> h >> m;
        f[t].emplace_back(make_pair(h, m));
    }
    int best = 0;
    int copx = x;
    for (int i = 0; i < 2; i++) {
        x = copx;
        memset(used, 0, sizeof used);
        multiset < int > s[2];
        int ans = 0;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < f[k].size(); j++) {
                if (f[k][j].first <= x) {
                    s[k].insert(f[k][j].second);
                    used[k][j] = true;
                }
            }
        }
        while (true) {
            int who = (ans + i) % 2;
            if (s[who].empty()) break;
            auto it = (--s[who].end());
            int we = (*it);
            s[who].erase(s[who].find(we));
            x += we;
            for (int k = 0; k < 2; k++) {
                for (int t = 0; t < f[k].size(); t++) {
                    if (used[k][t]) continue;
                    if (f[k][t].first <= x) {
                        used[k][t] = true;
                        s[k].insert(f[k][t].second);
                    }
                }
            }
            ans++;
        }
        best = max(best, ans);
    }
    cout << best;
    return 0;
}