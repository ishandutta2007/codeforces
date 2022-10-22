#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		a[i]--;
	}
	
	vector<vector<int>> E(n);
	rep(i,m){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	vector d(n,vector<int>(k));
	
	rep(i,k){
		queue<int> Q;
		vector<int> dis(n,Inf);
		rep(j,n){
			if(a[j]==i){
				dis[j] = 0;
				Q.push(j);
			}
		}
		
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			rep(j,E[u].size()){
				int v = E[u][j];
				if(dis[v]!=Inf)continue;
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
		rep(j,n){
			d[j][i] = dis[j];
		}
	}
	
	vector<int> ans(n,0);
	rep(i,n){
		sort(d[i].begin(),d[i].end());
		rep(j,s)ans[i] += d[i][j];
	}
	
	
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;
	
	
	return 0;
}