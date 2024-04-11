#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

struct segtree {
    int n;
    vector <int> st;
    vector <int> fl;
    segtree() {}
    void downOn(int v, int f) {
        st[v] += f;
        fl[v] += f;
    }
    void Down(int v) {
        if (fl[v]) {
            downOn(2 * v, fl[v]);
            downOn(2 * v + 1, fl[v]);
            fl[v] = 0;
        }
    }
    void Union(int v) {
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
    void Create(int v, int l, int r, const vector <int> &seq)
    {
        if (l == r) st[v] = seq[l];
        else {
            int m = l + r >> 1;
            Create(2 * v, l, m, seq);
            Create(2 * v + 1, m + 1, r, seq);
            Union(v);
        }
    }
    void Add(int v, int l, int r, int a, int b, int val) {
        if (l == a && r == b) downOn(v, val);
        else {
            Down(v);
            int m = l + r >> 1;
            if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
            if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
            Union(v);
        }
    }
    void addRange(int l, int r, int val) {
        if (l <= r) Add(1, 0, n - 1, l, r, val);
        else {
            Add(1, 0, n - 1, l, n - 1, val);
            Add(1, 0, n - 1, 0, r, val);
        }
    }
    int Get(int v, int l, int r, int a, int b) {
        if (l == a && r == b) return st[v];
        else {
            Down(v);
            int res = 0;
            int m = l + r >> 1;
            if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
            if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
            return res;
        }
    }
    segtree(const vector <int> &seq) {
        n = seq.size();
        int m = 1;
        while (m <= 4 * n) m *= 2;
        st.resize(m);
        fl.resize(m, 0);
        Create(1, 0, n - 1, seq);
    }
    void Move(int ind) {
        if (n == 1) return;
        int sid = n / 2;
        addRange((ind - sid + 1 + n) % n, ind, 1);
        addRange((ind + 1) % n, (ind + sid) % n, -1);
    }
    int Get(int ind) {
        int res = 0;
        if (ind > 0) res = max(res, Get(1, 0, n - 1, 0, ind - 1));
        if (ind + 1 < n) res = max(res, Get(1, 0, n - 1, ind + 1, n - 1));
        return res;
    }
};

int n, m;
vector <ii> neigh[Maxn];
int cur, tim[Maxn], low[Maxn];
bool bridge[2 * Maxn];
int cycs, cycle[Maxn], cid[Maxn];
vector <int> C[Maxn];
int bot[Maxn][2], ret[Maxn];
segtree S[Maxn];
vector <int> seq[Maxn];
int res[Maxn];

void findBridges(int v, int p)
{
    cur++;
    tim[v] = low[v] = cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p) continue;
        if (tim[u]) low[v] = min(low[v], tim[u]);
        else {
            findBridges(u, v);
            low[v] = min(low[v], low[u]);
            if (tim[v] < low[u])
                bridge[neigh[v][i].second] = true;
        }
    }
}

void findCycles(int v)
{
    if (cycle[v]) return;
    cycle[v] = cycs;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        int ind = neigh[v][i].second;
        if (bridge[ind]) continue;
        findCycles(u);
    }
    cid[v] = C[cycs].size();
    C[cycs].push_back(v);
}

void addBot(int v, int val)
{
    if (val > bot[v][0]) bot[v][1] = bot[v][0], bot[v][0] = val;
    else if (val > bot[v][1]) bot[v][1] = val;
}

int getBot(int v, int val)
{
    return val == bot[v][0]? bot[v][1]: bot[v][0];
}

int Fix(int add, int clen)
{
    add %= clen;
    if (add < 0) add += clen;
    if (clen - add < add) add = clen - add;
    return add;
}

int Traverse1(int v, int p)
{
    int col = cycle[v];
    int res = 0;
    for (int i = 0; i < C[col].size(); i++) {
        int u = C[col][i];
        for (int j = 0; j < neigh[u].size(); j++) {
            int u2 = neigh[u][j].first;
            if (cycle[u] == cycle[u2] || u2 == p) continue;
            addBot(u, Traverse1(u2, u) + 1);
        }
        res = max(res, bot[u][0] + Fix(cid[v] - i, C[col].size()));
    }
    ret[v] = res;
    return res;
}

void Traverse2(int v, int p, int tp)
{
    int col = cycle[v];
    for (int i = 0; i < C[col].size(); i++) {
        int u = C[col][i];
        seq[v].push_back(bot[u][0] + Fix(i, C[col].size()));
    }
    S[v] = segtree(seq[v]);
    for (int i = 0; i < C[col].size(); i++) {
        int u = C[col][i];
        int ntop = max(S[v].Get(i), tp + Fix(cid[v] - i, C[col].size()));
        res[u] = max(ntop, bot[u][0]);
        for (int j = 0; j < neigh[u].size(); j++) {
            int u2 = neigh[u][j].first;
            if (cycle[u] == cycle[u2] || u2 == p) continue;
            Traverse2(u2, u, max(ntop, getBot(u, ret[u2] + 1)) + 1);
        }
        S[v].Move(i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(ii(b, i));
        neigh[b].push_back(ii(a, i));
    }
    findBridges(1, 0);
    for (int i = 1; i <= n; i++) if (!cycle[i]) {
        cycs++;
        findCycles(i);
    }
    Traverse1(1, 0);
    Traverse2(1, 0, 0);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}