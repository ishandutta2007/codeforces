#include <bits/stdc++.h>
using namespace std;
#define N 1005
const int X[]={1,-1,0,0},Y[]={0,0,1,-1};const char D[]="DURLX";
int n,dX[N][N],dY[N][N],ans[N][N];bool vs[N][N];
void dfs(int x,int y)
{
	for(int i=0,gX,gY;i<4;++i)
	{
		gX=x+X[i];gY=y+Y[i];
		if(gX>0 && gX<=n && gY>0 && gY<=n && dX[x][y]==dX[gX][gY] && dY[x][y]==dY[gX][gY] && ans[gX][gY]==-1)
			ans[gX][gY]=i^1,dfs(gX,gY);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ans[i][j]=-1,scanf("%d %d",&dX[i][j],&dY[i][j]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(dX[i][j]==-1) for(int k=0,gX,gY;k<4;++k)
	{gX=i+X[k];gY=j+Y[k];if(dX[gX][gY]==-1) {ans[i][j]=k;break;}}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(dX[i][j]==i && dY[i][j]==j) ans[i][j]=4,dfs(i,j);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(ans[i][j]==-1) {puts("INVALID");return 0;}puts("VALID");
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=n;++j) printf("%c",D[ans[i][j]]);return 0;
}