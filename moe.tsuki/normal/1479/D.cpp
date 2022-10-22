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
#define int long long
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

const int maxn = 345678, mod = 1000000009, pool = 8000000;
int n, q;
int a[maxn];
int u, v, w, x;
vector<int> E[maxn];
int in[maxn], out[maxn], pa[maxn][20];
int T(lc), T(rc), T(num);
int ran[maxn];
int rt[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F1 (i, n) cin >> a[i];
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

int myrand()
{
	return ((rand() * rand() + rand()) % mod) * ((rand() * rand() + rand()) % mod) % mod;
}

int cnt;

void dfs(int cur)
{
	in[cur] = ++cnt;
	for (auto x : E[cur]) if (!in[x])
	{
		pa[x][0] = cur;
		dfs(x);
	}
	out[cur] = cnt;
}

bool anc(int a, int b)
{
	return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b)
{
	if (anc(b, a)) return b;
	for (int i = 19; i >= 0; --i)
		if (!anc(pa[b][i], a)) b = pa[b][i];
	return pa[b][0];
}

int build(int l, int r)
{
	int cur = ++cnt;
	if (l == r) return cur;
	int m = (l + r) / 2;
	lc[cur] = build(l, m);
	rc[cur] = build(m + 1, r);
	return cur;
}

int modify(int cur, int q, int p, int l, int val)
{
	if (q == p) 
	{
		num[++cnt] = num[cur] ^ val;
		return cnt;
	}
	int ret = ++cnt;
	int m = (q + p) / 2;
	if (l <= m)
	{
		rc[ret] = rc[cur];
		num[ret] = num[cur] ^ val;
		lc[ret] = modify(lc[cur], q, m, l, val);
	} else
	{
		lc[ret] = lc[cur];
		num[ret] = num[cur] ^ val;
		rc[ret] = modify(rc[cur], m + 1, p, l, val);
	}
	return ret;
}

void dfs2(int cur, int t)
{
	rt[cur] = modify(t, 1, n, a[cur], ran[a[cur]]);
	for (auto x : E[cur])
		if (anc(cur, x)) dfs2(x, rt[cur]);
}

bool query(int q, int p, int l, int r)
{
	//dbgg(u); dbgg(v); dbgg(w); dbg(x);
	if (p < l || r < q) return false;
	if (q >= l && p <= r)
	{
		int U = u, V = v, W = w, X = x;
		if (num[u] ^ num[v] ^ num[w] ^ num[x])
		{
			if (q == p)
			{
				cout << q << '\n';
				return true;
			} else
			{
				int m = (q + p) / 2;
				u = lc[U], v = lc[V], w = lc[W], x = lc[X];
				if (query(q, m, l, r)) return true;
				u = rc[U], v = rc[V], w = rc[W], x = rc[X];
				if (query(m + 1, p, l, r)) return true;
			}
		}
		return false;
	}
	int m = (q + p) / 2;
	int U = u, V = v, W = w, X = x;
	u = lc[U], v = lc[V], w = lc[W], x = lc[X];
	if (query(q, m, l, r)) return true;
	u = rc[U], v = rc[V], w = rc[W], x = rc[X];
	if (query(m + 1, p, l, r)) return true;
	return false;
}

void solve()
{
	in[0] = -mod;
	out[0] = mod;
	srand(time(NULL));
	F1 (i, n) ran[i] = myrand();
	//F1 (i, n) dbg(ran[i]);
	dfs(1);
	//F1 (i, n) dbg(pa[i][0]);
	F1 (i, 19)
		F1 (j, n)
			pa[j][i] = pa[pa[j][i - 1]][i - 1];
	cnt = 0;
	build(1, n);
	dfs2(1, 1);		
	while (q --> 0)
	{
		int l, r; cin >> u >> v >> l >> r;
		w = lca(u, v);
		x = pa[w][0];
		if (w == 1) x = 0;
		//dbgg(w);
		//dbg(x);
		u = rt[u];
		v = rt[v];
		w = rt[w];
		x = rt[x];
		if (!query(1, n, l, r)) cout << -1 << '\n';
	}
}

main()
{
	input();
	solve();
}