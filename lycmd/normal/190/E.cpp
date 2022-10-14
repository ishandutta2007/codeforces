#include<bits/stdc++.h>
using namespace std;
int const N=500010;
int n,m,vis[N],f[N];
map<int,vector<int> >ans;
vector<int>e[N],t;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx^fy)f[fx]=fy;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int x,y;m--;){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	int p=1;
	for(int i=1;i<=n;i++)
		if(e[i].size()<e[p].size())
			p=i;
	for(int i:e[p])vis[i]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			merge(i,p);
	for(int i=1;i<=n;i++)
		if(vis[i]){
			t.clear();
			t.resize(n+1,0);
			for(int j:e[i])t[j]=1;
			for(int j=1;j<=n;j++)
				if(!t[j])
					merge(i,j);
		}
	for(int i=1;i<=n;i++)
		ans[find(i)].push_back(i);
	cout<<ans.size()<<"\n";
	for(auto&i:ans){
		cout<<i.second.size();
		for(int j:i.second)
			cout<<" "<<j;
		cout<<"\n";
	}
}