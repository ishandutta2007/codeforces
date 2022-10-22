#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000



int main(){
	
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> Q;
	
	vector<vector<pair<long long,int>>> E(n);
	
	rep(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		
		x--;y--;
		
		E[x].emplace_back(z*2,y);
		E[y].emplace_back(z*2,x);
	}
	
	vector<long long> dis(n,Inf);
	dis[0] = 0;
	
	Q.emplace(0,0);
//	int ans = 0;
	rep(i,k){
		int x,y;
		scanf("%d %d",&x,&y);
		x--;
		
		dis[x] = min(dis[x],(long long)y*2+1);

		
	}
	
	int ans = k;
	
	rep(i,n){
		if(i!=0&&dis[i]!=Inf){
			Q.emplace(dis[i],i);
			ans--;
		}
	}
	
	
	
	while(Q.size()!=0){
		long long D = Q.top().first;
		int u = Q.top().second;
		Q.pop();
		
		if(dis[u]!=D){
			if(D&1)ans++;
			continue;
		}
		if(D&1){
			D--;
		}
		
		rep(i,E[u].size()){
			int v = E[u][i].second;
			long long D2 = E[u][i].first;
			if(dis[v]>D+D2){
				dis[v] = D+D2;
				Q.emplace(dis[v],v);
			}
		}
	}
	
	//rep(i,n)cout<<dis[i]<<endl;
	
	cout<<ans<<endl;
	
    return 0;
}