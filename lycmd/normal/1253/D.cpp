#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,l,r,vis[N];
vector<int>e[N];
vector<pair<int,int> >p;
void dfs(int x){
	l=min(l,x),r=max(r,x),vis[x]=1;
	for(int y:e[x])
		if(!vis[y])
			dfs(y);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;m--;){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			l=n,r=0,dfs(i),p.push_back({l,r});
	int ans=p.size()-1,w=p[0].second;
	sort(p.begin(),p.end());
	for(auto i:p)
		ans-=w<i.first,w=max(w,i.second);
	cout<<ans<<"\n";
}