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

int n, m;
int dp[456][456];
int f[456], fu[456];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
}

int power(int a, int b)
{
	if (b == 0) return 1;
	int ret = power(a * a % m, b / 2);
	if (b & 1) ret = ret * a % m;
	return ret;
}

void solve()
{
	f[0] = 1;
	F1 (i, n) f[i] = f[i - 1] * i % m;
	fu[n] = power(f[n], m - 2);
	for (int i = n - 1; i >= 0; --i)
		fu[i] = fu[i + 1] * (i + 1) % m;
	for (int i = 2; i <= n; ++i)
		fu[i] = fu[i] * power(2, i - 1) % m; 
	//F1 (i, n) dbg(f[i]);
	dp[0][0] = 1; 
	F1 (i, n)
		F1 (j, n)
			for (int k = 0; k <= i - 2; ++k)
				dp[i][j] = (dp[i][j] + dp[k][j - 1] * fu[i - k - 1] % m) % m;
	int ans = 0;
	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= i; ++j)
		{ 
			//dbgg(mp(i, j));
			//dbg(dp[i][j]);
			ans = (ans + (dp[i][j] * fu[n - i] % m) * f[n - j] % m) % m;
			//dbg(ans);
		} 
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}