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

const int maxn = 2345, mod = 1000000007;

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
int a[maxn], b[maxn];

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
		bool ok = true;
		F1 (i, n) if ((a[i] ^ i) & 1) ok = false; 
		vi ans;
		//for (int j = 2; j <= n; j += 2)
		//	if (abs(a[j] - a[j + 1]) != 1) ok = false;
		if (!ok) { cout << "-1\n"; continue; }
		for (int i = n; i >= 1; i -= 2)
		{
			if (i == 1) break;
			int p;
			F1 (j, n) if (a[j] == i) p = j;
			int q;
			F1 (j, n) if (a[j] == i - 1) q = j;
			ans.pb(p);
			reverse(a + 1, a + p + 1);
			if (p > q) q = p + 1 - q;
			ans.pb(q - 1);
			reverse(a + 1, a + q);
			ans.pb(q + 1);
			reverse(a + 1, a + q + 2);
			ans.pb(3);
			reverse(a + 1, a + 4);
			ans.pb(i); 
			reverse(a + 1, a + i + 1);
			//F1 (i, n) cout << a[i] << ' ';
			//cout << '\n';
		}
		cout << ans.size() << '\n';
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}