#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
long long dp[100005][2];
#define inf (1LL<<60)
int main()
{
	int n;
	cin >> n;
	int c[n];
	for (int i=0;i<n;i++)
	cin >> c[i];
	string s[n],r[n];
	for (int i=0;i<n;i++)
	{
		cin >> s[i];
		r[i]=s[i];
		reverse(r[i].begin(),r[i].end());
	}
	dp[0][0]=0;
	dp[0][1]=c[0];
	for (int i=1;i<n;i++)
	{
		if (s[i]>=s[i-1])
		dp[i][0]=dp[i-1][0];
		else
		dp[i][0]=inf;
		if (r[i]>=s[i-1])
		dp[i][1]=dp[i-1][0]+c[i];
		else
		dp[i][1]=inf;
		if (s[i]>=r[i-1])
		dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if (r[i]>=r[i-1])
		dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
	}
	long long a=min(dp[n-1][0],dp[n-1][1]);
	if (a==inf)
	a=-1;
	cout << a;
}