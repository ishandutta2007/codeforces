#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

char board[2005][2005];
int m, n, k;

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>n>>m>>k;
	for (int i=0; i<2005; i++) for (int j=0; j<2005; j++) board[i][j]='*';
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>board[i][j];
	
	int ans=0, temp=0;
	
	//rows
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m+1; j++) 
		{
			if (board[i][j]=='*') 
			{
				ans+=max((int)0, temp-k+1);
				temp=0;
			}
			else temp++;
		}
	}
	
	//column
	for (int j=1; j<=m; j++)
	{
		for (int i=1; i<=n+1; i++)
		{
			if (board[i][j]=='*')
			{
				ans+=max((int)0, temp-k+1);
				temp=0;
			}
			else temp++;
		}
	}
	
	if (k==1) cout<<(ans/2);
	else cout<<ans;
	
	//column
}