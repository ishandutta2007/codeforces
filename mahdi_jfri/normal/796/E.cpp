#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int maxk = 55;

int dp[2][maxn][maxk][2] , uni[maxn][maxn] , has[maxn][2];

int a[maxn] , b[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , p , K;
	cin >> n >> p >> K;

	int r;
	cin >> r;

	for(int i = 0; i < r; i++)
		cin >> a[i] , a[i]--;

	int s;
	cin >> s;

	for(int i = 0; i < s; i++)
		cin >> b[i] , b[i]--;

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < maxn; j++)
		{
			bool f1 = 0;
			int ind = lower_bound(a , a + r , j - 1) - a;
			if(ind < r && a[ind] == j - 1)
				f1 = 1;

			bool f2 = 0;
			ind = lower_bound(b , b + s , j - 1) - b;

			if(ind < s && b[ind] == j - 1)
				f2 = 1;

			has[j - 1][0] = f1;
			has[j - 1][1] = f2;
			uni[i][j] = uni[i][j - 1] + (f1 | f2);
		}

	p = min(p , 2 * (n / K) + 5);

	for(int j = 0; j <= p; j++)
		for(int i = n - 1; i >= 0; i--)
			for(int k = 0; k <= K; k++)
				for(int x = 0; x < 2; x++)
				{
					int id = j&1;

					dp[id][i][k][x] = dp[id][i + 1][max(0 , k - 1)][x];
					if(k)
						dp[id][i][k][x] += has[i][x];

					if(!j)
						continue;

					dp[id][i][k][x] = max(dp[id][i][k][x] , dp[!id][i][K][x]);
					dp[id][i][k][x] = max(dp[id][i][k][x] , dp[!id][i + k][K - k][!x] + uni[i][i + k]);
				}
	cout << dp[p&1][0][0][0] << endl;
}