#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , a[maxn] , tp , b[maxn] , dp[5010][5010];

int main()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (a[i] != b[tp]) b[++tp] = a[i];
	}
	for (k = 2 ; k <= tp ; k++)
	{
		for (i = 1 ; i+k-1 <= tp ; i++)
		{
			j = i+k-1;
			dp[i][j] = min(dp[i][j-1]+1,dp[i+1][j]+1);
			if (b[i] == b[j]) dp[i][j] = min(dp[i][j],dp[i+1][j-1]+1);
		}
	}
	cout << dp[1][tp] << "\n";
	return 0;
}