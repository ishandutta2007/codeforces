#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define int long long
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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 1e6 + 10;
int n, m, p;
int a[N], ca[N], b[N], cb[N], x[N], y[N], z[N];
int mx[N], tag[N], V[N];
vi at[N], Mo[N];
void push_down(int rt)
{
	if (tag[rt])
	{
		mx[ls] += tag[rt];
		mx[rs] += tag[rt];
		tag[ls] += tag[rt];
		tag[rs] += tag[rt];
		tag[rt] = 0;
	}
}
void modify(int l, int r, int rt, int x, int y, int v)
{
	if (x <= l && r <= y) 
	{
		mx[rt] += v;
		tag[rt] += v;
		return;
	}
	int mid = (l + r) >> 1;
	push_down(rt);
	if (x <= mid) modify(l, mid, ls, x, y, v);
	if (y > mid) modify(mid + 1, r, rs, x, y, v);
	mx[rt] = max(mx[ls], mx[rs]);
}
signed main()
{
	n = read();
	m = read();
	p = read();
	rep(i, 1, n)
		a[i] = read(), ca[i] = read();
	rep(i, 1, m)
		b[i] = read(), cb[i] = read();
	rep(i, 1, p)
		x[i] = read(), y[i] = read(), z[i] = read();
	rep(i, 1, n) at[a[i]].pb(i);
	rep(i, 1, p) Mo[x[i]].pb(i);

	vi fj;
	rep(i, 1, m) fj.pb(b[i]);
	sort(ALL(fj));
	fj.erase(unique(ALL(fj)), fj.end());
	int sz = fj.size();
	rep(i, 1, sz) V[i] = 0x7f7f7f7f;
	rep(i, 1, m)
	{
		b[i] = upper_bound(ALL(fj), b[i]) - fj.begin();
		V[b[i]] = min(V[b[i]], cb[i]);
	}
	rep(i, 1, sz) modify(1, sz, 1, i, i, -V[i]);
	int ans = -ca[1] - cb[1];
	rep0(t, N)
	{
		rep0(xx, sz(at[t])) {int i = at[t][xx]; ans = max(ans, mx[1] - ca[i]);}
		rep0(xx, sz(Mo[t]))
		{
			int i = Mo[t][xx];
			int id = upper_bound(ALL(fj), y[i]) - fj.begin() + 1;
			if (id <= sz) modify(1, sz, 1, id, sz, z[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}