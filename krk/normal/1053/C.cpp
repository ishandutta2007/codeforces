#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    int lef, anslef;
    int rig, ansrig;
    ll sum;
    int cnt;
};

int n, q;
int a[Maxn];
int w[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
    node c;
    c.lef = a.lef;
    c.anslef = (ll(a.anslef) + ll(b.anslef) + ll(b.sum) % mod * (b.lef - a.lef - a.cnt)) % mod;
    c.rig = b.rig;
    c.ansrig = (ll(a.ansrig) + ll(b.ansrig) + ll(a.sum) % mod * (b.rig - a.rig - b.cnt)) % mod;
    c.sum = a.sum + b.sum;
    c.cnt = a.cnt + b.cnt;
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].lef = st[v].rig = a[l];
        st[v].anslef = st[v].ansrig = 0;
        st[v].sum = w[l];
        st[v].cnt = 1;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) st[v].sum = w[x];
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

ll getSum(int v, int l, int r, int a, int b)
{
    if (a > b) return 0;
    if (l == a && r == b) return st[v].sum;
    else {
        int m = l + r >> 1;
        if (b <= m) return getSum(2 * v, l, m, a, b);
        if (m + 1 <= a) return getSum(2 * v + 1, m + 1, r, a, b);
        return getSum(2 * v, l, m, a, m) + getSum(2 * v + 1, m + 1, r, m + 1, b);
    }
}

int getInd(int v, int l, int r, ll sum)
{
    if (l == r) return l;
    else {
        int m = l + r >> 1;
        if (sum < st[2 * v].sum) return getInd(2 * v, l, m, sum);
        return getInd(2 * v + 1, m + 1, r, sum - st[2 * v].sum);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    Create(1, 1, n);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        if (x < 0) {
            x = -x;
            w[x] = y;
            Update(1, 1, n, x);
        } else {
            ll A = getSum(1, 1, n, 1, x - 1);
            ll B = getSum(1, 1, n, x, y);
            int ind = getInd(1, 1, n, A + B / 2);
            if (ind < x) {
                node got2 = Get(1, 1, n, x, y);
                printf("%d\n", got2.anslef);
            } else if (ind > y) {
                node got1 = Get(1, 1, n, x, y);
                printf("%d\n", got1.ansrig);
            } else {
                node got1 = Get(1, 1, n, x, ind);
                node got2 = Get(1, 1, n, ind, y);
                printf("%d\n", (got1.ansrig + got2.anslef) % mod);
            }
        }
    }
    return 0;
}