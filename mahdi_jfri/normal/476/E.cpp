#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int maxs = 27;

int dp[maxn][maxn] , nxt[maxn][maxs] , x[maxn];

int main()
{
	string s , p;
	cin >> s >> p;
	int n = s.size() , m = p.size();

	memset(nxt , 63 , sizeof nxt);
	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j < maxs; j++)
		{
			if(i + 1 < n && s[i + 1] == j + 'a')
				nxt[i][j] = i + 1;
			else
				nxt[i][j] = nxt[i + 1][j];
		}
	for(int i = 0; i < n; i++)
	{
		int now = i;
		for(int j = (s[i] == p[0]); j < m; j++)
			if(now < n)
				now = nxt[now][p[j] - 'a'];
		x[i] = now;
	}
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			dp[i][j] = -1e8;
	dp[n][0] = 0;
	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j <= n; j++)
		{
			dp[i][j] = dp[i + 1][j];
			if(j)
				dp[i][j] = max(dp[i][j] , dp[i + 1][j - 1]);
			if(s[i] == p[0] && (x[i] - i + 1 - m) <= j)
				dp[i][j] = max(dp[i][j] , dp[x[i] + 1][j - x[i] + i - 1 + m] + 1);
		}
	for(int i = 0; i <= n; i++)
		cout << dp[0][i] << " ";
	cout << endl;
}