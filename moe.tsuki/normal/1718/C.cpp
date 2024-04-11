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
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

int a[maxn];
bool p[maxn];
map<int, int> fu;
vi sum[10];

void solve()
{
	while (t --> 0)
	{
		fu.clear();
		int n, q; cin >> n >> q;
		F1 (i, n) cin >> a[i];
		F1 (i, n) p[i] = true;
		vi v;
		F1 (i, n) if (i == 1) continue;
		else
		{
			if (p[i])
			{
				if (n % i == 0 && n != i) v.pb(i);
				for (int j = i + i; j <= n; j += i)
					p[j] = false;
			}
		}
		int tot = 0;
		F1 (i, n) tot += a[i];
		F (i, v.size()) v[i] = n / v[i];
		F (i, v.size())
		{
			//dbg(v[i]);
			sum[i].clear();
			F (j, v[i])
			{
				int cur = 0;
				int nm = 0;
				for (int k = j; k <= n; k += v[i])
				{
					if (k > 0)
					{
						cur += a[k];
						++nm;
					}
				}
				//dbg(n);
				//dbg(v[i]);
				//dbg(j);
				//dbg(nm);
				assert(p[nm]);
				sum[i].pb(cur);
				++fu[-cur * v[i]];
			}
		}
		{
			int ans = tot;
			if (fu.size()) ans = max(ans, -fu.begin() -> fi);
			cout << ans << '\n';
		}
		//for (auto x : fu) dbg(mp(x.fi, x.se));
		while (q --> 0)
		{
			int x, y; cin >> x >> y;
			int del = y - a[x];
			a[x] = y;
			tot += del;
			F (i, v.size())
			{
				//dbg(sum[i][x % v[i]]);
				--fu[-sum[i][x % v[i]] * v[i]];
				sum[i][x % v[i]] += del;
				++fu[-sum[i][x % v[i]] * v[i]];
			}
			//dbg("QQ");
			while (fu.size() && fu.begin() -> second == 0)
				fu.erase(fu.begin());
			int ans = tot;
			if (fu.size()) ans = max(ans, -fu.begin() -> fi);
			cout << ans << '\n';
		}
	}
}

main()
{
	fac_init();
	input();
	solve();
}