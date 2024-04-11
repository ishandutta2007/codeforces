#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e4 + 20;
const int maxk = 53;
const int maxp = 1e2 + 20;

int dp[maxn][maxk][maxp] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n , k , p;
	cin >> n >> k >> p;

	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i] %= p;

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxk; j++)
			for(int k = 0; k < maxp; k++)
				dp[i][j][k] = -1e9;

	for(int i = 0; i < p; i++)
		dp[0][1][i] = (a[0] + i) % p;

	for(int i = 1; i < n; i++)
		for(int j = 1; j <= k; j++)
			for(int v = 0; v < p; v++)
				dp[i][j][v] = max(dp[i - 1][j - 1][0] + ((v + a[i]) % p) , dp[i - 1][j][(v + a[i]) % p]);

	cout << dp[n - 1][k][0] << endl;
}