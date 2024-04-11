#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <int, ll> ill; 

const int Maxn = 200005;

struct node {
    ill val[2];
    bool fl;
};

ill Add(const ill &a, const ill &b)
{
    return ill(a.first + b.first, a.second + b.second);
}

ill Sub(const ill &a, const ill &b)
{
    return ill(a.first - b.first, a.second - b.second);
}

struct segtree {
    vector <node> st;
    int n;
    segtree() {}
    void downOn(int v) {
        swap(st[v].val[0], st[v].val[1]);
        st[v].fl = !st[v].fl;
    }
    void Down(int v) {
        if (st[v].fl) {
            downOn(2 * v);
            downOn(2 * v + 1);
            st[v].fl = false;
        }
    }
    void Union(int v) {
        int lc = 2 * v, rc = 2 * v + 1;
        for (int i = 0; i < 2; i++)
            st[v].val[i] = Add(st[lc].val[i], st[rc].val[i]);
    }
    void Create(int v, int l, int r, const vector <int> &dist) {
        st[v].fl = false;
        if (l == r) {
            st[v].val[0] = ill(0, 0ll);
            st[v].val[1] = ill(1, ll(dist[l]));
        } else {
            int m = l + r >> 1;
            Create(2 * v, l, m, dist);
            Create(2 * v + 1, m + 1, r, dist);
            Union(v);
        }
    }
    void Flip(int v, int l, int r, int a, int b) {
        if (l == a && r == b) downOn(v);
        else {
            Down(v);
            int m = l + r >> 1;
            if (a <= m) Flip(2 * v, l, m, a, min(m, b));
            if (m + 1 <= b) Flip(2 * v + 1, m + 1, r, max(m + 1, a), b);
            Union(v);
        }
    }
    segtree(const vector <int> &dist) {
        n = int(dist.size()) - 1;
        if (n == 0) return;
        int m = 1;
        while (m <= 4 * n) m <<= 1;
        st.resize(m);
        Create(1, 1, n, dist);
    }
    void Flip(int a, int b) { Flip(1, 1, n, a, b); }
    ill Get() { return st[1].val[0]; }
};

int n;
vector <ii> neigh[Maxn];
int cnt[Maxn];
int L[Maxn], P[Maxn], PE[Maxn];
vector <int> E[Maxn];
int head[Maxn], ind[Maxn];
segtree st[Maxn];
ill my[Maxn][2];
ill cur;
bool tk[Maxn];
int sav = 1;
int tot = 1;
vector <int> res;

void Count(int v)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (P[v] == u) continue;
        L[u] = L[v] + 1; P[u] = v;
        PE[u] = neigh[v][i].second;
        Count(u);
        cnt[v] += cnt[u];
    }
}

void Flip(int e) 
{
    cur = Sub(cur, my[e][0]);
    swap(my[e][0], my[e][1]);
    cur = Add(cur, my[e][0]);
}

void buildHLD(int v)
{
    E[head[v]].push_back(PE[v]);
    bool was = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (P[v] == u) continue;
        if (cnt[u] > cnt[v] / 2) {
            was = true;
            head[u] = head[v];
            ind[u] = ind[v] + 1;
        } else {
            head[u] = u;
            ind[u] = 0;
        }
        buildHLD(u);
    }
    if (!was) st[head[v]] = segtree(E[head[v]]);
}

void flipPath(int a, int b)
{
    while (head[a] != head[b]) {
        if (L[head[a]] < L[head[b]])
            swap(a, b);
        if (ind[a]) {
            cur = Sub(cur, st[head[a]].Get());
            st[head[a]].Flip(1, ind[a]);
            cur = Add(cur, st[head[a]].Get());
        }
        Flip(PE[head[a]]);
        a = P[head[a]];
    }
    if (L[a] < L[b]) swap(a, b);
    if (a != b) {
        cur = Sub(cur, st[head[a]].Get());
        st[head[a]].Flip(ind[b] + 1, ind[a]);
        cur = Add(cur, st[head[a]].Get());
    }
}

void Query1(int v)
{
    tk[v] = true;
    tot++;
    if (sav == -1) { sav = v; printf("0\n"); return; }
    flipPath(v, sav);
    sav = -1;
    if (cur.first == tot / 2) printf("%I64d\n", cur.second);
    else printf("0\n");
}

void Collect1(int v)
{
    cnt[v] = tk[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (P[v] == u) continue;
        Collect1(u);
        if (cnt[u] > 0 && cnt[u] % 2)
            res.push_back(neigh[v][i].second);
        cnt[v] += cnt[u];
    }
}

void Query2()
{
    if (tot % 2 || cur.first != tot / 2) { printf("0\n"); return; }
    res.clear();
    Collect1(1);
    sort(res.begin(), res.end());
    printf("%d", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf(" %d", res[i]);
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
       // int a = i, b = i + 1;
        neigh[a].push_back(ii(b, i));
        neigh[b].push_back(ii(a, i));
        my[i][1] = ill(1, ll(i));
    }
    L[1] = 1;
    Count(1);
    head[1] = 1;
    buildHLD(1);
    tk[1] = true;
    int typ;
    while (scanf("%d", &typ) == 1) {
        if (typ == 1) {
            int v; scanf("%d", &v);
            Query1(v);
            fflush(stdout);
        } else if (typ == 2) {
            Query2();
            fflush(stdout);
        } else break;
    }
    return 0;
}