#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
vector<vector<int>> E;
vector<bool> dp;
int ans = 0;

void dfs(int cur,int p){
	int c = 0;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur);
		if(dp[to])c++;
	}
	if(c==0){
		dp[cur] = true;
	}
	else{
		dp[cur] = false;
		ans += c-1;
	}
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		ans = 0;
		int n;
		scanf("%d",&n);
		dp.assign(n,false);
		E.assign(n,vector<int>());
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		dfs(0,-1);
		ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}