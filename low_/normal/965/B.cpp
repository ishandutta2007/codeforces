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

int n, k;
char board[105][105];
int ans[105][105];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) 
	{
		cin>>board[i][j];
		ans[i][j]=0;
	}
	
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (board[i][j]=='.')
	{
		if (i<=n-k+1) for (int h=i; h<i+k; h++) 
		{
			if (board[h][j]=='#') break;
			if (h==i+k-1) for (int g=i; g<=h; g++) ans[g][j]++;
		}
		
		if (j<=n-k+1) for (int h=j; h<j+k; h++)
		{
			if (board[i][h]=='#') break;
			if (h==j+k-1) for (int g=j; g<=h; g++) ans[i][g]++;
		}
	}
	
	int x=1, y=1;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (ans[i][j]>ans[x][y])
	{
		x=i;
		y=j;
	}
	
	cout<<x<<' '<<y;
	
}