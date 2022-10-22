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

void solve()
{
	while (t --> 0)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		string s; cin >> s;
		int n = s.length();
		int A = 0;
		for (auto x : s) if (x == 'A') ++A;
		if (a + c + d != A || b + c + d != n - A)
		{
			cout << "NO\n";
			continue;
		}
		int cur = 0, last = 0, u = 0;
		vi x, y;
		F (i, n)
		{
			if (s[i] == 'A' + 'B' - last) ++cur;
			else
			{
				if (cur & 1) u += cur / 2;
				else if (last == 'B') x.pb(cur / 2);
				else y.pb(cur / 2);
				cur = 1;
			}
			last = s[i];
		}
		if (cur & 1) u += cur / 2;
		else if (last == 'B') x.pb(cur / 2);
		else y.pb(cur / 2);
		cur = 1;
		//dbg(x); dbg(y);
		sort(all(x));
		sort(all(y));
		
		for (auto cur : x)
		{
			if (c >= cur) c -= cur;
			else if (cur) u += cur - 1; 
		}
		for (auto cur : y)
		{
			if (d >= cur) d -= cur;
			else if (cur) u += cur - 1; 
		}
		if (c + d > u) cout << "NO\n";
		else cout << "YES\n";
	} 
}

main()
{
	fac_init();
	input();
	solve();
}