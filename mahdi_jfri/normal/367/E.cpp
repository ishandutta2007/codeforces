#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxm = 1e5 + 20;
const int maxn = 320;
const int mod = 1e9 + 7;

int dp[2][maxn][maxn];

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

	int n , m , x;
	cin >> n >> m >> x;

	if(n > m)
		return cout << 0 << endl , 0;

	x--;

	dp[m&1][0][0] = 1;

	for(int i = m - 1; i >= 0; i--)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
			{
				int shit = i&1;

				dp[shit][j][k] = 0;

				// baz she
				if(k)
				{
					mkay(dp[shit][j][k] += dp[!shit][j + 1][k - 1]);
					mkay(dp[shit][j][k] += dp[!shit][j][k - 1]);
				}

				if(i == x)
					continue;

				// baste she
				if(j)
					mkay(dp[shit][j][k] += dp[!shit][j - 1][k]);

				// hech
				mkay(dp[shit][j][k] += dp[!shit][j][k]);
			}

	int fn = 1;
	for(int i = 1; i <= n; i++)
		fn = 1LL * fn * i % mod;

	fn = 1LL * fn * dp[0][0][n] % mod;

	cout << fn << endl;

}