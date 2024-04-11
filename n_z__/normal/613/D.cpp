#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define int long long 
struct custom_hash{static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
main(){
	int n;
	cin>>n;
	vector<int>e[n+1];
	for(int x=1;x<n;x++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int m;
	cin>>m;
	unordered_set<int,custom_hash>a[n+1],b[n+1];
	for(int x=1;x<=m;x++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int y;
			cin>>y;
			a[y].insert(x);
		}
	}
	vector<int>ans(m+1);
	function<void(int,int)>dfs=[&](int u,int fa){
		unordered_set<int,custom_hash>fk;
		for(auto v:e[u])
		if(v!=fa)
		{
			dfs(v,u);
			for(auto q:a[v])
			if(a[u].count(q))ans[q]=-1;
			if(b[u].size()<b[v].size())swap(b[u],b[v]);
			for(auto q:b[v])
			if(ans[q]!=-1)
			if(a[u].count(q))ans[q]++;
			else if(b[u].count(q))fk.insert(q);
			else b[u].insert(q);
		}
		for(auto q:fk)
		{
			b[u].erase(q);
			if(ans[q]!=-1)ans[q]++;
		}
		for(auto q:a[u])
		if(b[u].count(q)){if(ans[q]!=-1)ans[q]++;}
		else b[u].insert(q);
	};
	dfs(1,0);
	for(int x=1;x<=m;x++)
	cout<<ans[x]<<endl;
}