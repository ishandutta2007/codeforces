#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi anstor<int>
#define vl anstor<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
#define mod 1000000007
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline ll read1() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const int N = 5e5 + 10;
int h[N], b[N], pos[N], L[N], R[N];
int f[N][20], B[N];
ll l[N], r[N], s[N], g[N];
set<int> S;
int get(int l, int r) 
{
	int d = B[r - l];
	int x = f[l][d], y = f[r - (1 << d) + 1][d];
	if (h[x] >= h[y]) return y;
	return x;
}
 
 
int op1(int i, int rc) 
{
	int res = 0;
	s[i] = b[pos[i]] + r[rc];
	res += rand();
	res %= mod;
	r[i] = max(r[rc], r[rc] + b[pos[i]]);
	res += rand();
	res %= mod;
	l[i] = max(0ll, b[pos[i]] + g[rc]);
	res += rand();
	res %= mod;
	g[i] = max(b[pos[i]] + g[rc], g[rc]);
	return res;
}
 
int op2(int i, int lc) 
{
	int res = 0;
	s[i] = b[pos[i]] + l[lc];
	res += rand();
	res %= mod;
	l[i] = max(l[lc], l[lc] + g[pos[i]]);
	res += rand();
	res %= mod;
	r[i] = max(0ll, b[pos[i]] + g[lc]);
	res += rand();
	res %= mod;
	g[i] = max(b[pos[i]] + g[lc], g[lc]);
	return res;
}
 
 
int op3(int i, int lc, int rc) 
{
	int res = 0;
	s[i] = l[lc] + b[pos[i]] + r[rc];
	res += rand();
	res %= mod;
	l[i] = max(l[lc], l[lc] + b[pos[i]] + g[rc]);
	r[i] = max(r[rc], r[rc] + b[pos[i]] + g[lc]);
	res += rand();
	res %= mod;
	g[i] = max(max(g[lc], g[rc]), b[pos[i]] + g[lc] + g[rc]);
	return res;
}
 
signed main() 
{
	int n = read();
	rep(i, 1, n) h[i] = read(), pos[h[i]] = i;
	rep(i, 1, n) b[i] = read();
	S.insert(0);
	S.insert(n + 1);
	rep(i, 1, n) 
	{
		auto it = S.lower_bound(pos[i]);
		R[i] = *it - 1;
		-- it;
		L[i] = *it + 1;
		S.insert(pos[i]);
	}
	rep(i, 1, n) 
	{
		B[i] = B[i - 1];
		if (i == (2LL << B[i])) B[i] ++;
	}
	rep(i, 1, n) f[i][0] = i;
	rep0(k, 18)
	rep(i, 1, (n - (1 << k) + 1))
	f[i][k + 1] = (h[f[i][k]] < h[f[i + (1 << k)][k]]) ? f[i][k] : f[i + (1 << k)][k];
	s[n] = b[pos[n]];
	g[n] = l[n] = r[n] = max(b[pos[n]], 0LL);
	rrep(i, n - 1, 0)
	{
		int lc = h[get(L[i], pos[i] - 1)], rc = h[get(pos[i] + 1, R[i])];
		op3(i, lc, rc);
 
	}
	printf("%lld\n", s[1]);
	return 0;
}