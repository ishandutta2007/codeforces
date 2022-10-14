#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,cur,f[N],ans[N],dfn[N],low[N];
vector<int>b;
vector<array<int,3> >g[N];
struct edge{
	int x,y,w;
};
edge t[N];
vector<edge>e[N];
void init(int n){
	for(int i=1;i<=n;i++)
		f[i]=i; 
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
void tarjan(int x,int pre){
	dfn[x]=low[x]=++cur;
	for(auto i:g[x]){
		int y=i[0];
		if(!dfn[y])
			tarjan(y,i[2]),low[x]=min(low[x],low[y]),
			ans[i[1]]+=dfn[x]<low[y];
		else if(pre!=i[2])
			low[x]=min(low[x],dfn[y]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,init(n); 
	for(int i=1;i<=m;i++)
		cin>>t[i].x>>t[i].y>>t[i].w,b.push_back(t[i].w);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=m;i++)
		e[lower_bound(b.begin(),b.end(),t[i].w)-b.begin()+1].
			push_back({t[i].x,t[i].y,i});
	for(int i=1;i<=m;i++){
		for(edge j:e[i]){
			int id=j.w,fx=find(j.x),fy=find(j.y);
			if(fx^fy)
				ans[id]++,g[fx].push_back({fy,id,++cur}),
				g[fy].push_back({fx,id,cur});
		}
		for(edge j:e[i])
			merge(j.x,j.y);
	}
	cur=0;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]>1?"any\n":ans[i]?"at least one\n":"none\n");
}