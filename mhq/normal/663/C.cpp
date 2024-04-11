#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
vector < pair < int, int > > g[maxN];
int n, m;
int used[maxN];
int getColor(char z) {
    if (z == 'B') return 0;
    else return 1;
}
vector < int > ans_for_comp[2];
int curcolor[maxN];
bool dfs(int v, int color, int f, int p = -1) {
//    cout << v << " " << p << endl;
    bool ok = true;
    used[v] = f;
    for (auto t : g[v]) {
        int to = t.first;
        int clr = t.second;
        if (to == p) {
            if (((clr ^ color) ^ curcolor[to]) == 1) {
                curcolor[v] = 1;
                ans_for_comp[f].push_back(v);
            }
            else curcolor[v] = 0;
        }
    }
    for (auto t : g[v]) {
        int to = t.first;
        if (used[to] != f) ok &= dfs(to, color, f, v);
        int clr = t.second;
        if ((clr ^ color) != (curcolor[to] ^ curcolor[v])) ok = false;
    }
    return ok;
}
vector < int > ans;
vector < int > curans;
bool ok[2];
bool go(int v, int color) {
    for (int i = 0; i < 2; i++) {
        ans_for_comp[i].clear();
        curcolor[v] = i;
        ok[i] = dfs(v, color, i);
        if (i == 1) ans_for_comp[i].push_back(v);
    }
    int mn = n + 10;
    for (int i = 0; i < 2; i++) {
        if (ok[i]) mn = min(mn, (int)ans_for_comp[i].size());
    }
    for (int i = 0; i < 2; i++) {
        if (ok[i] && (mn == ans_for_comp[i].size())) {
            for (int j : ans_for_comp[i]) curans.push_back(j);
            break;
        }
    }
    return (mn < (n + 10));
}
bool solve(int color) {
    memset(used, -1, sizeof used);
    curans.clear();
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (used[i] == -1) {
            ok &= go(i, color);
        }
    }
    return ok;
}
int main() {
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, getColor(z)));
        g[y].push_back(make_pair(x, getColor(z)));
    }
    ans.resize(n + 10);
    for (int color = 0; color < 2; color++) {
        if (solve(color)) {
            if (curans.size() < ans.size()) ans = curans;
        }
    }
    if (ans.size() > n) {
        cout << -1;
    }
    else {
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << " ";
    }
    return 0;
}