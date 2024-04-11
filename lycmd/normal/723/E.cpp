#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,m,vis[N],pre[N],e[N][N],deg[N];
void add(int x,int y){
	e[x][y]=e[y][x]=1,deg[x]++,deg[y]++;
}
void solve(int x){
	vis[x]=1;
	for(int i=0;i<=n;i++)
		if(e[i][x]){
			e[i][x]=e[x][i]=0,solve(i);
			if(i&&x)cout<<x<<" "<<i<<"\n";
		}
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(pre,0,sizeof pre);
		memset(deg,0,sizeof deg);
		memset(vis,0,sizeof vis);
		memset(e,0,sizeof e);
		for(cin>>n>>m;m--;){
			int x,y;cin>>x>>y;
			add(x,y);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=~deg[i]&1;
		cout<<cnt<<"\n";
		for(int i=1;i<=n;i++)
			if(deg[i]&1)
				add(0,i);
		for(int i=0;i<=n;i++)
			if(!vis[i])
				solve(i);
	}
}