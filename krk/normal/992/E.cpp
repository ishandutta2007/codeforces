#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, q;
int a[Maxn];
ii mx[Maxm];
ll sum[Maxm];

void Union(int v)
{
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
}

void Create(int v, int l, int r)
{
    if (l == r) { mx[v] = ii(a[l], l); sum[v] = a[l]; }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) { mx[v] = ii(a[l], l); sum[v] = a[l]; }
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        Union(v);
    }
}

ill getMax(int v, int l, int r, int x, ll nd, ll col)
{
    if (max(nd, col) > mx[v].first) return ill(-1, col);
    if (l == r) return ill(l, col);
    else {
        int m = l + r >> 1;
        if (x <= m) {
            ill got = getMax(2 * v, l, m, x, nd, col);
            if (got.first != -1) return got;
        }
        ill got = getMax(2 * v + 1, m + 1, r, x, nd, col + sum[2 * v]);
        return got;
    }
}

int Solve()
{
    if (a[1] == 0) return 1;
    int from = 1, nd = a[1];
    while (from <= n && nd <= 1000000000) {
        ill got = getMax(1, 1, n, from, nd, 0);
        if (got.first == -1) return -1;
        if (a[got.first] == got.second) return got.first;
        from = got.first + 1;
        nd = a[got.first] + got.second;
    }
    return -1;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    while (q--) {
        int ind, val; scanf("%d %d", &ind, &val);
        a[ind] = val;
        Update(1, 1, n, ind);
        printf("%d\n", Solve());
    }
    return 0;
}