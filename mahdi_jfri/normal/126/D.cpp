#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxm = 88;

ll f[maxm] , dp[maxm][2];

bool has[maxm];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	f[0] = 1;
	f[1] = 1;

	for(int i = 2; i < maxm; i++)
		f[i] = f[i - 1] + f[i - 2];


	int T;
	cin >> T;

	while(T--)
	{
		memset(has , 0 , sizeof has);
		memset(dp , 0 , sizeof dp);

		ll n;
		cin >> n;

		for(int i = maxm - 1; i >= 0; i--)
			if(n >= f[i])
				n -= f[i] , has[i] = 1;

		dp[0][0] = 1;

		if(has[1])
			dp[1][0] = 1;
		else
			dp[1][0] = dp[1][1] = 1;
		for(int i = 2; i < maxm; i++)
		{
			// dp[i][0]
			if(has[i])
				dp[i][0] = dp[i - 1][0] + dp[i - 2][1];
			else
				dp[i][0] = dp[i - 1][0];

			// dp[i][1]
			if(has[i])
				dp[i][1] = dp[i - 2][1];
			else
			{
				dp[i][1] = dp[i - 1][0];

				if(!has[i - 1])
					dp[i][1] += dp[i - 2][1];
			}
		}

		cout << dp[maxm - 1][0] << endl;
		
	}


}