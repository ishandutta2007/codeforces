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

const int maxn = 567;
int n, m, k;
int a[maxn][maxn], b[maxn][maxn];
int dp[maxn][maxn][12];
int mn[maxn][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	F1 (i, n)
		F1 (j, m - 1)
			cin >> a[i][j];
	F1 (i, n - 1)
		F1 (j, m)
			cin >> b[i][j]; 
}

/*int ans[maxn][maxn];
int X, Y;

/*void gao(int i, int j, int t)
{
	if (t + t > k) return;
	ans[X][Y] = min(ans[X][Y], 2 * dp[i][j] + mn[i][j] * (k - t - t));
}*/

void solve()
{
	F1 (i, n)
		F1 (j, m)
		{
			mn[i][j] = 1234567;
			if (i <= n - 1) mn[i][j] = min(mn[i][j], b[i][j]);
			if (i >= 2) mn[i][j] = min(mn[i][j], b[i - 1][j]);
			if (j >= 2) mn[i][j] = min(mn[i][j], a[i][j - 1]);
			if (j <= m - 1) mn[i][j] = min(mn[i][j], a[i][j]);
		}
	//F1 (i, n) F1 (j, m) dbg(mn[i][j]);
	/*F1 (i, n)
	{
		F1 (j, m)
		{
			gao(i, j, 0);
			
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}*/
	if (k & 1)
	{
		F1 (i, m)
		{
			F1 (j, m) cout << "-1 ";
			cout << '\n';
		}
		return;
	}
	F (t, k / 2 + 1)
	{
		F1 (i, n)
			F1 (j, m)
			{
				dp[i][j][t] = mn[i][j] * t * 2;
			}
		if (t)
		{
			F1 (i, n) F1 (j, m)
			{
				if (i <= n - 1) dp[i][j][t] = min(dp[i][j][t], dp[i + 1][j][t - 1] + b[i][j] * 2);
				if (i >= 2) dp[i][j][t] = min(dp[i][j][t], dp[i - 1][j][t - 1] + b[i - 1][j] * 2);
				if (j >= 2) dp[i][j][t] = min(dp[i][j][t], dp[i][j - 1][t - 1] + a[i][j - 1] * 2);
				if (j <= m - 1) dp[i][j][t] = min(dp[i][j][t], dp[i][j + 1][t - 1] + a[i][j] * 2);
			}
		}
	}
	F1 (i, n) 
	{
		F1 (j, m)
		{
			cout << dp[i][j][k / 2] << ' ';
		}
		cout << '\n';	
	}
}

main()
{
	input();
	solve();
}