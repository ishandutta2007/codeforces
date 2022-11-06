#include <bits/stdc++.h>
using namespace std;
#define lson x << 1
#define rson x << 1 | 1
const int N = 300010;
struct Segtree
{
    int l, r, val, add, tol, tol2;
} T[N << 2];
int p[N], a[N];
int n;
long long ans;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void Build (int x, int l, int r)
{
    T[x].l = l, T[x].r = r;
    T[x].tol = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build (lson, l, mid);
    Build (rson, mid + 1, r);
}
void push (int x)
{
    if (T[x].add == 0) return;
    T[lson].add += T[x].add;
    T[rson].add += T[x].add;
    T[lson].val += T[x].add;
    T[rson].val += T[x].add;
    T[x].add = 0;
}
void update (int x)
{
    T[x].val = min (T[lson].val, T[rson].val);
    T[x].tol = T[lson].tol * (T[x].val == T[lson].val) + T[rson].tol * (T[x].val == T[rson].val);
    T[x].tol2 = T[lson].tol * (T[x].val + 1 == T[lson].val) + T[rson].tol * (T[x].val + 1 == T[rson].val);
    T[x].tol2 += T[lson].tol2 * (T[x].val == T[lson].val) + T[rson].tol2 * (T[x].val == T[rson].val);
}
void Modify (int x, int l, int r, int key)
{
    if (T[x].l >= l && T[x].r <= r)
    {
        T[x].val += key, T[x].add += key;
        return;
    }
    push (x);
    int mid = (T[x].l + T[x].r) >> 1;
    if (mid >= l) Modify (lson, l, r, key);
    if (mid < r) Modify (rson, l, r, key);
    update (x);
}
void Query (int x, int l, int r)
{
    if (T[x].l >= l && T[x].r <= r)
    {
        ans += T[x].tol * (T[x].val <= 2) + T[x].tol2 * (T[x].val == 1);
        return;
    }
    push (x);
    int mid = (T[x].l + T[x].r) >> 1;
    if (mid >= l) Query (lson, l, r);
    if (mid < r) Query (rson, l, r);
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
    	int x = read();
        p[x] = i;
    }
    Build (1, 1, n);
    for (int i = n; i; i --)
    {
        a[p[i]] = i;
        int x = a[p[i] - 1], y = a[p[i] + 1];
        if (x > y) swap (x, y);
        if (x) Modify (1, i, x - 1, 1), Modify (1, y, n, -1);
        else if (y) Modify (1, i, y - 1, 1);
        else Modify (1, i, n, 1);
        Query (1, i, n);
    }
    printf ("%I64d", ans-n);
}