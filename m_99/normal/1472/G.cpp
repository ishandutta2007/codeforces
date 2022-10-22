#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

vector<int> get(vector<vector<int>> E){
	vector<int> ret(E.size(),Inf);
	queue<int> Q;
	Q.push(0);
	ret[0] = 0;
	
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		
		rep(i,E[u].size()){
			int v = E[u][i];
			if(ret[v]!=Inf)continue;
			ret[v] = ret[u] + 1;
			Q.push(v);
		}
	}
	return ret;
}

vector<int> get(vector<vector<int>> E,vector<int> d){
	vector<int> ret(E.size(),Inf);

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	rep(i,d.size()){
		ret[i*2] = d[i];
		Q.emplace(ret[i*2],i*2);
	}
	
	while(Q.size()>0){
		int D = Q.top().first;
		int u = Q.top().second;
		Q.pop();
		if(ret[u]!=D)continue;
		rep(i,E[u].size()){
			int v = E[u][i];
			int D2 = d[v>>1];
			if(ret[v]>min(D,D2)){
				ret[v] = min(D,D2);
				Q.emplace(ret[v],v);
			}
		}
	}
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<vector<int>> E(n);
		rep(i,m){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			
			E[u].push_back(v);
		}
		
		vector<int> d = get(E);
		
		vector<vector<int>> E2(n*2);
		
		rep(i,n){
			rep(j,E[i].size()){
				int u = E[i][j],v = i;
				if(d[u]>d[v]){
					E2[u*2].push_back(v*2);
					E2[u*2+1].push_back(v*2+1);
				}
				else{
					E2[u*2].push_back(v*2+1);
				}
			}
		}
		
		vector<int> ans = get(E2,d);
		
		rep(i,n){
			if(i!=0)printf(" ");
			int A = min(ans[i*2],ans[i*2+1]);
			printf("%d",A);
		}
		printf("\n");
		
	}
	
    return 0;
}