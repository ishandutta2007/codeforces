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

const int maxn = 123456, mod = 1000000007, LOG = 18;

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

int n, q;
int a[maxn], b[maxn], z[maxn];
int mx[maxn][LOG], mn[maxn][LOG];
int c[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F1 (i, n) cin >> a[i];
	F1 (i, n) cin >> b[i];
}

int mnn(int l, int r)
{
	int len = r - l + 1;
	return min(mn[l][z[len]], mn[r - (1 << z[len]) + 1][z[len]]);
}

int mxx(int l, int r)
{
	int len = r - l + 1;
	return max(mx[l][z[len]], mx[r - (1 << z[len]) + 1][z[len]]);
}

void solve()
{
	F1 (i, n) b[i] -= a[i];
	F1 (i, n) c[i] = b[i];
	F1 (i, n) c[i] += c[i - 1];
	F1 (i, n) mx[i][0] = c[i];
	z[1] = 0;
	for (int i = 2; i < maxn; ++i)
		z[i] = z[i / 2] + 1;
	for (int i = 1; i < LOG; ++i)
		F1 (j, n)
			mx[j][i] = max(mx[j][i - 1], mx[min(j + (1 << (i - 1)), n)][i - 1]);
	F1 (i, n) mn[i][0] = c[i];
	for (int i = 1; i < LOG; ++i)
		F1 (j, n)
			mn[j][i] = min(mn[j][i - 1], mn[min(j + (1 << (i - 1)), n)][i - 1]);
	while (q --> 0)
	{
		int l, r; cin >> l >> r;
		if (c[r] != c[l - 1])
		{
			cout << "-1\n";
			continue;
		}
		if (mnn(l, r) < c[l - 1])
		{
			cout << "-1\n";
			continue;
		}
		cout << mxx(l, r) - c[l - 1] << '\n';	
	}
	// checksum
}

main()
{
	fac_init();
	input();
	solve();
}