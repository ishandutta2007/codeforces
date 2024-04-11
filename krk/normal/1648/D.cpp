#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 2000000000000000000ll;
const int Maxn = 500005;
const int Maxm = 2097152;

struct node {
    ll best1, best2;
    ll res;
};

int n, q;
int B[3][Maxn];
ll sum[Maxn];
ll mx[Maxm];
int ql[Maxn], qr[Maxn], qk[Maxn];
vector <int> quer[Maxn];
ll A[Maxn], A2[Maxn];
node st[Maxm];

void Clear(int v, int l, int r)
{
    mx[v] = -Inf;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

ll getMax(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return mx[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return getMax(2 * v, l, m, a, b);
        if (m + 1 <= a) return getMax(2 * v + 1, m + 1, r, a, b);
        return max(getMax(2 * v, l, m, a, m), getMax(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Insert(int v, int l, int r, int x, ll val)
{
    if (l == r) mx[v] = max(mx[v], val);
    else {
        int m = l + r >> 1;
        if (x <= m) Insert(2 * v, l, m, x, val);
        else Insert(2 * v + 1, m + 1, r, x, val);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
}

void Export(int v, int l, int r)
{
    if (l == r) A[l] = mx[v];
    else {
        int m = l + r >> 1;
        Export(2 * v, l, m);
        Export(2 * v + 1, m + 1, r);
    }
}

node Union(const node &a, const node &b)
{
    node c;
    c.best1 = max(a.best1, b.best1);
    c.best2 = max(a.best2, b.best2);
    c.res = max(max(a.res, b.res), a.best1 + b.best2);
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].best1 = A[l];
        st[v].best2 = A2[l];
        st[v].res = st[v].best1 + st[v].best2;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, min(m, b));
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &B[i][j]);
    for (int j = 1; j <= n; j++)
        sum[j] = sum[j - 1] + B[1][j];
    Clear(1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &ql[i], &qr[i], &qk[i]);
        quer[qr[i]].push_back(i);
    }
    ll cur = 0;
    for (int j = 1; j <= n; j++) {
        cur += B[0][j];
        Insert(1, 1, n, j, cur - sum[j - 1]);
        for (int l = 0; l < quer[j].size(); l++) {
            int ind = quer[j][l];
            if (qr[ind] < n) {
                ll got = getMax(1, 1, n, ql[ind], qr[ind]);
                Insert(1, 1, n, qr[ind] + 1, got - qk[ind]);
            }
        }
    }
    Export(1, 1, n);
    cur = 0;
    for (int j = n; j >= 1; j--) {
        cur += B[2][j];
        A2[j] = cur + sum[j];
    }
    Create(1, 1, n);
    ll res = -Inf;
    for (int i = 0; i < q; i++)
        res = max(res, Get(1, 1, n, ql[i], qr[i]).res - qk[i]);
    cout << res << endl;
    return 0;
}