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

const int maxn = 123456;
int r, n;
int t[maxn], x[maxn], y[maxn];
int dp[maxn], al[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> r >> n;
	F1 (i, n) cin >> t[i] >> x[i] >> y[i];
}

void solve()
{
	dp[0] = 0;
	x[0] = 1;
	y[0] = 1;
	int ans = 0;
	F1 (i, n) dp[i] = -1234567;
	F (i, n + 1) 
	{
		al[i] = -1234567;
	}
	F (i, n + 1)
	{
		if (i) al[i] = max(al[i], al[i - 1]);
		dp[i] = max(dp[i], al[i]);
		//dbgg(i);dbg(dp[i]);dbg(al[i]);
		for (int j = i + 1; j <= n; ++j)
		{
			if (abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[j] - t[i])
			{
				dp[j] = max(dp[j], dp[i] + 1);
				//dbg(mp(i, j));
			}
			if (t[j] - t[i] > 1000)
			{
				al[j] = max(al[j], dp[i] + 1);
				break;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n'; 
}

main()
{
	input();
	solve();
}