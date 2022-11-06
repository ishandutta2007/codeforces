#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define E Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).sze()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 2e6 + 10;
struct vec
{
	ll to, next;
}E[N * 2];
ll head[N], cnt, n, rt, rtf, sum, ct[N],sz[N];
bool vis[N];
ll tim[M],v[M], T;
char s[N];
ll ans[N], tE[N], tot;
inline void ins(ll x,ll y)
{
	E[++ cnt].to = y;
	E[cnt].next = head[x];
	head[x] = cnt;
}
inline void insert(ll x,ll y)
{
	ins(x, y);
	ins(y, x);
}
void getrt(ll x, ll fa)
{
	ll i,y;
	sz[x] = 1;
	ct[x] = 0;
	for(i = head[x]; i; i = E[i].next)
	{
		y = E[i].to;
		if(!vis[y] && y != fa)
		{
			getrt(y, x);
			sz[x] += sz[y];
			ct[x] = max(ct[x], sz[y]);
		}
	}
	ct[x] = max(ct[x], sum - sz[x]);
	if(ct[x] < ct[rt]) rt = x, rtf = fa;
}

void add(ll x, ll y)
{
	if(tim[x] != T)	v[x] = 0;
	tim[x] = T;
	v[x] += y;
}
ll ask(ll x)
{
	if(tim[x] != T) v[x] = 0;
	return v[x];
}
ll dfs1(ll x, ll fa, ll now)
{
	ll i,y;
	ll res = 0;
	now ^= (1 << s[x]);
	res += ask(now);
	rep(i, 0, 19)
		(res += ask(now ^ (1 << i)));
	for(i = head[x]; i; i = E[i].next)
	{
		y=E[i].to;
		if(!vis[y] && y != fa)
			res += dfs1(y, x, now);
	}
	ans[x] += res;
	return res;
}
void dfs2(ll x, ll fa, ll now)
{
	ll i,y;
	now ^= (1 << s[x]);
	add(now, 1);
	for(i = head[x]; i; i = E[i].next)
	{
		y = E[i].to;
		if(!vis[y] && y != fa)
			dfs2(y, x, now);
	}
}
void work(ll x)
{
	ll i,y;
	vis[x] = 1;
	T ++;
	add(0, 1);
	tot = 0;
	for(i = head[x]; i; i = E[i].next)
	{
		y = E[i].to;
		if(!vis[y])
		{
			tE[++ tot] = y;
			(ans[x] += dfs1(y, x, 1 << s[x]));
			dfs2(y, x, 0);
		}
	}
	T ++;
	for(i = tot; i; i --)
	{
		y = tE[i];
		dfs1(y, x, 1 <<s[x]);
		dfs2(y, x, 0);
	}
	for(i = head[x]; i; i = E[i].next)
	{
		y = E[i].to;
		if(!vis[y])
		{
			rt = 0;
			sum = sz[y];
			getrt(y, x);
			sz[rtf] = sum - sz[rt];
			work(rt);
		}
	}
}
int main()
{
	n = read();
	rep(i, 1, n - 1)
	{
		int x = read();
		int y = read();
		insert(x,y);
	}
	scanf("%s",s + 1);
	rep(i, 1, n) s[i] -= 'a';
	ct[0] = INF;
	sum = n;
	getrt(1, 0);
	work(rt);
	rep(i, 1, n)
		printf("%lld ", ans[i] + 1);
	return 0;
}