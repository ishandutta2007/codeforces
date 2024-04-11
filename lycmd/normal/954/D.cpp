#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int const N=2333;
int n,m,s,t,ans,d1[N],d2[N],vis[N];
vector<int>e[N];
queue<node>q;
void dij(int s,int(&d)[N]){
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	q.push({d[s]=0,s});
	while(!q.empty()){
		int x=q.front().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int y:e[x])
			if(!vis[y]&&d[y]>d[x]+1)
				q.push({d[y]=d[x]+1,y});
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s>>t,ans=-m;
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dij(s,d1),dij(t,d2);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=d1[i]+d2[j]+1>=d1[t]&&d2[i]+d1[j]+1>=d1[t];
	cout<<ans<<"\n";
}