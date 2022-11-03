#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int maxb = 21;
const int mod = 1e9 + 7;

int dp[maxn][maxb] , pr[maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	for(int i = 2; i < maxn; i++)
		if(!pr[i])
			for(int j = i; j < maxn; j += i)
				pr[j] = i;

	for(int i = 1; i < maxb; i++)
		dp[0][i] = 2;
	for(int i = 0; i < maxn; i++)
		dp[i][0] = 1;

	for(int i = 1; i < maxn; i++)
		for(int j = 1; j < maxb; j++)
			mkay(dp[i][j] = dp[i][j - 1] + dp[i - 1][j]);

	int q;
	scanf("%d", &q);
	
	while(q--)
	{
		int r , n;
		scanf("%d%d", &r, &n);

		int res = 1;

		while(n > 1)
		{
			int p = pr[n] , t = 0;
			while(n % p == 0)
				n /= p , t++;

			res = 1LL * res * dp[r][t] % mod;
		}

		printf("%d\n", res);
	}
}