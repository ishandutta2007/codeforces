#include <bits/stdc++.h>
using namespace std;
#define N 15
#define M 105
#define C 1<<14
const int INF=1e9+1;
int n,m,ans,lg[C],dst1[C][N],dst2[C][M],dp[C][M],dp1[C][M];struct Node {int tim,x,y;}a[N],b[M];
bool cmp(Node x,Node y) {return x.tim<y.tim;}
int dst(Node x,Node y) {return x.x<INF && y.x<INF?abs(x.x-y.x)+abs(x.y-y.y):0;}
void W1(int &x,int y) {x=min(x,y);}
void W2(int &x,int y) {x=max(x,y);}
int main()
{
	scanf("%d %d",&n,&m);for(int i=2;i<1<<n;++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;++i) scanf("%d %d",&a[i].x,&a[i].y);b[0].x=INF;
	for(int i=1;i<=m;++i) scanf("%d %d %d",&b[i].x,&b[i].y,&b[i].tim);sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;++i) dst1[0][i]=INF;for(int i=1;i<=m;++i) dst2[0][i]=INF;
	for(int i=1;i<1<<n;++i) for(int j=1;j<=n;++j) dst1[i][j]=min(dst1[i&i-1][j],dst(a[j],a[lg[i&-i]+1]));
	for(int i=1;i<1<<n;++i) for(int j=1;j<=m;++j) dst2[i][j]=min(dst2[i&i-1][j],dst(b[j],a[lg[i&-i]+1]));
	for(int i=0;i<1<<n;++i) for(int j=0;j<=m;++j) dp[i][j]=-INF,dp1[i][j]=INF;dp[0][0]=dp1[0][0]=0;
	for(int i=0;i<1<<n;++i) for(int j=0;j<=m;++j)
	{
		for(int k=j+1;k<=m;++k)
		{
			if(b[j].tim+min(dst(b[j],b[k]),dst2[i][k])<=b[k].tim) W2(dp[i][k],dp[i][j]+1);
			if(dp1[i][j]+dst2[i][k]<=b[k].tim) W2(dp[i][k],j+1);
		}
		for(int k=1;k<=n;++k) if(!(i>>k-1&1))
		{
			if(dp[i][j]>=0) W1(dp1[i|(1<<k-1)][dp[i][j]],b[j].tim+min(dst(b[j],a[k]),dst1[i][k]));
			W1(dp1[i|(1<<k-1)][j],dp1[i][j]+dst1[i][k]);
		}ans=max(ans,dp[i][j]);
	}printf("%d\n",ans);return 0;
}