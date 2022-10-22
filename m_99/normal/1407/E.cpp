
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<vector<pair<int,int>>> E(n,vector<pair<int,int>>());
	rep(i,m){
		int u,v,t;
		cin>>u>>v>>t;
		u--;v--;
		E[v].emplace_back(u,t);
	}
	
	vector<int> dis0(n,Inf),dis1(n,Inf);
	dis0.back() = 0;
	dis1.back() = 0;
	queue<pair<int,int>> Q;
	Q.emplace(0,n-1);
	string ans(n,'0');
	while(Q.size()!=0){
		int D = Q.front().first;
		int u = Q.front().second;
		Q.pop();
		
		rep(i,E[u].size()){
			int v = E[u][i].first;
			int c = E[u][i].second;
			if(dis0[v]!=Inf&&dis1[v]!=Inf)continue;
			if(c==0)dis0[v] = min(dis0[v],D+1);
			if(c==1)dis1[v] = min(dis1[v],D+1);
			if(dis0[v]!=Inf&&dis1[v]!=Inf){
				Q.emplace(max(dis0[v],dis1[v]),v);
				
			}
		}
	}
	rep(i,n){
		if(dis0[i]>dis1[i])ans[i] = '0';
		else ans[i]='1';
	}
	int Ans = max(dis0[0],dis1[0]);
	if(Ans==Inf)cout<<-1<<endl;
	else cout<<Ans<<endl;
	cout<<ans<<endl;
	
    return 0;
}