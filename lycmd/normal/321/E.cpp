#include<bits/stdc++.h>
using namespace std;
int const N=4010;
int n,m,a[N][N],f[N][N],g[N][N],pre[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j],a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			g[i][j]=(a[i][i]+a[j][j])/2-a[i][j];
	memset(f,0x3f,sizeof f);
	for(int i=0;i<=m;i++)
		f[0][i]=0,pre[n+1][i]=n-1;
	for(int j=1;j<=m;j++)
		for(int i=n;i>=1;i--)
			for(int p=pre[i][j-1];p<=pre[i+1][j];p++)
				if(f[i][j]>f[p][j-1]+g[p][i])
					f[i][j]=f[p][j-1]+g[p][i],pre[i][j]=p;
	cout<<f[n][m]<<"\n";
}