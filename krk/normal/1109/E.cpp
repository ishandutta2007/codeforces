#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100002;
const int Maxm = 524288;
const int Maxs = 11;

int n, mod;
int a[Maxn];
int mx[Maxn];
int inv[Maxn];
vector <int> my;
int tmp[Maxs + 1];
bool give[Maxm];
int fl[Maxm][Maxs + 1], mult[Maxm];
int sum[Maxm];

int toPower(int a, int p)
{
    int res = 1;
    while (p > 0) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

void gcd(ll a, ll &x, ll b, ll &y)
{
    if (a == 0) { x = 0; y = 1; }
    else {
        ll xx, yy;
        gcd(b % a, xx, a, yy);
        x = yy - b / a * xx;
        y = xx;
    }
}

int getInv(int a, int mod)
{
    ll x, y;
    gcd(a, x, mod, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

void downOn(int v, int f[], int mul)
{
    give[v] = true;
    for (int i = 0; i < my.size(); i++)
        fl[v][i] += f[i];
    fl[v][Maxs] = ll(fl[v][Maxs]) * f[Maxs] % mod;
    mult[v] = ll(mult[v]) * mul % mod;
    sum[v] = ll(sum[v]) * mul % mod;
}

void Down(int v)
{
    if (give[v]) {
        downOn(2 * v, fl[v], mult[v]);
        downOn(2 * v + 1, fl[v], mult[v]);
        give[v] = false;
        fill(fl[v], fl[v] + int(my.size()), 0);
        fl[v][Maxs] = 1;
        mult[v] = 1;
    }
}

void Union(int v)
{
    sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
}

void Export(int val, bool inverse, int tmp[])
{
    fill(tmp, tmp + int(my.size()), 0);
    tmp[Maxs] = 1;
    while (val > 1) {
        int pr = mx[val];
        if (inv[pr] <= 0) tmp[-inv[pr]] += inverse? -1: 1;
        else tmp[Maxs] = ll(tmp[Maxs]) * (inverse? inv[pr]: pr) % mod;
        val /= pr;
    }
}

int Import(int tmp[])
{
    int num = 1;
    for (int i = 0; i < my.size(); i++)
        num = ll(num) * toPower(my[i], tmp[i]) % mod;
    num = ll(num) * tmp[Maxs] % mod;
    return num;
}

void Create(int v, int l, int r)
{
    fl[v][Maxs] = mult[v] = 1;
    if (l == r) {
        Export(a[l], false, fl[v]);
        sum[v] = Import(fl[v]);
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Multiply(int v, int l, int r, int a, int b, int tmp[], int mul)
{
    if (l == a && r == b) downOn(v, tmp, mul);
    else {
        int m = l + r >> 1;
        Down(v);
        if (a <= m) Multiply(2 * v, l, m, a, min(m, b), tmp, mul);
        if (m + 1 <= b) Multiply(2 * v + 1, m + 1, r, max(m + 1, a), b, tmp, mul);
        Union(v);
    }
}

int getSum(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return sum[v];
    else {
        int res = 0;
        int m = l + r >> 1;
        Down(v);
        if (a <= m) res = (res + getSum(2 * v, l, m, a, min(m, b))) % mod;
        if (m + 1 <= b) res = (res + getSum(2 * v + 1, m + 1, r, max(m + 1, a), b)) % mod;
        return res;
    }
}

void Divide(int v, int l, int r, int x, int tmp[])
{
    if (l == r) {
        downOn(v, tmp, 1);
        sum[v] = Import(fl[v]);
    } else {
        int m = l + r >> 1;
        Down(v);
        if (x <= m) Divide(2 * v, l, m, x, tmp);
        else Divide(2 * v + 1, m + 1, r, x, tmp);
        Union(v);
    }
}

int main()
{
    scanf("%d %d", &n, &mod);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0) {
        for (int j = i; j < Maxn; j += i) mx[j] = i;
        if (mod % i == 0) {
            inv[i] = -int(my.size());
            my.push_back(i);
        } else inv[i] = getInv(i, mod);
    }
    Create(1, 1, n);
    int m; scanf("%d", &m);
    while (m--) {
        int typ, a, b, c; scanf("%d %d %d", &typ, &a, &b);
        if (typ == 1) {
            scanf("%d", &c);
            Export(c, false, tmp);
            Multiply(1, 1, n, a, b, tmp, c);
        } else if (typ == 2) {
            Export(b, true, tmp);
            Divide(1, 1, n, a, tmp);
        } else if (typ == 3)
            printf("%d\n", getSum(1, 1, n, a, b));
    }
    return 0;
}