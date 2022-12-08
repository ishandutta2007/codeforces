#include <bits/stdc++.h>

using namespace std;

int a[10][2000];
int n, m;
int dp[2000][200];
int get(int i, int mask, int st)
{
	int lel=0;
	for(int j=st; j<st+n; j++)
	{
		int at=j%n;
		if(at==0) at=n;
		if((mask&(1<<(j-st)))>0) lel+=a[at][i];
	}
	return lel;
}

signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		cin>>n>>m;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				cin>>a[i][j];
			}
		}
//		for(int i=1; i<=m; i++)
//		{
//			cout<<get(i, 3, 1);
//		}
		for(int i=1; i<=m; i++)
		{
			for(int mask=0; mask<(1<<n); mask++)
			{
				dp[i][mask]=dp[i-1][mask];
				for(int j=0; j<=mask; j++)
				{
					if((mask|j)==mask)
					{
						for(int st=1; st<=n; st++)
						dp[i][mask]=max(dp[i][mask], dp[i-1][mask^j]+get(i, j, st));
					}
				}
			}
		}
		cout<<dp[m][(1<<n)-1];
		cout<<endl;
	}
}