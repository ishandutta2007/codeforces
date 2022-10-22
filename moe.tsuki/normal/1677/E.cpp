#pragma GCC optimize("O3")
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
#define MEOW { cout << "meowwwww" << '\n'; system("pause"); }
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

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

const int maxn = 456789, mod = 1000000007, pool = 1234567;

#define fac_init() fact(maxn - 1, 1);
#define C(x,y) ((fact(x, 2) * fact(y, 3) % mod) * fact((x) - (y), 3) % mod)

int fact(int cur, int mode)
{
	static int f[maxn], g[maxn];
	if (mode == 1)
	{
		f[0] = 1;
		F1 (i, cur) f[i] = f[i - 1] * i % mod;
		g[cur] = 1;
		int a = f[cur], b = (mod - 2) << 1;
		while (b >>= 1)
		{
			if (b & 1) g[cur] = g[cur] * a % mod;
			a = a * a % mod;
		}
		for (int i = cur - 1; i >= 0; --i)
			g[i] = g[i + 1] * (i + 1) % mod;
		return 0;
	} else if (mode == 2) return f[cur];
	else return g[cur];
}

int n, q;
int a[maxn], app[maxn];
int T(lc), T(rc), T(c), T(d), T(e), T(f);
vector<pair<pii, pii>> qry[maxn];
vector<pair<pii, int>> evt[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F1 (i, n) cin >> a[i];
	F1 (i, q)
	{
		int l, r; cin >> l >> r;
		qry[r].emplace_back(mp(mp(l, r), mp(i, 1ll)));
		qry[l - 1].emplace_back(mp(mp(l, r), mp(i, -1ll)));
	}
}

int cnt;

int build(int l, int r)
{
	int cur = ++cnt;
	c[cur] = d[cur] = e[cur] = f[cur] = 0;
	if (l == r) 
	{
		lc[cur] = rc[cur] = 0;
		return cur;
	}
	int m = (l + r) / 2;
	lc[cur] = build(l, m);
	rc[cur] = build(m + 1, r);
	return cur;
}

void push(int t, int ls, int rs)
{
	e[lc[t]] += e[t];
	e[rc[t]] += e[t];
	f[lc[t]] += f[t];
	f[rc[t]] += f[t];
	// e[t] * now - f[t]
	c[lc[t]] += e[t] * ls;
	d[lc[t]] -= f[t] * ls;
	c[rc[t]] += e[t] * rs;
	d[rc[t]] -= f[t] * rs;
	e[t] = f[t] = 0;
}

void pull(int t)
{
	assert(e[t] == 0);
	assert(f[t] == 0);
	c[t] = c[lc[t]] + c[rc[t]];
	d[t] = d[lc[t]] + d[rc[t]];
}

int now;

void add(int t, int l, int r, int q, int p, int v)
{
	if (q > r || p < l) return;
	if (q <= l && r <= p)
	{
		e[t] += v;
		f[t] += now * v;
		c[t] += v * (r - l + 1);
		d[t] -= now * v * (r - l + 1); 
		// (e[t] * now - f[t]) * (r - l + 1)
		return;
	}
	int m = (l + r) / 2;
	push(t, m - l + 1, r - m);
	add(lc[t], l, m, q, p, v);
	add(rc[t], m + 1, r, q, p, v);
	pull(t);
}

int query(int t, int l, int r, int q, int p)
{
	if (p < q) return 0;
	if (q > r || p < l) return 0;
	if (q <= l && r <= p)
	{
		return c[t] * now + d[t];
	}
	int m = (l + r) / 2;
	push(t, m - l + 1, r - m);
	int ret = query(lc[t], l, m, q, p) + 
		query(rc[t], m + 1, r, q, p);
	pull(t);
	return ret;
}

vpii seg[maxn];
int lft[maxn], rgt[maxn];
int ans[1234567];

void solve()
{
	F1 (i, n) app[a[i]] = i;
	F1 (i, n) F1 (j, n / i)
		if (i == j) continue;
		else
			seg[i * j].pb(mp(min(app[i], app[j]), max(app[i], app[j])));
	stack<int> s;
	F1 (i, n) 
	{
		while (!s.empty())
		{
			if (a[i] < a[s.top()]) break;
			s.pop(); 
		}
		if (!s.empty()) lft[i] = s.top();
		s.push(i);
	}
	
	while (!s.empty()) s.pop();
	F1 (i, n) rgt[i] = n + 1;
	for (int i = n; i >= 1; --i)
	{
		while (!s.empty())
		{
			if (a[i] < a[s.top()]) break;
			s.pop(); 
		}
		if (!s.empty()) rgt[i] = s.top();
		s.push(i);
	}
	
	F1 (i, n)
	{
		sort(all(seg[i]));
		stack<pii> stk;
		for (auto x : seg[i])
		{
			while (!stk.empty())
			{
				if (stk.top().se < x.se) break;
				stk.pop();
			}
			stk.push(x);
		}
		pii last = mp(n + 1, n + 1);
		//dbg(i);
		while (!stk.empty())
		{
			auto x = stk.top();
			stk.pop();
			x.fi = min(x.fi, app[i]);
			x.se = max(x.se, app[i]);
			if (x.fi <= lft[app[i]]) continue;
			if (x.se >= rgt[app[i]]) continue;
			assert(x.fi <= last.fi);
			assert(x.se <= last.se);
			int yl = x.se;
			int yr = min(last.se - 1, rgt[app[i]] - 1);
			last = mp(x.fi, x.se);
			if (yl > yr) continue;
			evt[lft[app[i]]].pb(mp(mp(yl, yr), 1ll));
			evt[x.fi].pb(mp(mp(yl, yr), -1ll));
			//evt[yl].pb(mp(mp(lft[app[i]] + 1, x.fi), 1ll));
			//evt[yr].pb(mp(mp(lft[app[i]] + 1, x.fi), -1ll));
			//dbg(mp(lft[app[i]] + 1, x.fi));
			//dbg(mp(yl, yr));
		}
	}
	cnt = 0;
	build(1, n);
	F (i, n + 2)
	{
		/*dbg(i);
		for (auto x : evt[i])
		{
			dbgg(x.fi);
			dbg(x.se);
		}
		dbg(i);
		for (auto x : qry[i])
		{
			dbgg(x.fi);
			dbg(x.se);
		}*/
		now = i;
		for (auto x : evt[i])
		{
			add(1, 1, n, x.fi.fi, x.fi.se, x.se);
		}
		for (auto x : qry[i])
		{
			// 
			ans[x.se.fi] += x.se.se * query(1, 1, n, x.fi.fi, x.fi.se);
		}
	}
	F1 (i, q) cout << ans[i] << '\n';
}

main()
{
	fac_init();
	input();
	solve();
}