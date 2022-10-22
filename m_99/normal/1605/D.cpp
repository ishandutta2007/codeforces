#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<vector<int>> E(n);
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		vector<int> d(n,Inf);
		queue<int> Q;
		Q.push(0);
		d[0] = 0;
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			rep(i,E[u].size()){
				int v = E[u][i];
				if(d[v]!=Inf)continue;
				d[v] = d[u]+1;
				Q.push(v);
			}
		}
		
		vector<vector<int>> num(18,vector<int>());
		for(int i=1;i<=n;i++){
			int ind = 0;
			rep(j,18){
				if((i>>j)&1)ind = j;
			}
			num[ind].push_back(i);
		}
		int sum = 0;
		vector<vector<int>> ind(2);
		vector<int> ans(n,-1);
		rep(i,n){
			d[i] &= 1;
			sum += d[i];
			ind[d[i]].push_back(i);
		}
		for(int i=17;i>=0;i--){
			if(sum>=num[i].size()){
				sum -= num[i].size();
				rep(j,num[i].size()){
					ans[ind[1].back()] = num[i][j];
					ind[1].pop_back();
				}
			}
			else{
				rep(j,num[i].size()){
					ans[ind[0].back()] = num[i][j];
					ind[0].pop_back();
				}
				
			}
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
				
	}
	
	return 0;
}