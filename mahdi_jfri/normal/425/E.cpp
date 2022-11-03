#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e2 + 20;
const int maxt = maxn * maxn;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn] , t[maxt];

int main()
{
	t[0] = 1;
	for(int i = 1; i < maxt; i++)
		t[i] = (t[i - 1] * 2) % mod;
	int n , k;
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
			for(int k = 0; k < i; k++)
			{
				if(!j)
					dp[i][j] = 1;
				else
					dp[i][j] += (((t[k + 1] - 1 + mod) * t[(i - k - 1) * (k + 1)]) % mod) * dp[i - k - 1][j - 1];
				dp[i][j] %= mod;
			}
	cout << dp[n][k] << endl;
}