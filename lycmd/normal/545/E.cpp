#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef array<int,4> node;
int const N=300010;
int n,m,s,sum,cur,d[N],vis[N];
vector<node>e[N];
vector<int>ans;
priority_queue<node,vector<node>,greater<node> >q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		e[x].push_back({y,w,i,0});
		e[y].push_back({x,w,i,0});
	}
	cin>>s,memset(d,0x3f,sizeof d),q.push({d[s]=0,0,s,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		int x=t[2];
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:e[x])
			if(i[2]==t[3])sum+=i[1];
		if(t[3])ans.push_back(t[3]);
		for(auto i:e[x]){
			int y=i[0],w=i[1]+d[x],id=i[2];
			if(!vis[y]&&w<=d[y])
				q.push({d[y]=w,--cur,y,id});
		}
	}
	cout<<sum<<"\n";
	for(int x:ans)cout<<x<<" ";
	cout<<"\n"; 
}