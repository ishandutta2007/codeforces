#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400005;
const int Maxm = 301;
const int Maxk = 62;
const int Maxs = 2097152;
const int mod = 1000000007;

vector <int> V;
int cur, mx[Maxm];
int myind[Maxm], myval[Maxm];
int n, q;
int a[Maxn];
int st[Maxs], stflag[Maxs];
ll has[Maxs], hasflag[Maxs];

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

void downOn(int v, int siz, int gst, ll ghas)
{
    st[v] = ll(st[v]) * toPower(gst, siz) % mod;
    has[v] |= ghas;
    stflag[v] = ll(stflag[v]) * gst % mod;
    hasflag[v] |= ghas;
}

void Down(int v, int l, int m, int r)
{
    if (hasflag[v]) {
        downOn(2 * v, m + 1 - l, stflag[v], hasflag[v]);
        downOn(2 * v + 1, r - m, stflag[v], hasflag[v]);
        stflag[v] = 1; hasflag[v] = 0;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    st[v] = ll(st[lc]) * st[rc] % mod;
    has[v] = (has[lc] | has[rc]);
}

ll getFlag(int x)
{
    ll res = 0;
    while (x > 1) {
        int cur = mx[x];
        res |= 1ll << ll(myind[cur]);
        x /= cur;
    }
    return res;
}

void Create(int v, int l, int r)
{
    stflag[v] = 1;
    if (l == r) { st[v] = a[l]; has[v] = getFlag(a[l]); }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Multiply(int v, int l, int r, int a, int b, int val, ll ghas)
{
    if (l == a && r == b) downOn(v, r - l + 1, val, ghas);
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (a <= m) Multiply(2 * v, l, m, a, min(m, b), val, ghas);
        if (m + 1 <= b) Multiply(2 * v + 1, m + 1, r, max(m + 1, a), b, val, ghas);
        Union(v);
    }
}

void Get(int v, int l, int r, int a, int b, int &val, ll &ghas)
{
    if (l == a && r == b) {
        val = ll(val) * st[v] % mod;
        ghas |= has[v];
    } else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (a <= m) Get(2 * v, l, m, a, min(m, b), val, ghas);
        if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b, val, ghas);
    }
}

int main()
{
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0) {
        V.push_back(i);
        myind[i] = cur++; myval[i] = (1 - Inv(i) + mod) % mod;
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    }
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    char str[50];
    for (int i = 1; i <= q; i++) {
        scanf("%s", str);
        int l, r, x; scanf("%d %d", &l, &r);
        if (str[0] == 'M') {
            scanf("%d", &x);
            Multiply(1, 1, n, l, r, x, getFlag(x));
        } else {
            int res = 1;
            ll got = 0;
            Get(1, 1, n, l, r, res, got);
            for (int i = 0; i < Maxk; i++)
                if (got & 1ll << ll(i))
                    res = ll(res) * myval[V[i]] % mod;
            printf("%d\n", res);
        }
    }
    return 0;
}