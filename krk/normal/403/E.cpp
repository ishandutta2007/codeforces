#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxt = 2;
const int Maxn = 200005;
const string nam[Maxt] = {"Blue", "Red"};

bool tk[Maxt][Maxn];

struct segtree {
    int t, n;
    vector <vector <int> > st;
    segtree(int gt = 0, int gn = 0) {
        t = gt;
        n = gn;
        int m = 1;
        while (m <= 4 * n) m *= 2;
        st.resize(m);
    }
    void Add(int v, int l, int r, int a, int b, int ind) {
        if (l == a && r == b) st[v].push_back(ind);
        else {
            int m = l + r >> 1;
            if (a <= m) Add(2 * v, l, m, a, min(m, b), ind);
            if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, ind);
        }
    }
    void Add(int l, int r, int ind) { Add(1, 1, n, l, r, ind); }
    void Get(int v, int l, int r, int x, vector <int> &res) {
        while (!st[v].empty()) {
            int ind = st[v].back(); st[v].pop_back();
            if (!tk[t][ind]) {
                tk[t][ind] = true;
                res.push_back(ind);
            }
        }
        if (l < r) {
            int m = l + r >> 1;
            if (x <= m) Get(2 * v, l, m, x, res);
            else Get(2 * v + 1, m + 1, r, x, res);
        }
    }
    void Get(int x, vector <int> &res) { Get(1, 1, n, x, res); }
};

int n;
int A[Maxt][Maxn], B[Maxt][Maxn];
vector <ii> neigh[Maxt][Maxn];
segtree st[Maxt][Maxn];
vector <int> simple[Maxt][Maxn];
int head[Maxt][Maxn], id[Maxt][Maxn];
int P[Maxt][Maxn], L[Maxt][Maxn], cnt[Maxt][Maxn];
int tonode[Maxt][Maxn];

void Count(int t, int v)
{
    cnt[t][v] = 1;
    for (int i = 0; i < neigh[t][v].size(); i++) {
        int u = neigh[t][v][i].first;
        if (u == P[t][v]) continue;
        int ind = neigh[t][v][i].second;
        tonode[t][ind] = u;
        P[t][u] = v; L[t][u] = L[t][v] + 1;
        Count(t, u);
        cnt[t][v] += cnt[t][u];
    }
}

void Build(int t, int v)
{
    bool was = false;
    for (int i = 0; i < neigh[t][v].size(); i++) {
        int u = neigh[t][v][i].first;
        if (u == P[t][v]) continue;
        if (cnt[t][u] > cnt[t][v] / 2) {
            was = true;
            head[t][u] = head[t][v];
            id[t][u] = id[t][v] + 1;
        } else {
            head[t][u] = u;
            id[t][u] = 0;
        }
        Build(t, u);
    }
    if (!was) st[t][head[t][v]] = segtree(1 - t, id[t][v]);
}

void Add(int t, int a, int b, int ind)
{
    while (head[t][a] != head[t][b]) {
        if (L[t][head[t][a]] < L[t][head[t][b]])
            swap(a, b);
        if (head[t][a] != a) {
            st[t][head[t][a]].Add(1, id[t][a], ind);
            a = head[t][a];
        }
        simple[t][a].push_back(ind);
        a = P[t][a];
    }
    if (a != b) {
        if (L[t][a] < L[t][b]) swap(a, b);
        st[t][head[t][a]].Add(id[t][b] + 1, id[t][a], ind);
    }
}

void Solve(int t, int v, vector <int> &res)
{
    int nd = 1 - t;
    if (id[t][v]) st[t][head[t][v]].Get(id[t][v], res);
    else while (!simple[t][v].empty()) {
            int ind = simple[t][v].back(); simple[t][v].pop_back();
            if (!tk[nd][ind]) {
                tk[nd][ind] = true;
                res.push_back(ind);
            }
        }
}

int main()
{
    scanf("%d", &n);
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i < n; i++) {
            scanf("%d", &A[t][i]); B[t][i] = i + 1;
            neigh[t][A[t][i]].push_back(ii(B[t][i], i));
            neigh[t][B[t][i]].push_back(ii(A[t][i], i));
        }
        Count(t, 1);
        head[t][1] = 1; id[t][1] = 0;
        Build(t, 1);
    }
    for (int t = 0; t < 2; t++)
        for (int i = 1; i < n; i++)
            Add(1 - t, A[t][i], B[t][i], i);
    int ind; scanf("%d", &ind);
    vector <int> cur = {ind}, nxt;
    int curt = 0;
    tk[curt][ind] = true;
    while (!cur.empty()) {
        printf("%s\n", nam[curt].c_str());
        sort(cur.begin(), cur.end());
        for (int i = 0; i < cur.size(); i++)
            printf("%d%c", cur[i], i + 1 < cur.size()? ' ': '\n');
        for (int i = 0; i < cur.size(); i++)
            Solve(curt, tonode[curt][cur[i]], nxt);
        cur = nxt; nxt.clear();
        curt = 1 - curt;
    }
    return 0;
}