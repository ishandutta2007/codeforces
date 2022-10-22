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
int t;
int f[maxn], g[maxn];
int w[maxn];

int power(int a, int b)
{
	if (b == 0) return 1;
	int ret = power(a * a % mod, b / 2);
	if (b & 1) ret = ret * a % mod;
	return ret;
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	f[0] = 1;
	F1 (i, maxn - 1) f[i] = f[i - 1] * i % mod;
	g[maxn - 1] = power(f[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; --i)
		g[i] = g[i + 1] * (i + 1) % mod;
	while (t --> 0)
	{
		int n, k; cin >> n >> k;
		w[0] = 1;
		F1 (i, n)
		{
			if (n - 1 - (i - 1) * k < 0) w[i] = 0;
			else w[i] = (f[n - 1 - (i - 1) * k + i] * g[i] % mod) * g[n - 1 - (i - 1) * k] % mod;
		}
		int ans = 0;
		F (i, n + 1)
		{
			ans = (ans + (w[i] * f[i] % mod) * f[n - i] % mod) % mod;
		}
		cout << ans * g[n] % mod << '\n';
	}
}

main()
{
	input();
	solve();
}