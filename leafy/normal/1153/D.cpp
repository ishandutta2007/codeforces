#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,opt[N],fa[N],cnt=0,num[N];
vector<int> G[N];
void dfs(int u){
	if(opt[u]) num[u]=1e9;
	if(!G[u].size()){
		cnt++;num[u]=1;
	}
	for(int v:G[u]){
		dfs(v);
		if(opt[u]) num[u]=min(num[u],num[v]);
		else num[u]+=num[v];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>opt[i];
	for(int i=2;i<=n;i++) cin>>fa[i],G[fa[i]].push_back(i);
	dfs(1);
	cout<<cnt-num[1]+1;
	return 0;
}