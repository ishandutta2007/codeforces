#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 100;
const int64 MOD = 1000000007;

int dp[MAXN][2];

int main()
{
	int N, a, b, x;
	x = -1;
	cin >> N >> a;

	dp[1][0] = 1;
	dp[1][1] = 1;
	int ans = 1;

	for (int i = 2; i <= N; ++i)
	{
		cin >> b;
		//cout << x << " " << a << " " << b << endl;
		if (b > a)
		{
			dp[i][0] = 1 + dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + 1;
			if (b > x + 1)
				dp[i][1] = max(dp[i][1], dp[i - 2][0] + 2);
		}
		else
		{
			dp[i][0] = 1;
			dp[i][1] = 2;
			ans = max(ans,1 + dp[i - 1][0]);
			if (b > x + 1)
				dp[i][1] = max(dp[i][1], dp[i - 2][0] + 2);
		}

		ans = max(ans,max(dp[i][0],dp[i][1]));
		x = a;
		a = b;
		//cout << dp[i][0] << " " << dp[i][1] << endl;
	}

	cout << ans << endl;
}