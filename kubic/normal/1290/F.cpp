#include <bits/stdc++.h>
using namespace std;
#define N 35
#define M 25
#define MOD 998244353
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,X[N],Y[N],sX1[N],sY1[N],sX2[N],sY2[N],dp[N][M][M][M][M][2][2];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int dfs(int u,int x1,int y1,int x2,int y2,bool flX,bool flY)
{
	if(u>29) return !x1 && !y1 && !x2 && !y2 && flX && flY;
	int res=dp[u][x1][y1][x2][y2][flX][flY];if(~res) return res;res=0;
	for(int i=0,tX1,tY1,tX2,tY2;i<1<<n;++i)
	{
		bool d=m>>u&1,dX1,dY1,dX2,dY2,tFlX,tFlY;
		tX1=x1+sX1[i];tY1=y1+sY1[i];tX2=x2+sX2[i];tY2=y2+sY2[i];
		dX1=tX1&1;dY1=tY1&1;dX2=tX2&1;dY2=tY2&1;
		tFlX=d^dX1?d>dX1:flX;tFlY=d^dY1?d>dY1:flY;
		if(dX1==dX2 && dY1==dY2)
			res=add(res,dfs(u+1,tX1/2,tY1/2,tX2/2,tY2/2,tFlX,tFlY));
	}return dp[u][x1][y1][x2][y2][flX][flY]=res;
}
int main()
{
	scanf("%d %d",&n,&m);set(dp,-1);
	for(int i=1;i<=n;++i) scanf("%d %d",&X[i],&Y[i]);
	for(int i=0;i<1<<n;++i) for(int j=1;j<=n;++j) if(i>>j-1&1)
	{
		if(X[j]>0) sX1[i]+=X[j];else sX2[i]-=X[j];
		if(Y[j]>0) sY1[i]+=Y[j];else sY2[i]-=Y[j];
	}printf("%d\n",add(dfs(0,0,0,0,0,1,1),MOD-1));return 0;
}