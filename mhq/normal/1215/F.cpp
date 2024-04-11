#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, p, M, m;
const int maxN = 2 * (int)(2 * 4e5 + 4e5 + 10);
vector < int > g[maxN];
vector < int > gr[maxN];
bool used[maxN];
int cmp[maxN];
vector < int > ord;

void add_edge(int x, int y) {
    g[x].push_back(y);
    gr[y].push_back(x);
}

void add(int x, int y) {
    add_edge(x ^ 1, y);
    add_edge(y ^ 1, x);
}

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) dfs1(to);
    }
    ord.push_back(v);
}

void dfs2(int v, int num) {
    cmp[v] = num;
    for (int to : gr[v]) {
        if (cmp[to] == -1) dfs2(to, num);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> p >> M >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        add(2 * x, 2 * y);
    }
    // p_1 = f >= 1
    // p_2 = f >= 2
    // ..
    for (int i = 1; i + 1 <= M; i++) {
        add(2 * (p + i - 1), 2 * (p + i) + 1);
    }
    // p_1 always true
    add(2 * p, 2 * p);
    //
    for (int i = 1; i + 1 <= M; i++) {
        add(2 * (p + M + i), 2 * (p + M + i - 1) + 1);
    }
    // q_M always true
    add(2 * (p + M + M - 1), 2 * (p + M + M - 1));
    // p_i || q_(i - 1)
    for (int i = 2; i <= M; i++) {
        add(2 * (p + i - 1), 2 * (p + M + i - 1 - 1));
        add(2 * (p + i - 1) + 1, 2 * (p + M + i - 1 - 1) + 1);
    }
    for (int i = 0; i < p; i++) {
        int l, r;
        cin >> l >> r;
        if (r + 1 <= M) {
            add(2 * (p + r + 1 - 1) + 1, 2 * i + 1);
        }
        if (l > 1) {
            add(2 * (p + M + l - 1 - 1) + 1, 2 * i + 1);
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        add(2 * u + 1, 2 * v + 1);
    }
    int TOTAL = 2 * (p + M + M);
    for (int i = 0; i < TOTAL; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(ord.begin(), ord.end());
    memset(cmp, -1, sizeof cmp);
    int sz = 0;
    for (int v : ord) {
        if (cmp[v] == -1) {
            cmp[v] = sz;
            dfs2(v, sz);
            sz++;
        }
    }
    for (int i = 0; i < TOTAL; i++) {
        if (cmp[i] == cmp[i ^ 1]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    int val_f = M;
    assert(cmp[2 * p] > cmp[2 * p + 1]);
    for (int i = 1; i <= M; i++) {
        int a = 2 * (p + i - 1);
        if (cmp[a] < cmp[a ^ 1]) {
            val_f = i - 1;
            break;
        }
    }

    vector < int > ans;
    for (int i = 0; i < p; i++) {
        if (cmp[2 * i] > cmp[2 * i + 1]) ans.push_back(i);
    }
    cout << ans.size() << " " << val_f << '\n';
    for (int v : ans) cout << v + 1 << " ";
    return 0;
}