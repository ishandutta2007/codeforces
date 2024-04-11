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

int dp[maxn];

void solve()
{
	dp[0] = 0;
	dp[1] = 0; dp[2] = dp[3] = 1;
	for (int i = 1; i <= 100; ++i)
	{
		map<int, int> app;
		if (i >= 4)
		{
			for (int j = 0; j <= i - 2; ++j)
				++app[dp[j] ^ dp[i - 2 - j]];
			//dbg(i);
			//for (auto x : app) dbg(mp(x.fi, x.se));
			while (app[dp[i]] > 0) ++dp[i];
		}
		//cout << dp[i] << ' ';
		//if (i % 34 == 0) cout << '\n';
	}
	while (t --> 0)
	{
		int n; cin >> n;
		string s; cin >> s;
		int r = 0, b = 0;
		for (auto x : s) if (x == 'R') ++r; else ++b;
		if (r > b)
		{
			cout << "Alice\n";
		} else if (b >= r + 1)
		{
			cout << "Bob\n";
		} else
		{
			// b - 1 <= r <= b
			int cur = 1;
			vi v;
			F1 (i, n - 1)
			{
				if (s[i] == s[i - 1])
				{
					if (cur >= 2) v.pb(cur);
					cur = 1;
				} else ++cur;
			}
			if (cur >= 2) v.pb(cur);
			/*sort(all(v));
			dbg(b - r);
			dbg(v);
			cout << "Not Sure\n";*/
			int ans = 0;
			for (auto x : v)
			{
				if (x > 100) x -= (x - 100 + 33) / 34 * 34;
				if (x > 100) x -= 34;
				ans ^= dp[x];
			}
			if (ans > 0) cout << "Alice\n";
			else cout << "Bob\n";
		}
	}
}

main()
{
	fac_init();
	input();
	solve();
}