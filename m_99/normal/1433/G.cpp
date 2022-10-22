#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000003
vector<vector<pair<int,int>>> E;

vector<int> get(int start){
	vector<int> dis(E.size(),Inf);
	dis[start] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.emplace(0,start);
	while(Q.size()>0){
		int D = Q.top().first;
		int u = Q.top().second;
		Q.pop();
		if(dis[u]!=D)continue;
		rep(i,E[u].size()){
			int v = E[u][i].first;
			int D2 = E[u][i].second;
			if(dis[v]>D+D2){
				dis[v] = D+D2;
				Q.emplace(dis[v],v);
			}
		}
	}
	return dis;
}

int main(){	
	
	int n,m,K;
	cin>>n>>m>>K;
	
	E.resize(n,vector<pair<int,int>>());
	
	rep(i,m){
		int x,y,w;
		cin>>x>>y>>w;
		x--;y--;
		E[x].emplace_back(y,w);
		E[y].emplace_back(x,w);
	}
	
	vector<vector<int>> dis(n);
	rep(i,n){
		dis[i] = get(i);
	}
	
	vector<int> a(K),b(K);
	rep(i,K){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
	}
	
	int ans = Inf;
	
	rep(i,E.size()){
		rep(j,E[i].size()){
			int u = i;
			int v = E[i][j].first;
			if(u>v)continue;
			int sum = 0;
			rep(k,K){
				sum += min({dis[a[k]][b[k]],dis[a[k]][u]+dis[v][b[k]],dis[a[k]][v]+dis[u][b[k]]});
			}
			ans = min(ans,sum);
		}
	}
	
	cout<<ans<<endl;
		
    return 0;
}