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

const int maxn = 234567, LOG = 20, mod = 1000000007;

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
int g[maxn][LOG];

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
		for (int i = n; i >= 2; --i) a[i] -= a[i - 1];
		--n;
		F1 (i, n) g[i][0] = abs(a[i + 1]);
		//dbg(n);
		//F1 (i, n) dbg(g[i][0]);
		for (int i = 1; i < LOG; ++i)
			for (int j = 1; j <= n; ++j)
				g[j][i] = __gcd(g[j][i - 1], g[min(n, j + (1 << (i - 1)))][i - 1]);
		int ans = 0;
		F1 (i, n)
		{
			int cur = i + 1;
			int d = LOG;
			int gg = g[i][0];
			while (d --> 0)
			{
				if (cur + (1 << d) - 1 <= n && __gcd(gg, g[cur][d]) != 1)
				{
					gg = __gcd(gg, g[cur][d]);
					cur = cur + (1 << d);
				}
			}
			ans = max(ans, cur - i);
		}
		int ok = false;
		F1 (i, n) if (g[i][0] != 1) ok = true;
		if (ok) cout << ans + 1 << '\n';
		else cout << 1 << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}