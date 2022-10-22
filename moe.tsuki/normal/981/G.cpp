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

typedef pair<pair<int, int>, int> seg;

const int maxn = 234567, pool = 1234567, mod = 998244353;
int n, q, cnt;
int T(lc), T(rc), T(sum), T(mtag), T(ptag);
set<seg> line[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
}

int build(int l, int r)
{
	int cur = ++cnt;
	if (l == r) 
	{
		sum[cur] = 0;
		mtag[cur] = 1;
		ptag[cur] = 0;
		return cur;
	}
	int m = (l + r) >> 1;
	lc[cur] = build(l, m);
	rc[cur] = build(m + 1, r);
	return cur;
}

void app(int cur, int len, int a, int b)
{
	sum[cur] = (sum[cur] * a) % mod;
	sum[cur] = (sum[cur] + (len * b) % mod) % mod;
	mtag[cur] = (mtag[cur] * a) % mod; 
	ptag[cur] = ((ptag[cur] * a) + b) % mod;
}

void pull(int cur)
{
	sum[cur] = (sum[lc[cur]] + sum[rc[cur]]) % mod;
}

void add(int cur, int q, int p, int l, int r, int x)
{
	if (p < l || r < q) return;
	if (l <= q && p <= r) 
	{
		app(cur, p - q + 1, 1, x);
		return; 
	}
	int m = (q + p) >> 1;
	app(lc[cur], m - q + 1, mtag[cur], ptag[cur]);
	app(rc[cur], p - m, mtag[cur], ptag[cur]);
	add(lc[cur], q, m, l, r, x);
	add(rc[cur], m + 1, p, l, r, x);
	mtag[cur] = 1; ptag[cur] = 0;
	pull(cur);
}

void mul(int cur, int q, int p, int l, int r, int x)
{
	if (p < l || r < q) return;
	if (l <= q && p <= r) 
	{
		app(cur, p - q + 1, x, 0);
		return; 
	}
	int m = (q + p) >> 1;
	app(lc[cur], m - q + 1, mtag[cur], ptag[cur]);
	app(rc[cur], p - m, mtag[cur], ptag[cur]);	
	mul(lc[cur], q, m, l, r, x);
	mul(rc[cur], m + 1, p, l, r, x);
	mtag[cur] = 1; ptag[cur] = 0;
	pull(cur);
}

int query(int cur, int q, int p, int l, int r)
{
	if (p < l || r < q) return 0;
	if (l <= q && p <= r) 
	{
		return sum[cur]; 
	}
	int ret = 0;
	int m = (q + p) >> 1;
	app(lc[cur], m - q + 1, mtag[cur], ptag[cur]);
	app(rc[cur], p - m, mtag[cur], ptag[cur]);	
	ret = query(lc[cur], q, m, l, r);
	ret = (ret + query(rc[cur], m + 1, p, l, r)) % mod;
	mtag[cur] = 1; ptag[cur] = 0;
	pull(cur);
	return ret;
}

void solve()
{
	F1 (i, n) line[i].insert(mp(mp(1, n), 0));
	build(1, n);
	F1 (i, q)
	{
		int t; cin >> t;
		if (t == 1)
		{
			int l, r, x; cin >> l >> r >> x;
			add(1, 1, n, l, r, 1);
			//dbg("nani");
			auto lcon = line[x].lower_bound(mp(mp(l + 1, 0), 0));			
			auto rcon = line[x].lower_bound(mp(mp(r + 1, 0), 0));
			--lcon; --rcon;
			//dbgg(lcon->fi); dbg(lcon->se);
			//dbg("haha");
			//dbgg(rcon->fi); dbg(rcon->se);
			
			++rcon;
			
			for (auto cur = lcon; cur != rcon; ++cur)
			{//dbgg(cur->fi); dbg(cur->se);
				if (cur -> se == 1) 
				{
					int f = max(cur -> fi.fi, l);
					int t = min(cur -> fi.se, r);
					//dbg(f); dbg(t);
					add(1, 1, n, f, t, mod - 1);
					mul(1, 1, n, f, t, 2);
					
				}
			}
			
			auto L = *lcon;
			auto R = *(--rcon);
			++rcon;
			//dbg("fuckyou");
			line[x].erase(lcon, rcon);//dbg("ala");
			line[x].insert(mp(mp(l, r), 1)); 
			if (L.fi.fi <= l - 1) line[x].insert(mp(mp(L.fi.fi, l - 1), L.se));
			if (r + 1 <= R.fi.se) line[x].insert(mp(mp(r + 1, R.fi.se), R.se));
			//dbg(x); for (auto cur : line[x]) { dbgg(cur.fi); dbg(cur.se); }
			//dbg("HELLO");
			//dbg(query(1, 1, n, 1, n));
		} else
		{
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
			//dbg(query(1, 1, n, 1, n));
		}
	}
}

main()
{
	input();
	solve();
}