#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (2e5 + 10) * 35;
const int maxK = 2e5 + 10;
int a[maxK];
vector<int> g[maxN];
int x = -1;
int y = -1;
int D = -1e9;
pair<int,int> dp[maxN];
void dfs(int v) {
    for (auto& it : g[v]) {
        dfs(it);
        dp[it].first++;
//        cout << dp[v].first << " gg " << dp[it].first << endl;
        if (D < dp[it].first + dp[v].first) {
            D = dp[it].first + dp[v].first;
            x = dp[it].second;
            y = dp[v].second;
        }
        dp[v] = max(dp[v], dp[it]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    int st = n + 1;
    vector<int> verts;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int c = a[i];
        verts.emplace_back(a[i]);
        for (int t = 30; t >= 0; t--) {
            if (!c) continue;
            if ((1 << t) >= c && (t == 0 || c > (1 << (t - 1)))) {
                c = (1 << t) - c;
                verts.emplace_back(c);
            }
        }
    }
    sort(verts.begin(), verts.end());
    verts.erase(unique(verts.begin(), verts.end()), verts.end());
    assert((int)verts.size() < maxN);
    for (int i = 0; i < verts.size(); i++) {
        dp[i] = {-1e9, -1};
    }
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(verts.begin(), verts.end(), a[i]) - verts.begin();
        dp[pos] = {0, i};
        int c = a[i];
        for (int t = 30; t >= 0; t--) {
            if (!c) continue;
            if ((1 << t) >= c && (t == 0 || c > (1 << (t - 1)))) {
                c = (1 << t) - c;
                int new_pos = lower_bound(verts.begin(), verts.end(), c) - verts.begin();
                g[new_pos].emplace_back(pos);
                pos = new_pos;
            }
        }
    }
    for (int i = 0; i < verts.size(); i++) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    dfs(0);
    cout << x << " " << y << " " << D << '\n';
    return 0;
}