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
string A, B;
int a[maxn], b[maxn];
int dp[maxn][2];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> A;
	cin >> B;
}

void solve()
{
	F1 (i, n) a[i] = A[i - 1] - '0';
	F1 (i, n) b[i] = B[i - 1] - '0';
	dp[0][0] = 0;
	F1 (i, n)
	{
		dp[i][0] = dp[i - 1][0] + (a[i] ^ b[i]);
		if (a[i] != b[i] && i > 1 && b[i] != b[i - 1])
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
		dp[i][1] = dp[i - 1][0] + (a[i] ^ b[i] ^ 1);
	}
	cout << dp[n][0] << '\n';
}

main()
{
	input();
	solve();
}