#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , m , l , a[50] , b[50] , dp[50];

int main()
{
	LL i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if (i >= 2) a[i] = min(a[i],2*a[i-1]);
	}
	for (i = n+1 ; i <= 32 ; i++)
	{
		a[i] = 2*a[i-1];
	}
	for (i = 31 ; i >= 1 ; i--)
	{
		a[i] = min(a[i],a[i+1]);
	}
	l = m;
	for (i = 1 ; i <= 32 ; i++)
	{
		b[i] = l%2;
		l /= 2;
		if (l == 0)
		{
			l = i;
			break;
		}
	}
	for (i = 1 ; i <= l ; i++)
	{
		if (b[i] == 0) dp[i] = dp[i-1];
		else dp[i] = min(a[i+1],a[i]+dp[i-1]);
	}
	cout << dp[l] << "\n";
	return 0;
}