#pragma GCC optimize("Ofast,no-stack-protector")
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

const int maxn = 234567, mod = 1000000007;

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

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

int x[maxn], p[maxn], ans[maxn], cer[maxn];

vector<pair<int, pii>> evt, evt2;

#define lowbit(x) ((x) & (-x))

int bit[1234567];

void add(int p, int x)
{
	while (p < maxn)
	{
		bit[p] += x;
		p += lowbit(p);
	}
}

int qry(int p)
{
	int r = 0;
	while (p)
	{
		r += bit[p];
		p -= lowbit(p);
	}
	return r;
}

void solve()
{
	while (t --> 0)
	{
		evt.clear();
		evt2.clear();
		int n, m; cin >> n >> m;
		F1 (i, n)
		{
			cin >> x[i] >> p[i];
			evt.pb(mp(x[i] - p[i], mp(1, -x[i] + p[i])));
			evt.pb(mp(x[i], mp(-2, 2 * x[i])));
			evt.pb(mp(x[i] + p[i], mp(1, -x[i] - p[i])));
			evt.pb(mp(x[i], mp(7122, i)));
		}
		//F1 (i, n) v.pb(mp(x[i], i));
		sort(all(evt));
		int a = 0, b = 0;
		for (auto c : evt)
		{
			if (c.se.fi == 7122)
			{
				ans[c.se.se] = a * x[c.se.se] + b;
			} else
			{
				a += c.se.fi, b += c.se.se;
			}
		}
		//F1 (i, n) dbg(ans[i]);
		int cur = 0;
		vi fu;
		F1 (i, n)
		{
			if (ans[i] > m)
			{
				int need = ans[i] - m;
				//dbg(mp(i, need));
				++cur;
				evt2.pb(mp(x[i] + need, mp(-71222222, -x[i] + need)));
				fu.pb(-x[i] + need);
			}
		}
		F1 (i, n)
		{
			evt2.pb(mp(x[i] + p[i], mp(i, -x[i] + p[i])));
			fu.pb(-x[i] + p[i]);
		}
		sort(all(fu));
		fu.resize(unique(all(fu)) - fu.begin());
		sort(all(evt2));
		F1 (i, n) cer[i] = 0;
		for (auto c : evt2)
		{
			if (c.se.fi == -71222222)
				add(lower_bound(all(fu), c.se.se) - fu.begin() + 1, 1);
			else
				cer[c.se.fi] += qry(lower_bound(all(fu), c.se.se) - fu.begin() + 1);
		}
		for (auto c : evt2)
		{
			if (c.se.fi == -71222222)
				add(lower_bound(all(fu), c.se.se) - fu.begin() + 1, -1);
		}
		//F1 (i, n) dbg(cer[i]);
		F1 (i, n) cout << "01"[cer[i] >= cur];
		cout << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}