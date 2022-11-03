#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;

int dp[5][maxn / 2][2] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(dp , 63 , sizeof dp);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	dp[0][0][0] = 0;
	dp[0][1][1] = 0;

	for(int i = 1; i < n; i++)
		for(int j = 0; j <= (i + 2) / 2; j++)
		{
			int x = i % 3 , y = (x - 1 + 3) % 3 , z = (y - 1 + 3) % 3;

			if(j == 0)
			{
				dp[x][j][0] = 0;
				dp[x][j][1] = 1e9;
				continue;
			}

			dp[x][j][0] = min(dp[y][j][0] , dp[y][j][1] + max(0 , a[i] - a[i - 1] + 1));

			if(i == 1)
				dp[x][j][1] = max(0 , a[i - 1] - a[i] + 1);
			else
			{
				int A = dp[z][j - 1][0] + max(0 , a[i - 1] - a[i] + 1);
				int B = dp[z][j - 1][1] + max(0 , max(a[i - 1] - a[i] + 1 , a[i - 1] - a[i - 2] + 1));

				dp[x][j][1] = min(A , B);
			}

		}

	for(int i = 1; i <= (n + 1) / 2; i++)
		cout << min(dp[(n - 1)%3][i][0] , dp[(n - 1)%3][i][1]) << " ";
	cout << endl;

}