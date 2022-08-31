#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
vector<pair<int,int>> g[maxN];
bool used[maxN];
int n, m;
int clr[maxN];
int cnt[2] = {0, 0};
bool ALL_OK = true;
void dfs(int v) {
    cnt[clr[v]]++;
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to.first]) {
            clr[to.first] = clr[v] ^ to.second;
            dfs(to.first);
        }
        else {
            if (clr[to.first] != (clr[v] ^ to.second)) {
                ALL_OK = false;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        used[i] = false;
        g[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        if (s == "crewmate") {
            g[x].emplace_back(y, 0);
            g[y].emplace_back(x, 0);
        }
        else {
            g[x].emplace_back(y, 1);
            g[y].emplace_back(x, 1);
        }
    }
    int F = 0;
    ALL_OK = true;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            clr[i] = 0;
            cnt[0] = cnt[1] = 0;
            dfs(i);
            F += max(cnt[0], cnt[1]);
        }
    }
    if (ALL_OK) {
        cout << F << '\n';
    }
    else {
        cout << -1 << '\n';
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