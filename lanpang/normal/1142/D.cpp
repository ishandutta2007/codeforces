#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n;
LL dp[maxn][15] , ans;
char c[maxn];

int main()
{
	int i , j;
	cin >> c+1;
	n = strlen(c+1);
	for (i = n ; i >= 1 ; i--)
	{
		for (j = 0 ; j <= 10 ; j++)
		{
			dp[i][j] = 1;
			if (i < n && c[i+1]-'0' < j) dp[i][j] += dp[i+1][(c[i+1]-'0'+j*(j-1)/2+10)%11];
		}
		if (c[i] > '0') ans += dp[i][c[i]-'0'];
	}
	cout << ans << "\n";
	return 0;
}