#pragma GCC optimize("O3")
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

const int maxn = 5678, mod = 1000000007;

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
int bit[maxn][2];

#define lowbit(x) (x & (-x))

void add(int x, int y, int tt)
{
	while (x < maxn)
	{
		bit[x][tt] += y;
		x += lowbit(x);
	}
}

int qry(int x, int tt)
{
	int ret = 0;
	while (x)
	{
		ret += bit[x][tt];
		x -= lowbit(x);
	}
	return ret;
}
void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		int ans = 0;
		for (int i = 2; i <= n - 2; ++i)
		{
			add(a[i - 1], 1, 0);
			for (int j = n - 1; j > i; --j)
			{
				add(a[j + 1], 1, 1);
				int x = qry(a[j], 0);
				int y = qry(a[i], 1);
				ans += x * y;
			}
			
			for (int j = n - 1; j > i; --j)
			{
				add(a[j + 1], -1, 1);
			}
		}
		for (int i = 2; i <= n - 2; ++i)
		{
			add(a[i - 1], -1, 0);
		}
		cout << ans << '\n';
	}
	
}

main()
{
	fac_init();
	input();
	solve();
}