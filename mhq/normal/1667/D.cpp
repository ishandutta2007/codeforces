#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
bool dp[maxN][2];
int n;
int deg[maxN];
vector<int> g[maxN];
vector<int> sons_ord[maxN][2];
map<pair<int,int>, int> mp;
void dfs(int v, int p) {
    int d = 0;
    vector<int> can_zero, can_one, can_both;
    dp[v][0] = dp[v][1] = true;
    for (int& to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        d++;
        if (!dp[to][0] && !dp[to][1]) {
            dp[v][0] = dp[v][1] = false;
            break;
        }
        if (dp[to][0] && dp[to][1]) {
            can_both.emplace_back(to);
        }
        else if (dp[to][0]) {
            can_zero.emplace_back(to);
        }
        else {
            can_one.emplace_back(to);
        }
    }
    if (!dp[v][0]) return;
    int need_0 = 0;
    int need_1 = 0;
    for (int i = 1; i <= (d + (v != 1)); i++) {
        if (i % 2 == 0) need_0++;
        else need_1++;
    }
//    if (v == 1) {
//        cout << need_0 << " " << need_1 << endl;
//    }
    for (int x = 0; x < 2; x++) {
        int c0 = need_0;
        int c1 = need_1;
        if (v != 1) {
            if (x == 0) {
                c0--;
            }
            else {
                c1--;
            }
        }
        if ((int)can_zero.size() + (int)can_both.size() < c0) {
            dp[v][x] = false;
            continue;
        }
        if ((int)can_one.size() + (int)can_both.size() < c1) {
            dp[v][x] = false;
            continue;
        }
        bool flag = (v != 1);
        auto t0 = can_zero;
        auto t1 = can_one;
        auto t01 = can_both;
//        cout << v << " ??? " << " " << t0.size() << " " << t1.size() << " " << t01.size() << " " << c0 << " " << c1 << endl;
        for (int i = (d + (v != 1)); i >= 1; i--) {
//            cout << " NEED " << (i % 2) << " ??? " << " " << flag << endl;
            if (flag && ((i % 2) == x)) {
                flag = false;
                sons_ord[v][x].emplace_back(p);
            }
            else {
                if (i % 2 == 0) {
                    if (!t0.empty()) {
                        sons_ord[v][x].emplace_back(t0.back());
                        t0.pop_back();
                    }
                    else {
                        sons_ord[v][x].emplace_back(t01.back());
                        t01.pop_back();
                    }
                }
                else {
                    if (!t1.empty()) {
                        sons_ord[v][x].emplace_back(t1.back());
                        t1.pop_back();
                    }
                    else {
                        sons_ord[v][x].emplace_back(t01.back());
                        t01.pop_back();
                    }
                }
            }
        }
    }
}
vector<pair<int,int>> ans;
void recover(int v, int p, int fl) {
    int cur = g[v].size() % 2;
    for (int t : sons_ord[v][fl]) {
        if (t == p) {
            ans.emplace_back(v, p);
        }
        else {
            recover(t, v, cur);
        }
        cur ^= 1;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dp[i][0] = dp[i][1] = false;
        deg[i] = 0;
        sons_ord[i][0].clear();
        sons_ord[i][1].clear();
    }
    mp.clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u] ^= 1;
        deg[v] ^= 1;
//        mp[minmax(u, v)] = i;
    }
    dfs(1, -1);
    if (!dp[1][0]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        ans.clear();
        recover(1, -1, 0);
        for (auto& c : ans) {
            cout << c.first << " " <<  c.second << '\n';
        }
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