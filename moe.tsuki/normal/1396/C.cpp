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

const int maxn = 1234567;
int n;
int r1, r2, r3;
int d;
int a[maxn];
int X[maxn];
int Y[maxn];
int dp[maxn];
int dp1[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> r1 >> r2 >> r3;
	cin >> d;
	F1 (i, n) cin >> a[i]; 
}

void solve()
{
	F1 (i, n) X[i] = min(r1 + r2, (a[i] + 2) * r1);
	F1 (i, n) Y[i] = a[i] * r1 + r3;
	dp[n + 1] = 0;
	dp[n] = min(X[n] + 2 * d, Y[n]);
	dp1[n] = Y[n];
	for (int i = n - 1; i >= 1; --i)
	{
		dp[i] = min(X[i] + 2 * d, Y[i]) + min(dp[i + 1], dp1[i + 1]);
		dp[i] = min(dp[i], X[i] + min(X[i + 1], Y[i + 1]) + 2 * d + dp[i + 2]);
		dp1[i] = X[i] + d + dp1[i + 1];
	}
	cout << dp[1] + (n - 1) * d << '\n';
}

main()
{
	input();
	solve();
}