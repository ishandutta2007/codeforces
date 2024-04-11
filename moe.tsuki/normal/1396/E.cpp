#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 123456;
int n;
long long k;
vi E[maxn];
int sz[maxn];
int a[maxn];
int b[maxn];
int dep[maxn];
int f[maxn];
int ptr[maxn];
long long ans;
vector<pii> que[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

pii cen;
int c;
vi s;

void dfs(int cur, int fa)
{
	int now = 0;
	sz[cur] = 1;
	for (auto x : E[cur])
		if (x != fa)
		{
			dfs(x, cur);
			sz[cur] += sz[x];
			now = max(now, sz[x]);
		}
	now = max(now, n - sz[cur]);
	cen = min(cen, mp(now, cur));
}

void dfs1(int cur, int fa)
{
	f[cur] = fa;
	dep[cur] = dep[fa] + 1;
	sz[cur] = 1;
	for (auto x : E[cur])
		if (x != fa)
		{
			dfs1(x, cur);
			sz[cur] += sz[x];
			b[cur] += a[x]; 
			if (cur == c)
				s.pb(x);
		}
	a[cur] = sz[cur] & 1;
	b[cur] += 1 - a[cur];
	ans += a[cur];
}

void dfs2(int cur, int fa, int son)
{
	F1 (i, b[cur] / 2)
		que[son].pb(mp(dep[cur], cur));
	for (auto x : E[cur])
		if (x != fa)
			dfs2(x, cur, son);
}

void dfs3(int cur, int fa)
{
	a[cur] = 1 - b[cur];
	for (auto x : E[cur])
		if (x != fa)
		{
			dfs3(x, cur);
			a[cur] += a[x];
		}
}

struct lst
{
	int val;
	lst *nxt, *las;
};

priority_queue<pii> pq;
lst *ls[maxn];

void dfs4(int cur, int fa)
{
	ls[cur] = new lst();
	ls[cur] -> val = cur;
	ls[cur] -> nxt = NULL;
	ls[cur] -> las = ls[cur];
	int lca = 1;
	for (auto x : E[cur])
		if (x != fa)
		{
			dfs4(x, cur);
			lca += a[x];
		}
	for (auto x : E[cur])
		if (x != fa)
			if (a[x]) pq.push(mp(a[x], x));
	pq.push(mp(1, cur));
	
	lca -= a[cur];
	F1 (i, lca / 2)
	{
		auto x = pq.top();
		pq.pop();
		auto y = pq.top();
		pq.pop();
		cout << ls[x.se] -> val << ' ' << ls[y.se] -> val << '\n';
		if (ls[x.se] -> nxt)
			ls[x.se] -> nxt -> las = ls[x.se] -> las;
		ls[x.se] = ls[x.se] -> nxt;
		if (ls[y.se] -> nxt)
			ls[y.se] -> nxt -> las = ls[y.se] -> las;
		ls[y.se] = ls[y.se] -> nxt;
		if (x.fi > 1) pq.push(mp(x.fi - 1, x.se));
		if (y.fi > 1) pq.push(mp(y.fi - 1, y.se));
	}
	lst *dum = new lst();
	dum -> nxt = ls[cur];
	lst *end = dum;
	while (end -> nxt) end = end -> nxt;
	for (auto x : E[cur])
		if (x != fa)
			if (ls[x])
			{
				end -> nxt = ls[x];
				end = ls[x] -> las;
			}
	ls[cur] = dum -> nxt;
	if (ls[cur]) ls[cur] -> las = end;
	while (!pq.empty()) pq.pop();
}

priority_queue<pii, vector<pii>, greater<pii> > PQ;

void solve()
{
	cen = mp(maxn, 0);
	dfs(1, 0);
	c = cen.se;
	dfs1(c, 0);
	if (ans > k || ((ans ^ k) & 1))
	{
		cout << "NO\n";
		return;
	}
	for (auto x : s)
	{
		dfs2(x, c, x);
		sort(all(que[x]));
		PQ.push(mp(a[x], x));
	}
	while (!PQ.empty())
	{
		auto x = PQ.top();
		PQ.pop();
		if (a[x.se] != x.fi) continue;
		if (ptr[x.se] == que[x.se].size()) continue;
		auto y = que[x.se][ptr[x.se]++];
		if (ans + (y.fi - 1) * 2 >= k)
		{
			int cur = y.se;
			b[y.se] -= 2;
			while (ans < k)
			{
				ans += 2;
				cur = f[cur];
			}
			b[cur] += 2;
			break;
		}
		b[y.se] -= 2;
		ans += (y.fi - 1) * 2;
		b[c] += 2;
		a[x.se] += 2;
		if (a[x.se] != sz[x.se])
			PQ.push(mp(a[x.se], x.se));
	}
	dfs3(c, 0);
	if (ans != k)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	dfs4(c, 0);
}

main()
{
	input();
	solve();
}