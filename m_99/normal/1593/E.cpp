#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<vector<int>> E(n);
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		vector<int> d(n,0);
		vector<bool> f(n,false);
		int ans = n;
		queue<int> Q;
		rep(i,n){
			d[i] = E[i].size();
			if(d[i] <= 1){
				Q.push(i);
				f[i] = true;
			}
		}
		
		rep(i,k){
			if(ans==0)break;
			queue<int> nQ;
			while(Q.size()>0){
				int u = Q.front();
				Q.pop();
				ans--;
				rep(j,E[u].size()){
					int v = E[u][j];
					d[v]--;
					if(d[v]<=1 && !f[v]){
						nQ.push(v);
						f[v] = true;
					}
				}
			}
			swap(Q,nQ);
		}
		
		printf("%d\n",ans);
		
	}
	
	return 0;
}