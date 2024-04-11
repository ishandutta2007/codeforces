#include<bits/stdc++.h>
using namespace std;
int r,n,m,d[105][105],w[105];
signed main()
{
	scanf("%d%d",&n,&m),memset(d,0,sizeof(d)),r=2000000000;
	for(int i=1;i<=n;i++) scanf("%d",w+i);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),d[x][y]=d[y][x]=1;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&j!=k&&i!=k&&d[i][j]&&d[j][k]&&d[k][i]) r=min(r,w[i]+w[j]+w[k]);
	return r==2000000000?puts("-1"):printf("%d\n",r),0;
}