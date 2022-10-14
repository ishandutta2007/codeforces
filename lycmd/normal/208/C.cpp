#include<bits/stdc++.h>
using namespace std;
int const N=105;
int n,m,x,y,f[N][N];
double ans=1.0,g[N][N];
int main(){
	ios::sync_with_stdio(0);
	memset(f,0x3f,sizeof f);
	for(cin>>n>>m;m--;)
		cin>>x>>y,f[x][y]=f[y][x]=g[x][y]=g[y][x]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j],g[i][j]=g[i][k]*g[k][j];
				else if(f[i][j]==f[i][k]+f[k][j])
					g[i][j]+=g[i][k]*g[k][j];
	for(int i=1;i<=n;i++)
		if(f[1][i]+f[i][n]==f[1][n])
			ans=max(ans,2*g[1][i]*g[i][n]/g[1][n]);
	cout<<fixed<<setprecision(8)<<ans<<"\n";
}