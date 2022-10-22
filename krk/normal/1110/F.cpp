#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 2097152;
const ll Inf = 1000000000000000000ll;

struct triple {
    int l, r, ind;
    triple(int l = 0, int r = 0, int ind = 0): l(l), r(r), ind(ind) {}
};

int n, q;
ll st[Maxm], fl[Maxm];
vector <ii> neigh[Maxn];
int lef[Maxn], rig[Maxn];
ll dist[Maxn];
vector <triple> my[Maxn];
ll res[Maxn];

void downOn(int v, ll f)
{
    st[v] += f; fl[v] += f;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Union(int v)
{
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r) st[v] = dist[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, ll val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

ll Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return min(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Move(int l, int r, ll delt)
{
    Update(1, 1, n, l, r, delt);
    if (1 < l) Update(1, 1, n, 1, l - 1, -delt);
    if (r < n) Update(1, 1, n, r + 1, n, -delt);
}

void Traverse(int v, ll d)
{
    if (neigh[v].empty()) {
        dist[v] = d;
        lef[v] = rig[v] = v;
        return;
    }
    dist[v] = Inf;
    lef[v] = n; rig[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        Traverse(u.first, d + u.second);
        lef[v] = min(lef[v], lef[u.first]);
        rig[v] = max(rig[v], rig[u.first]);
    }
}

void Solve(int v)
{
    for (int i = 0; i < my[v].size(); i++) {
        triple t = my[v][i];
        res[t.ind] = Get(1, 1, n, t.l, t.r);
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        Move(lef[u.first], rig[u.first], -u.second);
        Solve(u.first);
        Move(lef[u.first], rig[u.first], u.second);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int p, d; scanf("%d %d", &p, &d);
        neigh[p].push_back(ii(i, d));
    }
    for (int i = 0; i < q; i++) {
        int v, l, r; scanf("%d %d %d", &v, &l, &r);
        my[v].push_back(triple(l, r, i));
    }
    Traverse(1, 0);
    Create(1, 1, n);
    Solve(1);
    for (int i = 0; i < q; i++)
        printf("%I64d\n", res[i]);
    return 0;
}