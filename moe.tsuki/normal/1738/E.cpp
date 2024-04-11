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

const int maxn = 234567, mod = 998244353;

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
int a[maxn];
int pre[maxn], suf[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		F1 (i, n) pre[i] = pre[i - 1] + a[i];
		suf[n + 1] = 0;
		for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i];
		map<int, int> ty;
		map<int, int> p;
		map<int, int> s;
		F1 (i, n) ++p[pre[i]];
		F1 (i, n) ++s[suf[i]];
		//for (auto x : p)
		//	dbg(mp(x.fi, x.se));
		//for (auto x : s)
		//	dbg(mp(x.fi, x.se));
		int ans = 1;
		for (auto x : p)
		{
			//dbg(x.fi);
			if (x.fi +x.fi < pre[n])
			{
				//dbg(n);
				//dbg(x.fi);
				//dbg(mp(x.se, s[x.fi]));
				ans = ans * C(x.se + s[x.fi], x.se) % mod;
			} else if (x.fi == pre[n] / 2)
			{
				F1 (j, x.se) ans = ans * 2 % mod;
			}
		}
		if (pre[n] == 0) ans = ans * 499122177 % mod;
		cout << ans << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}