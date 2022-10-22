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

const int maxn = 567, mod = 998244353;
int n, m;
int a[maxn];
int mn[maxn][maxn];
int pos[maxn];
int dp[maxn][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	F1 (i, n) pos[a[i]] = i;
	F1 (i, n) mn[i][i] = a[i];
	for (int i = 1; i <= n - 1; ++i)
		for (int j = 1; i + j <= n; ++j)
			mn[j][i + j] = min(mn[j + 1][i + j], mn[j][i + j - 1]);
	F1 (i, n)
		dp[i][i] = 1;
	F1 (i, n + 1)
		dp[i][i - 1] = 1;
	for (int i = 1; i <= n - 1; ++i)
		for (int j = 1; i + j <= n; ++j)
		{
			int cur = pos[mn[j][i + j]];
			//int l = dp[j][cur - 1] * 2, r = dp[cur + 1][i + j] * 2;
			int l, r;
			if (cur == j) l = 1; else l = dp[j][cur - 1] * 2 % mod;
			if (cur == i + j) r = 1; else r = dp[cur + 1][i + j] * 2 % mod;
			for (int k = j; k < cur - 1; ++k)
				l = (l + dp[j][k] * dp[k + 1][cur - 1] % mod) % mod;
			for (int k = cur + 1; k < i + j; ++k)
				r = (r + dp[cur + 1][k] * dp[k + 1][i + j] % mod) % mod;
			dp[j][i + j] = l * r % mod;
			//dbgg(j); dbgg(i + j); dbgg(l); dbg(r);
		} 
	cout << dp[1][n] << '\n';
}

main()
{
	input();
	solve();
}