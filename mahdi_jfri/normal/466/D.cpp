#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int mod = 1e9 + 7;

int dp[maxn][maxn] , a[maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , h;
	cin >> n >> h;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		if(a[i] > h)
			return cout << 0 << endl , 0;
	}

	dp[n][0] = 1;

	for(int i = n - 1; i >= 0; i--)
		for(int j = h - a[i] - 1; j <= h - a[i]; j++)
		{
			if(j + a[i] == h)
			{
				dp[i][j] = dp[i + 1][j];

				if(j)
					mkay(dp[i][j] += 1LL * dp[i + 1][j - 1] * j % mod);
			}

			if(j + a[i] == h - 1)
			{
				dp[i][j] = dp[i + 1][j + 1];

				mkay(dp[i][j] += 1LL * dp[i + 1][j] * (j + 1) % mod);
			}
		}

	cout << dp[0][0] << endl;


}