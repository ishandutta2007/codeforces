#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , dp[110][2][2] , a[110] , b[110];
char aa[110] , bb[110];

int mmax(int x)
{
	int ret = dp[x][a[x]][b[x]];
	if (a[x] == 0) ret = max(ret,dp[x][1][b[x]]);
	if (b[x] == 0) ret = max(ret,dp[x][a[x]][1]);
	if (a[x] == 0 && b[x] == 0) ret = max(ret,dp[x][1][1]);
	return ret;
}

int main()
{
	int i;
	cin >> aa >> bb;
	n = strlen(aa);
	for (i = 0 ; i < n ; i++)
	{
		if (aa[i] == '0') a[i] = 0;
		else a[i] = 1;
		if (bb[i] == '0') b[i] = 0;
		else b[i] = 1;
	}
	for (i = 0 ; i < n ; i++)
	{
		dp[i][0][0] = -100;
		dp[i][0][1] = -100;
		dp[i][1][0] = -100;
		dp[i][1][1] = -100;
	}
	dp[0][a[0]][b[0]] = 0;
	for (i = 1 ; i < n ; i++)
	{
		dp[i][a[i]][b[i]] = mmax(i-1);
		if (a[i] == 0) dp[i][1][b[i]] = max(dp[i][1][b[i]],dp[i-1][0][0]+1);
		if (b[i] == 0) dp[i][a[i]][1] = max(dp[i][a[i]][1],dp[i-1][0][0]+1);
		if (a[i] == 0 && b[i] == 0) dp[i][1][1] = max(dp[i][1][1],max(dp[i-1][0][0]+1,max(dp[i-1][0][1]+1,dp[i-1][1][0]+1)));
	}
	cout << mmax(n-1) << "\n";
	return 0;
}