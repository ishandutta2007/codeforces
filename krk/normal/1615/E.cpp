#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const ll Inf = 9000000000000000000ll;

int n, k;
ll best[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int inlef[Maxn];
ii st[Maxm];
int flag[Maxm];
int P[Maxn], L[Maxn];
bool tk[Maxn];

void downOn(int v, int f)
{
    st[v].first += f;
    flag[v] += f;
}

void Down(int v)
{
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

void Union(int v)
{
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r) { st[v] = ii(L[inlef[l]], inlef[l]); }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) downOn(v, -1);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
        Union(v);
    }
}

void Update(int v)
{
    if (!v || tk[v]) return;
    tk[v] = true;
    Update(1, 1, n, lef[v], rig[v]);
    Update(P[v]);
}

void Traverse(int v)
{
    lef[v] = ++cur; inlef[lef[v]] = v;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        P[u] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
    rig[v] = cur;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        best[i] = max(best[i - 1], ll(i) * (n - i));
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    L[1] = 1;
    Traverse(1);
    Create(1, 1, n);
    int lft = n;
    ll res = -best[lft];
    for (int i = 1; i <= k; i++) {
        ii mx = st[1];
        if (mx.first > 0) {
            lft -= mx.first;
            Update(mx.second);
        }
        res = max(res, ll(i) * (n - i) - best[lft]);
    }
    cout << res << endl;
    return 0;
}