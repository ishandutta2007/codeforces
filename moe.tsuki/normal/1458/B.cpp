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

const int maxn = 123, maxt = 12345, oo = 123456789;
int n;
int a[maxn], b[maxn];
int dp[2][maxn][maxt];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i] >> b[i];
}

void solve()
{
	// min(sigma a, (sum + sigma b) / 2)
	int sum = 0;
	F1 (i, n) sum += b[i];
	F (i, maxn) F (j, maxt) dp[0][i][j] = dp[1][i][j] = -oo;
	dp[0][0][0] = dp[1][0][0] = 0;
	int last = 0;
	int cur = 1;
	F1 (i, n)
	{
		for (int k = 0; k <= n; ++k)
			for (int j = 0; j < maxt; ++j)
				dp[cur][k][j] = dp[last][k][j];
		for (int k = 1; k <= n; ++k)
			for (int j = a[i]; j < maxt; ++j)
				dp[cur][k][j] = max(dp[cur][k][j], dp[last][k - 1][j - a[i]] + b[i]);
		last ^= 1; cur ^= 1;
	}
	for (int k = 1; k <= n; ++k)
	{
		double ans = 0;
		for (int j = 0; j < maxt; ++j)
			ans = max(ans, (double) min(j + j, sum + dp[last][k][j]));
		cout << ans / 2 << ' ';
	}
}

main()
{
	input();
	solve();
}