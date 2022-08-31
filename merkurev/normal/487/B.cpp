#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;


const int maxn = 1e5 + 100;
int a[maxn];
int dp[maxn];
const int inf = 1e9;


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, s, l;
	scanf("%d%d%d", &n, &s, &l);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	for (int i = 0; i <= n; i++)
		dp[i] = inf;


	int lp = 0;
	multiset <int> vals;	
	multiset <int> dps;

	dp[0] = 0;
	for (int i = 0; i < l - 1; i++)
	{
		vals.insert(a[i] );
	}
	for (int i = l - 1; i < n; i++)
	{
		dps.insert(dp[i - (l - 1) ] );
		vals.insert(a[i] );
			
		while (lp <= (i - (l - 1)) && (*vals.rbegin() - *vals.begin() ) > s)
		{
			vals.erase(vals.find(a[lp] ) );
			dps.erase(dps.find(dp[lp] ) );
			lp++;
		}
		if (!dps.empty() )
			dp[i + 1] = (*dps.begin() ) + 1;
	}
	if (dp[n] > inf / 2)
		dp[n] = -1;
	printf("%d\n", dp[n] );	

	return 0;
}