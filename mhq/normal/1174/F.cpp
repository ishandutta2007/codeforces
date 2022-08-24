#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
vector < int > g[maxN];
bool used[maxN];
int sz[maxN];
int h[maxN];
int par[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (used[to]) continue;
        if (to == p) continue;
        h[to] = h[v] + 1;
        par[to] = v;
        dfs(to, v);
        sz[v] += sz[to];
    }
}
int asked[maxN];
int askD(int x) {
    if (asked[x] != -1) return asked[x];
    cout << "d " << x << endl;
    int ans;
    cin >> ans;
    asked[x] = ans;
    return ans;
}
bool markCen[maxN];
void go(int x) {
    markCen[x] = true;
    for (int to : g[x]) {
        if (used[to]) continue;
        if (to == par[x]) continue;
        go(to);
    }
}
void mark(int x) {
    memset(markCen, 0, sizeof markCen);
    go(x);
}
int solve(int root) {
    vector < int > cur;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) cur.push_back(i);
    }
    int nn = cur.size();
    h[root] = 0;
    dfs(root, -1);
    if (sz[root] == 1) return root;
    int cen = -1;
    for (int c : cur) {
        int mx = 0;
        for (int to : g[c]) {
            if (used[to]) continue;
            if (par[c] != to) {
                mx = max(mx, sz[to]);
            }
        }
        mx = max(mx, nn - sz[c]);
        if (mx <= nn / 2) {
            cen = c;
            break;
        }
    }
    assert(cen != -1);
    int ans1 = askD(root);
    int ans2 = askD(cen);
    if (ans1 == 0) return root;
    if (ans2 == 0) return cen;
    if (ans1 == ans2 + h[cen] - h[root]) {
        vector < int > cand;
        for (int to : g[cen]) {
            if (!used[to] && par[cen] != to) {
                cand.push_back(to);
            }
        }
        int where;
        if (cand.size() == 1) {
            where = cand[0];
        }
        else {
            cout << "s " << cen << endl;
            cin >> where;
        }
        mark(where);
        for (int i = 1; i <= n; i++) {
            if (!markCen[i]) used[i] = true;
        }
        asked[where] = asked[cen] - 1;
        return solve(where);
    }
    else {
        mark(cen);
        for (int i = 1; i <= n; i++) {
            if (markCen[i]) used[i] = true;
        }
        return solve(root);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    memset(asked, -1, sizeof asked);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int f = solve(1);
    cout << "! ";
    cout << f << endl;
    return 0;
}