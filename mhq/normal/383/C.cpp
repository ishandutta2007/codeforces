#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int n, m;
int a[maxN];
vector < int > g[maxN];
int open[maxN], close[maxN];
int timer = 0;
int t[8 * maxN];
bool odd[maxN];
void dfs(int v, int p = -1) {
    timer++;
    open[v] = timer;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        odd[to] = !odd[v];
        dfs(to, v);
    }
    close[v] = timer;
}
void add(int v, int tl, int tr, int l, int r, int val) {
    if (l == tl && r == tr) {
        t[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) add(v + v, tl, tm, l, r, val);
    else if (l > tm) add(v + v + 1, tm + 1, tr, l, r, val);
    else {
        add(v + v, tl, tm, l, tm, val);
        add(v + v + 1, tm + 1, tr, tm + 1, r, val);
    }
}
int get(int v, int tl, int tr, int pos) {
    if (tl == tr) return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm) return t[v] + get(v + v, tl, tm, pos);
    else return t[v] + get(v + v + 1, tm + 1, tr, pos);
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, val;
            cin >> x >> val;
            if (!odd[x]) {
                add(1, 1, 2 * n, open[x], close[x], val);
                add(1, 1, 2 * n, n + open[x], n + close[x], -val);
            }
            else {
                add(1, 1, 2 * n, n + open[x], n + close[x], val);
                add(1, 1, 2 * n, open[x], close[x], -val);
            }
        }
        else {
            int x;
            cin >> x;
            if (!odd[x]) cout << a[x] + get(1, 1, 2 * n, open[x]) << '\n';
            else cout << a[x] + get(1, 1, 2 * n, n + open[x]) << '\n';
        }
    }
	return 0;
}