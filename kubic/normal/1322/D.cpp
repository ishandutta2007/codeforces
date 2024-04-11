#include <bits/stdc++.h>
using namespace std;
#define N 4005
const int INF=1e9;
int n,m,a[N],b[N],w[N],dp[N][N];
void W(int &x,int y) {x=max(x,y);}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n+m;++i) for(int j=1;j<=n;++j) dp[i][j]=-INF;
	for(int i=n;i;--i) scanf("%d",&a[i]);
	for(int i=n;i;--i) scanf("%d",&b[i]);
	for(int i=1;i<=n+m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j;--j) W(dp[a[i]][j],dp[a[i]][j-1]+w[a[i]]-b[i]);
		for(int j=a[i],up=i;j<n+m;++j,up/=2)
			for(int k=0;k<=up;++k) W(dp[j+1][k/2],dp[j][k]+k/2*w[j+1]);
	}printf("%d\n",dp[n+m][0]);return 0;
}