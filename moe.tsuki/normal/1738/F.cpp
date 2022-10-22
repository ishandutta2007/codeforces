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

int t;

void input()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;	
}

int ask(int x)
{
	cout << "? " << x << '\n';
	fflush(stdout);
	int r; cin >> r;
	return r;
}

int d[maxn];
int p[maxn];
bool vis[maxn];

int f(int x)
{
	if (p[x] == x) return x;
	return p[x] = f(p[x]);
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		vpii v;
		F1 (i, n) cin >> d[i];
		F1 (i, n) v.pb(mp(d[i], i));
		sort(all(v));
		reverse(all(v));
		F1 (i, n) vis[i] = false;
		F1 (i, n)	p[i] = i;
		for (auto x : v)
		{
			if (vis[x.se]) continue;
			int cur = x.fi;
			vis[x.se] = true;
			while (cur --> 0)
			{
				int u = ask(x.se);
				if (vis[u])
				{
					p[x.se] = f(u);
					break;
				} else
				{
					vis[u] = true;
					p[u] = x.se;
				}
			}
		}
		cout << '!';
		F1 (i, n) cout << ' ' << f(i);
		cout << '\n';
		fflush(stdout);
	}
}

main()
{
	fac_init();
	input();
	solve();
}