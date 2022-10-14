#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> node;
int const N=200010;
int n,ans,rt1,rt2,d[N][2],deg[N],vis[N];
vector<int>e[N];
vector<array<int,3> >res;
priority_queue<node>q;
void dfs(int x,int fa,int op){
	for(int y:e[x]){
		if(y==fa)continue;
		d[y][op]=d[x][op]+1,dfs(y,x,op);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	d[1][0]=0,dfs(1,0,0);
	for(int i=1;i<=n;i++)
		if(d[rt1][0]<d[i][0])
			rt1=i;
	d[rt1][0]=0,dfs(rt1,0,0);
	for(int i=1;i<=n;i++)
		if(d[rt2][0]<d[i][0])
			rt2=i;
	d[rt2][1]=0,dfs(rt2,0,1);
	for(int i=1;i<=n;i++)
		if(e[i].size()==1&&i^rt1&&i^rt2)
			q.push({max(d[i][0],d[i][1]),i}),vis[i]=1;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		res.push_back({x,d[x][0]>d[x][1]?rt1:rt2,x});
		ans+=max(d[x][0],d[x][1]);
		for(int y:e[x])
			if(!vis[y]&&--deg[y]<2)
				q.push({max(d[y][0],d[y][1]),y}),vis[y]=1;
	}
	memset(vis,0,sizeof vis);
	for(int x=rt1;x^rt2;){
		res.push_back({x,rt2,x});
		ans+=d[x][1],vis[x]=1;
		for(int y:e[x])
			if(!vis[y]&&d[y][0]+d[y][1]==d[rt1][1]){
				x=y;break;
			}
	}
	cout<<ans<<"\n";
	for(auto i:res)
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
}