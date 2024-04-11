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

const int maxn = 15;
int n;
int dp[16384][maxn][128];
int E[maxn][maxn];
int ans[64][128];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n)
	{
		string s; cin >> s;
		F1 (j, n) E[i][j] = s[j - 1] - 48;
	}
}

void solve()
{
	F1 (i, n)
		dp[1 << (i - 1)][i][0] = 1;
	for (int i = 0; i < (1 << n) - 1; ++i)
	{
		if (__builtin_popcount(i) > (n + 2) / 2) continue; 
		for (int j = 1; j <= n; ++j)
		{	
			for (int k = 0; k < 64; ++k)
			{
				for (int l = 1; l <= n; ++l)
				{
					if (i & (1 << (l - 1))) continue;
					dp[i | (1 << (l - 1))][l][k + k + E[j][l]]
					+= dp[i][j][k];
				}
			}
		}
	}
	vi v1, v2;
	for (int i = 0; i < (1 << n); ++i)
		if (__builtin_popcount(i) == (n + 1) / 2) v1.pb(i);
	for (int i = 0; i < (1 << n); ++i)
		if (__builtin_popcount(i) == (n + 2) / 2) v2.pb(i);
	for (int i = 1; i <= n; ++i)
	{
		for (auto j : v1)
			for (auto k : v2)
			{
				if ((j & k) != (1 << (i - 1))) continue;
				for (int l = 0; l < 64; ++l)
				{
					for (int m = 0; m < 128; ++m)
					{
						ans[l][m] += dp[j][i][l] * dp[k][i][m];
						if ((dp[j][i][l] == 0 || dp[k][i][m] == 0)) continue;
						
					}
				}
			}
	}
	for (int i = 0; i < (1 << ((n - 1) / 2)); ++i)
	{
		for (int j = 0; j < (1 << (n / 2)); ++j)
		{
			int nj = 0;
			int bit = n / 2;
			int cur = bit;
		
			while (cur --> 0)
			{
				if (j & (1 << cur)) nj += 1 << (bit - cur - 1);
			}
			
			cout << ans[i][nj] << ' ';
		}
	}
}

main()
{
	input();
	solve();
}