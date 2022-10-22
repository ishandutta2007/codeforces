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

const int maxn = 2345678, mod = 1000000007;

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

int n;
int a[maxn];
int inv[maxn];
int win[maxn], scc[maxn];
int w[23][23];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	F1 (i, maxn - 1) inv[i] = fact(i - 1, 2) * fact(i, 3) % mod;
	F1 (i, n) F1 (j, n) w[i][j] = a[i] * inv[a[i] + a[j]] % mod;
	int ans = 0;
	F1 (i, (1 << n) - 1)
	{
		scc[i] = 1;
		int sub = i;
		do
		{
			int out = 1;
			if (sub != i)
			{
				vi p, q;
				F1 (j, n) if (sub & (1 << (j - 1))) p.pb(j);
				F1 (j, n) if ((i & (~sub)) & (1 << (j - 1))) q.pb(j);
				for (auto j : p) for (auto k : q)
					out = out * w[j][k] % mod;
				scc[i] = (scc[i] - out * scc[sub] % mod + mod) % mod; 
			}
			sub = (sub - 1) & i;
		} while (sub != i);
		vi p, q;
		int out = 1;
		F1 (j, n) if (i & (1 << (j - 1))) p.pb(j); else q.pb(j);
		for (auto j : p) for (auto k : q)
			out = (out * w[j][k]) % mod;
		win[i] = out * scc[i] % mod;
		int cnt = 0;
		F (j, n) if (i & (1 << j)) ++cnt;
		ans = (ans + cnt * win[i] % mod) % mod;
	}
	cout << ans << '\n';
}

main()
{
	fac_init();
	input();
	solve();
}