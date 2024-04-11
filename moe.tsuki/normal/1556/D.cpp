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

int n, k;

void input()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
}

int o(int x, int y)
{
	cout << "or " << x << ' ' << y << '\n';
	fflush(stdout);
	int r; cin >> r; return r;
}

int a(int x, int y)
{
	cout << "and " << x << ' ' << y << '\n';
	fflush(stdout);
	int r; cin >> r; return r;
}

int c[maxn];

void solve()
{
	int z = o(1, 2);
	z += a(1, 2);
	int y = o(1, 3);
	y += a(1, 3);
	int x = o(2, 3);
	x += a(2, 3);
	c[1] = (-x + y + z) / 2;
	c[2] = ( x - y + z) / 2;
	c[3] = ( x + y - z) / 2;
	//dbg(c[1]);dbg(c[2]);dbg(c[3]);
	for (int i = 4; i <= n; ++i)
		c[i] = o(1, i) + a(1, i) - c[1];
	sort(c + 1, c + n + 1);
	cout << "finish " << c[k] << '\n';
	fflush(stdout);
}

main()
{
	fac_init();
	input();
	solve();
}