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

const int maxn = 567890, mod = 1000000007;

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

int a[maxn], cnt[maxn];
vi fu;

void solve()
{
	while (t --> 0)
	{
		fu.clear();
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		int mx = 0;
		F1 (i, n - 1) ++cnt[a[i + 1] - a[i]];
		F1 (i, n - 1) fu.pb(a[i + 1] - a[i]);
		sort(all(fu));
		fu.resize(unique(all(fu)) - fu.begin());
		vpii v;
		for (auto x : fu)
			v.pb(mp(x, cnt[x]));
		F1 (i, n - 1) --cnt[a[i + 1] - a[i]];
		/*F1 (i, n - 1)
		{
			mx = max(mx, a[i + 1] - a[i]);
			++cnt[a[i - 1] - a[i]];
		}*/
		/*F (i, mx + 1)
		{
			if (cnt[i] > 0) v.pb(mp(i, cnt[i]));
		}*/
		vpii vv;
		//dbg(v);
		F (t, n - 2)
		{
			//int cnt = 0;
			vv.clear();
			fu.clear();
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i].se > 1)
				{
					fu.pb(0);
					cnt[0] += v[i].se - 1;
				}
				if (i + 1 < v.size())
				{
					fu.pb(v[i + 1].fi - v[i].fi);
					++cnt[v[i + 1].fi - v[i].fi];
				}
			}
			sort(all(fu));
			fu.resize(unique(all(fu)) - fu.begin());
			for (auto x : fu)
				vv.pb(mp(x, cnt[x]));
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i].se > 1)
				{
					fu.pb(0);
					cnt[0] -= v[i].se - 1;
				}
				if (i + 1 < v.size())
				{
					fu.pb(v[i + 1].fi - v[i].fi);
					--cnt[v[i + 1].fi - v[i].fi];
				}
			}
			v = vv;
			//dbg(v);
		}
		cout << v[0].fi << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}