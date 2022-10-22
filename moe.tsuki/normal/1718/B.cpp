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

int a[maxn], b[maxn], cnt[maxn];

void solve()
{
	int x = 1, y = 1, z;
	vi v;
	while (y <= 1000000000000000000ll)
	{
		v.pb(y);
		z = x + y;
		x = y;
		y = z;
	}
	reverse(all(v));
	while (t --> 0)
	{
		int k; cin >> k;
		/*if (k == 1)
		{
			bool ok = false;
			int n; cin >> n;
			for (auto x : v) if (n == x) ok = true;
			if (ok) cout << "YES\n";
			else cout << "NO\n";
			continue; 
		}*/
		bool ok = false;
		F1 (i, k) cin >> a[i];
		
		F1 (i, k) b[i] = a[i];
		F (i, v.size()) cnt[i] = 0;
		int oto = 0;
		F1 (i, k)
				F (j, v.size())
				{
					if (b[i] >= v[j])
					{
						++cnt[j];
						--oto;
						b[i] -= v[j];
					}
				}
		
		F1 (nm, k)
		{
			b[nm] = a[nm];
			F (j, v.size())
				{
					//if (v[j] == 1 && b[i] >= 1 && i == nm) fu = true;
					if (b[nm] >= v[j])
					{
						--cnt[j];
						++oto;
						b[nm] -= v[j];
					}
				}
			bool fu = false;
			b[nm] = a[nm] - 1;
			F (j, v.size())
				{
					if (v[j] == 1 && b[nm] >= 1) fu = true;
					if (b[nm] >= v[j])
					{
						++cnt[j];
						--oto;
						b[nm] -= v[j];
					}
				}
			//dbg(v);
			int tot = 0;
			//for (int i = v.size() - 1; i >= 0; --i)
			//	cout << cnt[i] << ' ';
			//cout << '\n';
			for (int i = v.size() - 1; i >= 0; --i) if (cnt[i] != 1)
			{
				tot = v.size() - 1 - i;
				break;
			}
			if (!fu) if (oto + tot == 0) ok = true;
			b[nm] = a[nm] - 1;
			F (j, v.size())
				{
					if (b[nm] >= v[j])
					{
						--cnt[j];
						++oto;
						b[nm] -= v[j];
					}
				}
			b[nm] = a[nm];
			F (j, v.size())
				{
					//if (v[j] == 1 && b[i] >= 1 && i == nm) fu = true;
					if (b[nm] >= v[j])
					{
						++cnt[j];
						--oto;
						b[nm] -= v[j];
					}
				}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}

main()
{
	fac_init();
	input();
	solve();
}