#include <bits/stdc++.h>

using namespace std;

const int N = (int)6e5;

int n;
long long x[N];
long long len[N];
long long cost[N][20];
int par[N][20];
vector<int> g[N];
vector<long long> w[N];
int last;

void dfs(int v, int p, long long parCost) {
    cost[v][0] = parCost;
    par[v][0] = p;
    for (int i = 1; i < 20; i++) {
        cost[v][i] = cost[v][i - 1] + cost[par[v][i - 1]][i - 1];
        par[v][i] = par[par[v][i - 1]][i - 1];
    }
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i], v, w[v][i]);
}

int calc(int a, int b) {
    long long res = 0;
    for (int i = 19; i >= 0; i--)
        if (x[par[a][i]] <= x[b]) {
            res += cost[a][i];
            a = par[a][i];
        }
    return res;
}

typedef pair<long long, int> pll;
pll tree[2 * N];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = pll(x[l] + len[l], l);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

pll getMax(int i, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
        return tree[i];
    int m = (tl + tr) / 2;
    pll pl;
    pll pr;
    if (l <= m)
        pl = getMax(2 * i + 1, tl, m, l, min(m, r));
    if (r > m)
        pr = getMax(2 * i + 2, m + 1, tr, max(l, m + 1), r);
    return max(pl, pr);
}

void add(int i) {
    int to = upper_bound(x, x + n, x[i] + len[i]) - x;
    to--;
    //cerr << i << " " << to << endl;
    pll mx = getMax(0, 0, n - 1, i, to);
    //cerr << mx.first << " " << mx.second << endl;
    if (mx.second != i) {
        g[mx.second].push_back(i);
        w[mx.second].push_back(0);
    } else {
        if (to == n - 1) {
            g[to].push_back(i);
            w[to].push_back(0);
        } else {
            int v = last++;
            x[v] = mx.first;
            g[v].push_back(i);
            w[v].push_back(0);
            g[to + 1].push_back(v);
            w[to + 1].push_back(x[to + 1] - x[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> len[i];
    last = n;
    build(0, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
        add(i);
    dfs(n - 1, n - 1, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << calc(a, b) << "\n";
    }
    return 0;
}