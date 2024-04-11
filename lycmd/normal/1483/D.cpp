#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=605,M=N*N;
int n,m,q,cnt,ex[M],ey[M],e[N][N],f[N][N],w[N][N],flg[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	memset(e,0x3f,sizeof e);
	memset(f,0x3f,sizeof f);
	for(int i=0,a,b,c;i<m;i++)
		cin>>a>>b>>c,ex[i]=a,ey[i]=b,
		e[a][b]=e[b][a]=f[a][b]=f[b][a]=c;
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	cin>>q;
	for(int i=0,a,b,c;i<q;i++)
		cin>>a>>b>>c,w[a][b]=w[b][a]=c;
	for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++){
			int t=0;
			for(int i=1;i<=n;i++)
				t=max(t,w[i][k]-f[i][j]);
			for(int i=1;i<=n;i++)
				flg[i][j]|=e[i][j]+f[i][k]<=t,
				flg[j][i]|=e[i][j]+f[i][k]<=t;
		}
	for(int i=0;i<m;i++)
		cnt+=flg[ex[i]][ey[i]];
	cout<<cnt<<"\n";
}