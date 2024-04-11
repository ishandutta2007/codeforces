#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 20000000;

struct node {
    int a, b;
    int L, R;
    node(): a(0), b(0), L(0), R(0) {}
};

int n;
vector <int> neigh[Maxn];
int q;
int qv[Maxn], qk[Maxn];
vector <int> quer[Maxn];
int res[Maxn];
node st[Maxm];
int stlen;

int createNew() { return stlen++; }

void Add(int &v, int l, int r, int a, int b, int vala, int valb)
{
    if (!v) v = createNew();
    if (l == a && r == b) {
        st[v].a += vala;
        st[v].b += valb;
    } else {
        int m = l + r >> 1;
        if (b <= m) Add(st[v].L, l, m, a, b, vala, valb);
        else if (m + 1 <= a) Add(st[v].R, m + 1, r, a, b, vala, valb);
        else {
            Add(st[v].L, l, m, a, m, vala, valb);
            Add(st[v].R, m + 1, r, m + 1, b, vala + (m + 1 - a) * valb, valb);
        }
    }
}

int Get(int v, int l, int r, int x)
{
    if (!v) return 0;
    int res = st[v].a + st[v].b * (x - l);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res += Get(st[v].L, l, m, x);
        else res += Get(st[v].R, m + 1, r, x);
    }
    return res;
}

void Union(int &v, int othv, int l, int r)
{
    if (!othv) return;
    if (!v) { v = othv; return; }
    st[v].a += st[othv].a;
    st[v].b += st[othv].b;
    if (l < r) {
        int m = l + r >> 1;
        Union(st[v].L, st[othv].L, l, m);
        Union(st[v].R, st[othv].R, m + 1, r);
    }
}

int Solve(int v, int p)
{
    int cur = createNew();
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Union(cur, Solve(u, v), 0, Maxn);
    }
    int ch = int(neigh[v].size()) - (p != 0);
    for (int i = 0; i < quer[v].size(); i++) {
        int ind = quer[v][i];
        res[ind] = ch + Get(cur, 0, Maxn, qk[ind]);
    }
    int l = 0, r = Maxn;
    while (l <= r) {
        int mid = l + r >> 1;
        if (Get(cur, 0, Maxn, mid) + (ch - mid) > 0)
            l = mid + 1;
        else r = mid - 1;
    }
    if (l > 0) Add(cur, 0, Maxn, 0, l - 1, ch, -1);
    while (l <= Maxn) {
        int g = Get(cur, 0, Maxn, l);
        if (g == 0) break;
        Add(cur, 0, Maxn, l, l, -g, 0);
        l++;
    }
    return cur;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qv[i], &qk[i]);
        qk[i]++;
        quer[qv[i]].push_back(i);
    }
    createNew();
    Solve(1, 0);
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}