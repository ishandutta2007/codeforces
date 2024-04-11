#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233,MOD=1000000007;
int n,sz[N],f[N][N][2],t[N][2],fac[N],inv[N],g[N];
vector<int>e[N];
inline int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
inline int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
inline void dfs(int x,int fa){ 
	sz[x]=f[x][0][0]=f[x][0][1]=1;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y==fa)continue;
		dfs(y,x);
		memset(t,0,sizeof t);
		for(int j=0;j<=sz[x];j++)
			for(int k=0;k<=sz[y];k++){
				t[j+k][0]=(t[j+k][0]+f[x][j][0]*f[y][k][0]%MOD)%MOD;
				t[j+k][1]=(t[j+k][1]+f[x][j][0]*f[y][k][1]%MOD+f[x][j][1]*f[y][k][0]%MOD)%MOD;
				t[j+k+1][0]=(t[j+k+1][0]+f[x][j][0]*f[y][k][1]%MOD)%MOD;
				t[j+k+1][1]=(t[j+k+1][1]+f[x][j][1]*f[y][k][1]%MOD)%MOD;
			}
		sz[x]+=sz[y];
		memcpy(f[x],t,sizeof t);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		fac[i]=i?fac[i-1]*i%MOD:1;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(int i=0;i<n;i++)
		g[i]=i?f[1][i][1]*qpow(n,i-1)%MOD:1;
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			g[i]=(g[i]-g[j]*C(n-j-1,i-j)%MOD+MOD)%MOD;
	for(int i=n-1;~i;i--)
		cout<<g[i]<<" ";
	return 0;
}