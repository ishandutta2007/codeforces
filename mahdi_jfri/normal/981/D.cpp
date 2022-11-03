#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 60;

ll a[maxn];

bool dp[maxn][maxn];

bool check(int n , int k , ll mask)
{
	memset(dp , 0 , sizeof dp);
	dp[0][0] = 1;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
		{
			ll sum = 0;
			for(int x = i; x > 0; x--)
			{
				sum += a[x];

				if((sum&mask) == mask)
					dp[i][j] |= dp[x - 1][j - 1];
			}
		}

	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	ll mask = 0;
	for(int i = maxn - 1; i >= 0; i--)
		if(check(n , k , mask + (1LL << i)))
			mask += (1LL << i);

	cout << mask << endl;
}