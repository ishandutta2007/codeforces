#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int const N=23333;
int t,n,m,cur,tot,c[N],dfn[N],low[N],vis[N],scc[N];
stack<int>seq;
vector<int>e[N];
set<pair<int,int> >s;
map<pair<int,int>,int>ord;
void tarjan(int x){
	dfn[x]=low[x]=++cur,vis[x]=1,seq.push(x);
	for(int y:e[x])
		if(!dfn[y])
			tarjan(y),low[x]=min(low[x],low[y]);
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	if(dfn[x]==low[x]){
		tot++;
		while(1){
			int t=seq.top();
			seq.pop(),vis[t]=0,scc[t]=tot;
			if(t==x)break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		s.insert({x,y});
		ord[{x,y}]=i;
	}
	for(auto i:s)
		for(auto j:s){
			int x=ord[i],y=ord[j];
			if(x==y)continue;
			auto ti=i,tj=j;
			if(ti.x>ti.y)swap(ti.x,ti.y);
			if(tj.x>tj.y)swap(tj.x,tj.y);
			if(ti.x>tj.x)swap(ti,tj);
			if(ti.y<=tj.x||tj.y<=ti.y||ti.x==tj.x)continue;
			e[x].push_back(y+m);
			e[x+m].push_back(y);
		}
	for(int i=1;i<=m+m;i++)
		if(!dfn[i])
			tarjan(i);
	int flg=1;
	for(int i=1;i<=m;i++)
		flg&=scc[i]!=scc[i+m];
	if(!flg)
		cout<<"Impossible\n",exit(0);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;cout<<(vis[scc[i++]]?'i':'o'))
		if(!vis[scc[i]]&&!vis[scc[i+m]])
			vis[scc[i]]=1;
	cout<<"\n";
}