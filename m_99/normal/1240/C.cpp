#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int n,k;
vector<vector<pair<int,long long>>> E;
vector<long long> dp0,dp1;

void dfs(int cur,int p){
	
	dp0[cur] = 0LL,dp1[cur] = 0LL;
	vector<long long> vs;
	rep(i,E[cur].size()){
		int to = E[cur][i].first;
		long long w = E[cur][i].second;
		if(to==p)continue;
		dfs(to,cur);
		
		dp0[cur] += dp0[to];
		dp1[cur] += dp0[to];
		vs.push_back(max(0LL,dp1[to]+w-dp0[to]));
		
	}
	
	sort(vs.rbegin(),vs.rend());
	rep(i,vs.size()){
		if(i<k)dp0[cur] += vs[i];
		if(i<(k-1))dp1[cur] += vs[i];
	}
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		E.resize(0);
		dp0.resize(0),dp1.resize(0);
		scanf("%d %d",&n,&k);
		E.resize(n);
		rep(i,n-1){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			u--;v--;
			E[u].emplace_back(v,w);
			E[v].emplace_back(u,w);
		}
		dp0.resize(n,-Inf),dp1.resize(n,-Inf);
		dfs(0,-1);
		printf("%lld\n",max(dp0[0],dp1[0]));
		
	}
	
    return 0;
}