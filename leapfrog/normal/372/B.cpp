//
//
#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[45][45],s[45][45],dp[45][45][45][45],sm[45][45][45][45];
inline int Q(int a,int b,int c,int d) {return s[c][d]+s[a][b]-s[c][b]-s[a][d];}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%1d",a[i]+j),s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=i;k<=n;k++) for(int l=j;l<=m;l++) dp[i][j][k][l]=!Q(i-1,j-1,k,l);
	for(int k=1;k<=n;k++) for(int l=1;l<=m;l++) for(int i=k;i>=1;i--) for(int j=l;j>=1;j--)
		dp[i][j][k][l]+=dp[i][j+1][k][l]+dp[i+1][j][k][l]-dp[i+1][j+1][k][l];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=i;k<=n;k++) for(int l=j;l<=m;l++)
		dp[i][j][k][l]+=dp[i][j][k-1][l]+dp[i][j][k][l-1]-dp[i][j][k-1][l-1];
	for(int i=1,a,b,c,d;i<=q;i++) scanf("%d%d%d%d",&a,&b,&c,&d),printf("%d\n",dp[a][b][c][d]);
	return 0;
}