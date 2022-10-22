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

int a[maxn], b[maxn];
vi v[maxn];
pii e[maxn];
int vis[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		F1 (i, n) cin >> a[i];
		F1 (i, n) cin >> b[i];
		F1 (i, n) a[i] += a[i - 1];
		F1 (i, n) b[i] += b[i - 1];
		F1 (i, n) a[i] -= b[i];
		F (i, n + 1) v[i].clear();
		F1 (i, m)
		{
			int l, r; cin >> l >> r;
			v[l - 1].pb(i);
			v[r].pb(i);
			e[i] = mp(l, r);
			//if (a[r] - a[l - 1] == b[r] - b[l - 1])
			//	++d[l], --d[r + 1];
		}
		F1 (i, m) vis[i] = 0;
		set<int> s;
		queue<pii> q;
		F1 (i, n) s.insert(i);
		//F1 (i, m) dbg(vis[m]);
		F (i, n + 1)
		{
			if (a[i] == 0)
			{
				//dbg(i);
				for (auto x : v[i])
				{
					++vis[x];
					assert(vis[x] <= 2);
					if (vis[x] == 2)
						q.push(e[x]);
				}
				s.erase(i);
			}
		}
		//F1 (i, m) dbg(vis[m]);
		while (!q.empty())
		{
			auto x = q.front();
			q.pop();
			while (true)
			{
				auto y = s.lower_bound(x.fi - 1);
				if (y == s.end()) break;
				if (*y > x.se) break;
				assert(*y != x.fi - 1);
				assert(*y != x.se);
				//dbg(*y);
				for (auto x : v[*y])
				{
					++vis[x];
					assert(vis[x] <= 2);
					if (vis[x] == 2)
						q.push(e[x]);
				}
				s.erase(y);
			}
		}
		if (s.empty()) cout << "YES\n";
		else cout << "NO\n";
		/*F1 (i, n) if (a[i] - a[i - 1] == b[i] - b[i - 1])
			++d[i], --d[i + 1];
		F1 (i, n) d[i] += d[i - 1];
		bool ok = true;
		F1 (i, n) if (d[i] < 1) ok = false;
		if (ok) cout << "YES\n";
		else cout << "NO\n";*/
	}
}

main()
{
	fac_init();
	input();
	solve();
}