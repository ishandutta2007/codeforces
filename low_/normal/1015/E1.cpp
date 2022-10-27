#include<iostream>
#include<fstream>
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
#define FLN "test"

int FU[1005][1005], FL[1005][1005], FR[1005][1005], FD[1005][1005], dp[1005][1005], ans[1005][1005];
int m, n;
char board[1005][1005];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<1005; i++) for (int j=0; j<1005; j++) FU[i][j]=FD[i][j]=FL[i][j]=FR[i][j]=0, board[i][j]='.';
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) 
	{
		cin>>board[i][j];
		ans[i][j]=(board[i][j]=='.');
	}
	
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (board[i][j]=='*') FL[i][j]=FL[i][j-1]+1;
	for (int i=1; i<=n; i++) for (int j=m; j>=1; j--) if (board[i][j]=='*') FR[i][j]=FR[i][j+1]+1;
	for (int j=1; j<=m; j++) for (int i=1; i<=n; i++) if (board[i][j]=='*') FU[i][j]=FU[i-1][j]+1;
	for (int j=1; j<=m; j++) for (int i=n; i>=1; i--) if (board[i][j]=='*') FD[i][j]=FD[i+1][j]+1;
	
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) dp[i][j]=min(min(FL[i][j], FR[i][j]), min(FU[i][j], FD[i][j]));
	
	for (int i=1; i<=n; i++)
	{
		int aura=0;
		for (int j=1; j<=m; j++) 
		{
			aura=max(aura-1, dp[i][j]-(dp[i][j]==1));
			if (aura>0) ans[i][j]=1;
		}
		
		aura=0;
		for (int j=m; j>=1; j--)
		{
			aura=max(aura-1, dp[i][j]-(dp[i][j]==1));
			if (aura>0) ans[i][j]=1;
		}
	}
	
	for (int j=1; j<=m; j++)
	{
		int aura=0;
		for (int i=1; i<=n; i++)
		{
			aura=max(aura-1, dp[i][j]-(dp[i][j]==1));
			if (aura>0) ans[i][j]=1;
		}
		
		aura=0;
		for (int i=n; i>=1; i--)
		{
			aura=max(aura-1, dp[i][j]-(dp[i][j]==1));
			if (aura>0) ans[i][j]=1;
		}
	}
	
//	for (int i=1; i<=n; i++) 
//	{
//		for (int j=1; j<=m; j++) cout<<dp[i][j]<<' ';
//		cout<<'\n';
//	}
	
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (ans[i][j]==0)
	{
//		cerr<<i<<' '<<j<<'\n';
		cout<<-1;
		return 0;
	}
	
	vector <pair <pair <int, int>, int> > ANS;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (dp[i][j]>1) ANS.push_back({{i, j}, dp[i][j]-1});
	
	cout<<ANS.size()<<'\n';
	for (int i=0; i<ANS.size(); i++) cout<<ANS[i].first.first<<' '<<ANS[i].first.second<<' '<<ANS[i].second<<'\n';
}