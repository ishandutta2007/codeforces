#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 8
#define STT 1<<7
#define INF 1e18
#define ll long long
int n,m,c;ll dp[N][STT];struct node {int v1,v2[M];}a[N];
int max(int x,int y) {return x>y?x:y;}
bool cmp(node x,node y) {return x.v1>y.v1;}
int main()
{
	scanf("%d %d %d",&n,&m,&c);for(int i=1;i<=n;++i) scanf("%d",&a[i].v1);
	for(int i=1;i<=n;++i) for(int j=0;j<m;++j) scanf("%d",&a[i].v2[j]);
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;++i) for(int j=0;j<1<<m;++j) dp[i][j]=-INF;dp[0][0]=0;
	for(int i=1,cnt;i<=n;++i) for(int j=0;j<1<<m;++j)
	{
		cnt=0;
		for(int k=0;k<m;++k) if(j&(1<<k))
			++cnt,dp[i][j]=max(dp[i][j],dp[i-1][j^(1<<k)]+a[i].v2[k]);
		if(i-cnt<=c) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].v1);
		else dp[i][j]=max(dp[i][j],dp[i-1][j]);
	}printf("%lld\n",dp[n][(1<<m)-1]);return 0;
}