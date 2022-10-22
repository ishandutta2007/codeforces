#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;
const int Maxm = 1048576;

struct node {
    int cnt, ways;
};

int fac[Maxn], inv[Maxn];
int n, m;
int a[Maxn];
int t[Maxn];
node st[Maxm];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

node Union(const node &a, const node &b)
{
    node c;
    c.cnt = a.cnt + b.cnt;
    c.ways = ll(a.ways) * b.ways % mod * C(a.cnt + b.cnt, a.cnt) % mod;
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) { st[v].cnt = a[l]; st[v].ways = 1; }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Remove(int v, int l, int r, int x)
{
    if (l == r) { st[v].cnt = a[l]; st[v].ways = 1; }
    else {
        int m = l + r >> 1;
        if (x <= m) Remove(2 * v, l, m, x);
        else Remove(2 * v + 1, m + 1, r, x);
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

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int s; scanf("%d", &s);
        a[s]++;
    }
    for (int i = 0; i < m; i++)
        scanf("%d", &t[i]);
    Create(1, 0, Maxn - 1);
    for (int i = 0; i < m; i++) {
        node p1 = Get(1, 0, Maxn - 1, 0, t[i] - 1);
        node p2 = Get(1, 0, Maxn - 1, t[i], Maxn - 1);
        if (p1.cnt > 0) res = (res + ll(p1.ways) * p2.ways % mod * C(p1.cnt - 1 + p2.cnt, p1.cnt - 1)) % mod;
        if (a[t[i]] == 0) break;
        a[t[i]]--;
        Remove(1, 0, Maxn - 1, t[i]);
        if (i + 1 < m && i + 1 >= n) res = (res + 1) % mod;
    }
    printf("%d\n", res);
    return 0;
}