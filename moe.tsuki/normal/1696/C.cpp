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

const int maxn = 123456, mod = 1000000007;

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

int a[maxn], b[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		F1 (i, n) cin >> a[i];
		int k; cin >> k;
		F1 (i, k) cin >> b[i];
		vpii v, vv;
		F1 (i, n)
		{
			int cur = 1;
			while (a[i] % m == 0)
			{
				cur *= m;
				a[i] /= m;
			}
			if (v.size() == 0) v.pb(mp(a[i], cur));
			else if (v[v.size() - 1].fi == a[i]) v[v.size() - 1].se += cur;
			else v.pb(mp(a[i], cur));
		}
		F1 (i, k)
		{
			int cur = 1;
			while (b[i] % m == 0)
			{
				cur *= m;
				b[i] /= m;
			}
			if (vv.size() == 0) vv.pb(mp(b[i], cur));
			else if (vv[vv.size() - 1].fi == b[i]) vv[vv.size() - 1].se += cur;
			else vv.pb(mp(b[i], cur));
		}
		if (v == vv) cout << "Yes\n";
		else cout << "No\n";
	}
}

main()
{
	fac_init();
	input();
	solve();
}