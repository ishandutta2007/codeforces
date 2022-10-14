#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=65;
int n,m,q,d[N][N][N],f[N][N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				cin>>d[i][j][k];
	for(int i=1;i<=m;i++)
		for(int z=1;z<=n;z++)
			for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++)
					d[i][x][y]=min(d[i][x][y],d[i][x][z]+d[i][z][y]);
	memset(f[0],0x3f,sizeof f[0]);
	for(int i=1;i<=m;i++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=n;y++)
				f[0][x][y]=min(f[0][x][y],d[i][x][y]);
	for(int i=1;i<=n+1;i++){
		memcpy(f[i],f[i-1],sizeof f[i]);
		for(int z=1;z<=n;z++)
			for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++)
					f[i][x][y]=min(f[i][x][y],f[i-1][x][z]+f[0][z][y]);
	}
	while(q--){
		int s,t,k;cin>>s>>t>>k,k=min(k,n+1);
		cout<<f[k][s][t]<<"\n";
	}
}