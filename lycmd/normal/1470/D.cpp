#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int t,n,m,f[N],vis[N];
vector<int>e[N],ans;
void dfs(int x){
	vis[x]=1;
	int flg=0;
	for(int y:e[x])
		flg|=f[y];
	if(f[x]=!flg)
		ans.push_back(x);
	for(int y:e[x])
		if(!vis[y])
			dfs(y);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			e[i].clear(),f[i]=vis[i]=0;
		ans.clear();
		for(int x,y;m--;){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1);
		int flg=1;
		for(int i=1;i<=n;i++)
			flg&=vis[i];
		if(!flg)
			cout<<"NO\n";
		else{
			cout<<"YES\n"<<ans.size()<<"\n";
			for(int i:ans)
				cout<<i<<" ";
			cout<<"\n"; 
		}
	}
}