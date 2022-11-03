#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 5e5 + 20;
const int maxk = 1e2 + 20;

int dp[maxn][maxk] , a[maxn] , fen[maxk] , sum[maxn] , total;

inline void update(int p , int val)
{
	for(p++; p < maxk; p += lb(p))
		fen[p] = min(fen[p] , val);
}

inline int get(int p)
{
	int res = 1e9;
	for(p++; p > 0; p -= lb(p))
		res = min(res , fen[p]);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k , p;
	cin >> n >> k >> p;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]) % p;
	}

	for(int i = 1; i <= n; i++)
		dp[i][1] = sum[i];

	for(int j = 2; j <= k; j++)
	{
		memset(fen , 63 , sizeof fen);
		total = 1e9;

		for(int i = 1; i <= n; i++)
		{
			dp[i][j] = min(total , get(sum[i])) + sum[i];

			total = min(total , dp[i][j - 1] - sum[i] + p);
			update(sum[i] , dp[i][j - 1] - sum[i]);
		}
	}

	cout << dp[n][k] << endl;
}