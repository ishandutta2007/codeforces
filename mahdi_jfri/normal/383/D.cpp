#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;
const int maxm = 1e4 + 20;
const ll mod = 1e9 + 7;


ll dp[maxn][maxm * 2] , a[maxn] , res;

void ok(ll &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%I64d" , &a[i]) , dp[i][a[i] + maxm]++ , dp[i][-a[i] + maxm]++;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < maxm * 2; j++)
		{
			if(a[i] <= j)
				ok(dp[i][j] += dp[i - 1][j - a[i]]);
			if(j + a[i] < maxm * 2)
				ok(dp[i][j] += dp[i - 1][j + a[i]]);
		}
		ok(res += dp[i][maxm]);
	}
	cout << res << endl;
}