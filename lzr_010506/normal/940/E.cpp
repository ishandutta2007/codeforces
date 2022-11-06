#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
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


int n, c;

const int N = 100010;
int a[N];
ll dp[N];
int minv[N << 2];

void Build(int l, int r, int rt) 
{
    if (l == r) 
    {
        minv[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, ls);
    Build(mid + 1, r, rs);
    minv[rt] = min(minv[ls], minv[rs]);
}

int Query(int L, int R, int l, int r, int rt) 
{
    if (L <= l && r <= R) return minv[rt];
    int mid = (l + r) >> 1;
    int ret = 0x7f7f7f7f;
    if (L <= mid) ret = min(ret, Query(L, R, l, mid, ls));
    if (R > mid) ret = min(ret, Query(L, R, mid + 1, r, rs));
    return ret;
}

int main() 
{
    n = read();
    c = read();
    ll ans = 0;
    rep(i, 1, n) a[i] = read();
    Build(1, n, 1);
    rep(i, 1, n)
    {
        ans += a[i];
        dp[i] = dp[i-1];
        if (i - c + 1 >= 1) 
            dp[i] = max(dp[i], dp[i - c] + Query(i - c + 1, i, 1, n, 1));
    }
    printf("%lld\n", ans - dp[n]);
    return 0;
}