#include<bits/stdc++.h>
using namespace std;
int const N=405,INF=0x3f3f3f3f;
int n,m,x,y,f[N][N],g[N][N];
int main(){
	ios::sync_with_stdio(0);
	memset(f,INF,sizeof f);
	for(cin>>n>>m;m--;)
		cin>>x>>y,f[x][y]=f[y][x]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=f[i][j]^0x3f3f3f3e;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]),
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	int res=max(f[1][n],g[1][n]);
	cout<<(res<INF?res:-1)<<"\n";
}