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

int a[maxn];

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		int p, q = 0;
		vi f, u;
		F1 (i, n) if (a[i] & 1)
		{
			++q;
		 	f.pb(i);
		} else u.pb(i);
		p = n - q;
		int ans = -2;
		{
			vi r, s;
			F1 (i, n)
			{
				if (i & 1) r.pb(i);
				else s.pb(i); 
			}
			if (r.size() == p && s.size() == q)
			{
				int cur = 0;
				F (i, p) cur = cur + abs(r[i] - u[i]);
				F (i, q) cur = cur + abs(s[i] - f[i]); 
				if (ans == -2) ans = cur;
				else ans = min(ans, cur);
			}
		}
		{
			vi r, s;
			F1 (i, n)
			{
				if (i & 1) s.pb(i);
				else r.pb(i); 
			}
			if (r.size() == p && s.size() == q)
			{
				int cur = 0;
				F (i, p) cur = cur + abs(r[i] - u[i]);
				F (i, q) cur = cur + abs(s[i] - f[i]); 
				if (ans == -2) ans = cur;
				else ans = min(ans, cur);
			}
		}
		cout << ans / 2 << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}