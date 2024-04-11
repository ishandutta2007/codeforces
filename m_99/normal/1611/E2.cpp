#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		vector<int> x(k);
		queue<int> Q;
		vector<int> dis(n,Inf);
		rep(i,k){
			scanf("%d",&x[i]);
			x[i]--;
			Q.push(x[i]);
			dis[x[i]] = 0;
		}
		
		vector<vector<int>> E(n);
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			rep(i,E[u].size()){
				int v=  E[u][i];
				if(dis[v]!=Inf)continue;
				dis[v] = dis[u]+ 1;
				Q.push(v);
			}
		}
		
		vector<int> d2(n,Inf);
		d2[0] = 0;
		Q.push(0);
		int ans = 0;
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			rep(i,E[u].size()){
				int v = E[u][i];
				if(d2[v]!=Inf)continue;
				if(d2[u] + 1 < dis[v]){
					d2[v] = d2[u] + 1;
					Q.push(v);
				}
				else ans++;
			}
		}
		bool f = false;
		rep(i,n){
			if(i==0)continue;
			if(E[i].size()==1 && d2[i]!=Inf)f = true;
		}
		if(f)printf("-1\n");
		else printf("%d\n",ans);
		
	}
		
	return 0;
}