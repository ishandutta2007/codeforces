#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000005

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<vector<pair<int,int>>> E(n);
	rep(i,m){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		u--;v--;
		
		E[u].emplace_back(v,w);
		E[v].emplace_back(u,w);
	}
	
	vector<int> dis(n*55,Inf);
	dis[0] = 0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.emplace(0,0);
	
	while(Q.size()>0){
		int x = Q.top().second;
		int D = Q.top().first;
		int u = x / 55;
		int w0 = x % 55;
		Q.pop();
		
		if(dis[x]!=D)continue;
		
		if(w0==0){
			rep(i,E[u].size()){
				int v = E[u][i].first;
				int w1 = E[u][i].second;
				int y = v*55 + w1;
				if(dis[y]>D){
					dis[y] = D;
					Q.emplace(D,y);
				}
			}
		}
		else{
			rep(i,E[u].size()){
				int v = E[u][i].first;
				int w1 = E[u][i].second;
				int y = v*55;
				int d = (w0+w1);
				d *= d;
				if(dis[y]>D + d){
					dis[y] = D + d;
					Q.emplace(D + d,y);
				}
			}
			
			
		}
	}
	
	vector<int> ans(n,Inf);
	rep(i,n){
		ans[i] = min(ans[i],dis[i*55]);
	}
	
	rep(i,n){
		if(i!=0)printf(" ");
		if(ans[i]==Inf)printf("-1");
		else printf("%d",ans[i]);
	}
	printf("\n");
	
	
    return 0;
}