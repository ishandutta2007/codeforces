#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;
const ll Inf = 4000000000000000000ll;

struct pos {
    int l, r;
    ll dist[2][2];
    pos() {
        fill((ll*)dist, (ll*)dist + 2 * 2, Inf);
    }
};

int n;
ii entr[Maxn][2];
ii nxt[Maxn][2];
pos st[Maxm];

ii Read()
{
    int a, b; scanf("%d %d", &a, &b);
    return ii(a, b);
}

int Len(const ii &a, const ii &b) { return abs(a.first - b.first) + abs(a.second - b.second); }

pos Union(const pos &a, const pos &b)
{
    pos c;
    c.l = a.l;
    c.r = b.r;
    for (int i1 = 0; i1 < 2; i1++)
        for (int j1 = 0; j1 < 2; j1++)
            for (int i2 = 0; i2 < 2; i2++)
                for (int j2 = 0; j2 < 2; j2++)
                    c.dist[i1][j2] = min(c.dist[i1][j2], a.dist[i1][j1] + 1 + Len(nxt[a.r][j1], entr[b.l][i2]) + b.dist[i2][j2]);
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].l = st[v].r = r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                st[v].dist[i][j] = Len(entr[l][i], entr[l][j]);
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

pos Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        entr[i][0] = Read();
        entr[i][1] = Read();
        nxt[i][0] = ii(entr[i][0].first + 1, entr[i][0].second);
        nxt[i][1] = ii(entr[i][1].first, entr[i][1].second + 1);
    }
    Create(1, 1, n - 1);
    int m; scanf("%d", &m);
    while (m--) {
        ii a = Read(), b = Read();
        int la = max(a.first, a.second);
        int lb = max(b.first, b.second);
        if (la == lb) { printf("%d\n", Len(a, b)); continue; }
        if (la > lb) {
            swap(a, b);
            swap(la, lb);
        }
        auto got = Get(1, 1, n - 1, la, lb - 1);
        ll res = Inf;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                res = min(res, Len(a, entr[la][i]) + got.dist[i][j] + 1 + Len(nxt[lb - 1][j], b));
        printf("%I64d\n", res);
    }
    return 0;
}