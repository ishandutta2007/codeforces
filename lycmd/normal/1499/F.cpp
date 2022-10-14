#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5010,MOD=998244353;
int n,k,ans,sz[N],dep[N],dmx[N],t[N],f[N][N];
vector<int>e[N];
void dfs(int x,int fa){
	sz[x]=f[x][0]=1;
	dmx[x]=dep[x];
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
		memset(t,0,sizeof t);
		for(int i=0;i<=dmx[x]-dep[x];i++)
			for(int j=0;j<=dmx[y]-dep[x];j++){
				t[i]=(t[i]+f[x][i]*f[y][j]%MOD)%MOD;
				if(i+j+1<=k)
					t[max(i,j+1)]=(t[max(i,j+1)]+f[x][i]*f[y][j]%MOD)%MOD;
			}
		memcpy(f[x],t,sizeof t);
		dmx[x]=max(dmx[x],dmx[y]);
		sz[x]+=sz[y];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(int i=0;i<=k;i++)
		ans=(ans+f[1][i])%MOD;
	cout<<ans<<"\n";
}