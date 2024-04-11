#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=3010;
int t,n,m,a[N],b[N],sz[N];
struct node{
	int cnt,val;
	node(int x=0,int y=0):cnt(x),val(y){}
	int operator<(const node&rhs)const{
		return cnt<rhs.cnt||(cnt==rhs.cnt&&val<rhs.val);
	}
};
node f[N][N],g[N];
vector<int>e[N];
void dfs(int x,int fa){
	sz[x]=1,f[x][1]={0,a[x]};
	for(int i=2;i<=m;i++)
		f[x][i]={0,0};
	for(int y:e[x]){
		if(y==fa)continue;
		dfs(y,x),sz[x]+=sz[y];
		for(int i=1;i<=sz[x];i++)
			g[i]={-1,-LLONG_MAX};
		for(int i=1;i<=sz[x]-sz[y];i++)
			for(int j=1;j<=sz[y];j++)
				g[i+j]=max(g[i+j],
					node(f[x][i].cnt+f[y][j].cnt+(f[y][j].val>0),f[x][i].val)),
				g[i+j-1]=max (g[i+j-1],
					node(f[x][i].cnt+f[y][j].cnt,f[x][i].val+f[y][j].val));
		for(int i=1;i<=sz[x];i++)
			f[x][i]=g[i];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>b[i],e[i].clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],a[i]-=b[i];
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		cout<<f[1][m].cnt+(f[1][m].val>0)<<"\n";
	}
}