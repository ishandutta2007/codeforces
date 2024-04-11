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

const int maxn = 131072, mod = 1000000007;

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

int bit1[maxn], bit2[maxn];


#define lowbit(x) (x & (-x))

void add1(int x, int v)
{
	while (x < maxn)
	{
		bit1[x] += v;
		x += lowbit(x);
	}
}
void add2(int x, int v)
{
	while (x < maxn)
	{
		bit2[x] += v;
		x += lowbit(x);
	}
}

int qry(int x)
{
	int r = 0;
	while (x)
	{
		r += bit2[x];
		x -= lowbit(x);
	}
	return r;
}

int a[maxn];
int app[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, k; cin >> n >> k;
		k = min(n, k);
		F1 (i, n) cin >> a[i];
		//sort(a + 1, a + n + 1);
		F (i, n) app[i] = 0;
		F1 (i, n) if (a[i] <= n - 1) app[a[i]] = 1;
		map<int, int> cnt;
		F1 (i, n) ++cnt[a[i]];
		int out = 0;
		
		F (i, n + 1) assert(bit1[i] == 0);  
		F (i, n + 1) assert(bit2[i] == 0); 
		for (auto x : cnt)
		{
			if (x.fi >= n) 
			{
				add1(x.se, x.se);
				add2(x.se, 1);
				++out;
			}
		}
		F1 (i, n - 1) app[i] += app[i - 1];  
		//F (i, n) dbg(app[i]);
		int ans = cnt.size();
		//dbg(out);
		for (int i = n - 1; i >= 0; --i)
		{
			if (i + 1 - app[i] <= k)
			{
				int mx = 0;
				int d = 131072;
				int cur = 0;
				int sum = 0;
				int num = 0;
				while (d >>= 1)
				{
					//if (cur + d < maxn)
					{
						if (sum + bit1[cur + d] <= k)
						{	
							cur += d;
							sum += bit1[cur];
							num += bit2[cur];
						}
					}
				}
				mx = num;
				if (cur < maxn - 1)
				{
					mx += min((k - sum) / (cur + 1), qry(cur + 1) - qry(cur));
				}
				//dbg(i);
				//dbg(mp(out, mx));
				assert(out >= mx);
				ans = min(ans, out - mx);
			}
			if (cnt.count(i) > 0)
			{
				++out;
				add1(cnt[i], cnt[i]);
				add2(cnt[i], 1);
			}
		}
		for (int i = n - 1; i >= 0; --i)
		{
			if (cnt.count(i) > 0)
			{
				add1(cnt[i], -cnt[i]);
				add2(cnt[i], -1);
			}
		}
		for (auto x : cnt)
		{
			if (x.fi >= n) 
			{
				add1(x.se, -x.se);
				add2(x.se, -1);
			}
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