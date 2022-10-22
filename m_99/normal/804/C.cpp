#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int n,m;
vector<vector<int>> s;
vector<int> c;
vector<vector<int>> E;

void dfs(int cur,int p){
	set<int> used;
	rep(i,s[cur].size()){
		int to = s[cur][i];
		if(c[to]!=-1)used.insert(c[to]);
	}
	int last = 0;
	rep(i,s[cur].size()){
		int to = s[cur][i];
		if(c[to]!=-1)continue;
		while(used.count(last))last++;
		c[to] = last;
		last++;
	}
	
	
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur);
	}
}

int main(){
	
	cin>>n>>m;
	s.resize(n);
	rep(i,n){
		int t;
		scanf("%d",&t);
		s[i].resize(t);
		rep(j,t){
			int cc;
			scanf("%d",&cc);
			cc--;
			s[i][j] = cc;
		}
	}
	
	E.resize(n);
	rep(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	c.resize(m,-1);
	
	dfs(0,-1);
	rep(i,m){
		if(c[i]==-1)c[i] = 0;
	}
	
	int ans = 0;
	rep(i,c.size()){
		c[i]++;
		ans = max(ans,c[i]);
	}
	
	cout<<ans<<endl;
	rep(i,c.size()){
		if(i!=0)printf(" ");
		printf("%d",c[i]);
	}
	cout<<endl;
	
    return 0;
}