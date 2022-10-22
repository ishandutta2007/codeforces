#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 20005
#define C 25 
int n,m,c,q[M],a[N][M],s[N][M],dp[N][M],mx1[N][M],mx2[N][M];
int max(int x,int y) {return x>y?x:y;}
int f1(int x,int y) {return dp[x-1][y]-s[x][y+c-1];}
int f2(int x,int y) {return dp[x-1][y]+s[x][y-1];}
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) s[i][j]=s[i][j-1]+a[i][j];
	for(int i=1;i<=m-c+1;++i) dp[1][i]=s[1][i+c-1]-s[1][i-1]+s[2][i+c-1]-s[2][i-1];
	for(int i=1;i<=m-c+1;++i) mx1[1][i]=max(mx1[1][i-1],dp[1][i]);
	for(int i=m-c+1;i>=1;--i) mx2[1][i]=max(mx2[1][i+1],dp[1][i]);
	for(int i=2,t;i<=n;++i)
	{
		for(int j=1;j<=m-c+1;++j)
		{
			t=s[i][j+c-1]-s[i][j-1]+s[i+1][j+c-1]-s[i+1][j-1];
			if(j-c>=1) dp[i][j]=mx1[i-1][j-c]+t;
			if(j+c<=m-c+1) dp[i][j]=max(dp[i][j],mx2[i-1][j+c]+t);
		}q[0]=2;q[1]=1;
		for(int j=1;j<=m-c+1;++j)
		{
			t=s[i][j+c-1]-s[i][j-1]+s[i+1][j+c-1]-s[i+1][j-1];
			while(q[0]<=q[1] && f1(i,q[q[1]])<=f1(i,j)) --q[1];q[++q[1]]=j;
			while(q[0]<=q[1] && q[q[0]]<=j-c) ++q[0];
			dp[i][j]=max(dp[i][j],f1(i,q[q[0]])+s[i][j-1]+t);
		}q[0]=2;q[1]=1;
		for(int j=m-c+1;j>=1;--j)
		{
			t=s[i][j+c-1]-s[i][j-1]+s[i+1][j+c-1]-s[i+1][j-1];
			while(q[0]<=q[1] && f2(i,q[q[1]])<=f2(i,j)) --q[1];q[++q[1]]=j;
			while(q[0]<=q[1] && q[q[0]]>=j+c) ++q[0];
			dp[i][j]=max(dp[i][j],f2(i,q[q[0]])-s[i][j+c-1]+t);
		}
		for(int j=1;j<=m-c+1;++j) mx1[i][j]=max(mx1[i][j-1],dp[i][j]);
		for(int j=m-c+1;j>=1;--j) mx2[i][j]=max(mx2[i][j+1],dp[i][j]);
	}printf("%d\n",mx2[n][1]);return 0;
}