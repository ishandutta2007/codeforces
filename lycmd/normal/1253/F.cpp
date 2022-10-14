#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>node;
int const N=300010;
int n,m,k,q,f[N],ans[N],d[N],vis[N];
vector<node>e[N];
set<int>s[N];
priority_queue<node,vector<node>,greater<node> >p;
struct edge{
	int x,y,w;
	int operator<(const edge&rhs)const{
		return w<rhs.w;
	}
};
vector<edge>g;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k>>q;
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=k;i++)
		p.push({d[i]=0,i});
	while(!p.empty()){
		int x=p.top().second;p.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:e[x]){
			int y=i.first,k=i.second+d[x];
			if(!vis[y]&&d[y]>k)
				p.push({d[y]=k,y});
		}
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int x=1;x<=n;x++)
		for(auto i:e[x]){
			int y=i.first,k=i.second+d[x]+d[y];
			g.push_back({x,y,k});
		}
	sort(g.begin(),g.end());
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		s[x].insert(i),s[y].insert(i);
	}
	for(auto i:g){
		int x=find(i.x),y=find(i.y);
		if(find(x)==find(y))continue;
		if(s[x].size()<s[y].size())swap(x,y);
		for(int j:s[y])
			if(!s[x].count(j))s[x].insert(j);
			else s[x].erase(j),ans[j]=i.w;
		s[y].clear(),f[y]=x;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}