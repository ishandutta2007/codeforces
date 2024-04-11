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

const int maxn = 234567, mod = 998244353;

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

string ss;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> ss;
}

int dp[maxn][8];
int s[6][3];

void solve()
{
	int n = ss.length();
	dp[0][0] = 1;
	s[0][0] = 0, s[0][1] = 0, s[0][2] = 0;
	s[1][0] = 1, s[1][1] = 0, s[1][2] = 0;
	s[2][0] = 1, s[2][1] = 1, s[2][2] = 0;
	s[3][0] = 1, s[3][1] = 1, s[3][2] = 1;
	s[4][0] = 0, s[4][1] = 1, s[4][2] = 1;
	s[5][0] = 0, s[5][1] = 0, s[5][2] = 1;
	F1 (i, n)
	{
		F (j, 8)
		{
			F (k, 6)
			{
				int cur = 0;
				bool ok = true;
				F (l, 3)
				{
					int f = (j >> l) & 1;
					if (f == 0)
					{
						if (s[k][l] > ss[i - 1] - '0') ok = false;
						else if (s[k][l] < ss[i - 1] - '0') cur += 1 << l;
					} else cur += 1 << l;
				}
				//dbg(mp(i, cur));
				if (ok)
					dp[i][cur] = (dp[i][cur] + dp[i - 1][j]) % mod;
			}
		}
		//F (j, 8) dbg(dp[i][j]);
	}
	/*int fu = 0;
	vi v;
	F (i, 6)
		F (j, 6)
			F (k, 6)
			{
				int a = s[i][0] * 4 + s[j][0] * 2 + s[k][0];
				int b = s[i][1] * 4 + s[j][1] * 2 + s[k][1];
				int c = s[i][2] * 4 + s[j][2] * 2 + s[k][2];
				if (a <= 5 && b <= 5 && c <= 5)
				{
					
				v.pb(64 * a + 8 * b + c);
				
				v.pb(64 * a + 8 * c + b);
				
				v.pb(64 * b + 8 * a + c);
				
				v.pb(64 * b + 8 * c + a);
				
				v.pb(64 * c + 8 * a + b);
				
				v.pb(64 * c + 8 * b + a);
					//cout << a << ' ' << b << ' ' << c << '\n';
					++fu;
				}
			}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());*/
	//dbg(v.size());
	//dbg(fu);
	int ans = 0;
	F1 (i, n)
	{
		ans = (ans + ans) % mod;
		ans = ans + ss[i - 1] - '0';
	}
	ans = (ans + 1) % mod;
	int h = ans;
	ans = (h * h % mod) * h % mod;
	ans = (ans + 3 * (h * h % mod) % mod) % mod;
	ans = (ans - h + mod) % mod;
	//dbg(ans);
	F (i, 8) ans = (ans - dp[n][i] * 3 % mod + mod) % mod;
	cout << ans << '\n';
}

main()
{
	fac_init();
	input();
	solve();
}