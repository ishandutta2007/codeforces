#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int n,m,x,y,cur,dfn[N],low[N];
vector<pair<int,int> >ans;
vector<int>e[N];
void dfs(int x,int fa){
	dfn[x]=low[x]=++cur;
	for(int y:e[x])
		if(!dfn[y]){
			dfs(y,x),low[x]=min(low[x],low[y]);
			ans.push_back({x,y});
			if(low[y]>dfn[x])
				cout<<"0\n",exit(0);
		}else if(y!=fa){
			low[x]=min(low[x],dfn[y]);
			if(dfn[y]<dfn[x])
				ans.push_back({x,y});
		}
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;m--;)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	for(auto&i:ans)
		cout<<i.first<<" "<<i.second<<"\n";
}