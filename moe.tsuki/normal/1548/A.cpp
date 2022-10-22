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

int n, m, q;
set<int> E[maxn];
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m)
	{
		int x, y; cin >> x >> y;
		E[x].insert(y);
		E[y].insert(x);
		
	}
}

void solve()
{
	int ans = 0;
	F1 (i, n)
	{
		if (E[i].lower_bound(i) == E[i].end()) a[i] = 1;
		ans += a[i];
	}
	cin >> q;
	while (q --> 0)
	{
		int t, x, y; cin >> t;
		if (t == 3)
		{
			cout << ans << '\n';
			continue;
		}
		cin >> x >> y;
		if (t == 1)
		{
			E[x].insert(y);
			E[y].insert(x);	
		} else
		{
			E[x].erase(y);
			E[y].erase(x);
		}
		ans -= a[x];
		ans -= a[y];
		if (E[x].lower_bound(x) == E[x].end()) a[x] = 1; else a[x] = 0;
		if (E[y].lower_bound(y) == E[y].end()) a[y] = 1; else a[y] = 0;
		ans += a[x];
		ans += a[y];
		//cout << ans << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}