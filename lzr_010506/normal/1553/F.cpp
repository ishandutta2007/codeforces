#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline int lowbit(int x)
{
    return x & (-x);
}

const int N = 3e5 + 10;
int n, m;
int a[N];
ll s[N << 2];
ll ss[N << 2];
ll flag[N << 2];
void update(int rt, int l, int r, int pos) 
{
    if (l == r) 
    {
        s[rt] += l;
        ss[rt] ++;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(ls, l, mid, pos);
    else update(rs, mid + 1, r, pos);
    s[rt] = s[ls] + s[rs];
    ss[rt] = ss[ls] + ss[rs];
}
ll query(int rt, int l, int r, int x, int y)
{
    if(x <= l && r <= y) return s[rt];
    int mid = l + r >> 1;
    ll res = 0;
    if(x <= mid) res += query(ls, l, mid, x, y);
    if(y > mid) res += query(rs, mid + 1, r, x, y);
    return res;
}
ll query2(int rt, int l, int r, int x, int y)
{
    if(x <= l && r <= y) return ss[rt];
    int mid = l + r >> 1;
    ll res = 0;
    if(x <= mid) res += query2(ls, l, mid, x, y);
    if(y > mid) res += query2(rs, mid + 1, r, x, y);
    return res;
}
ll tr[N];
void add(int x, int y) 
{
    while(x <= 300000)
    {
        tr[x] += y;
        x += lowbit(x);
    }
}
ll tquery(int x) 
{
    ll res = 0;
    while(x)
    {
        res += tr[x];
        x -= lowbit(x); 
    }
    return res;
}
ll ans[N];
int main()
{
    n = read();
    int mx = 3e5;
    rep(i, 1, n)
    {
        a[i] = read();
        ans[i] = ans[i - 1];
        ans[i] += 1ll * a[i] * (i - 1) - tquery(a[i]);
        rep(j, 0, mx / a[i])
        {
            int l = j * a[i];
            int r = min(l + a[i] - 1, mx);
            ll k = query(1, 0, mx, l, r);
            ll kk = query2(1, 0, mx, l, r);
            ans[i] += k - kk * l;
        }
        for (int j = a[i]; j <= mx; j += a[i]) add(j, a[i]);
        update(1, 0, mx, a[i]);

    }
    rep(i, 1, n) printf("%lld ", ans[i]);
    return 0;
}