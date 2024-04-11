#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n, k;
int m;
vector < int > g[maxN];
bool used[maxN];
int h[maxN];
vector < int > c[2];
int clr[maxN];
int prv[maxN];
void dfs(int v, int p) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to] && to != p) {
            int cv = v;
            vector < int > cyc;
            while (cv != to) {
                cyc.emplace_back(cv);
                cv = prv[cv];
            }
            cyc.emplace_back(to);
            cout << 2 << "\n" << cyc.size() << '\n';
            for (int vv : cyc) cout << vv << " ";
            exit(0);
        }
        else if (!used[to]) {
            h[to] = h[v] ^ 1;
            prv[to] = v;
            dfs(to, v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    n = k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > n || b > n) continue;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
    vector < int > c[2];
    for (int i = 1; i <= n; i++) {
        c[h[i]].emplace_back(i);
    }
    if (c[0].size() < c[1].size()) swap(c[0], c[1]);
    c[0].resize((k + 1) / 2);
    cout << 1 << '\n';
    for (int v : c[0]) cout << v << " ";
    return 0;
}