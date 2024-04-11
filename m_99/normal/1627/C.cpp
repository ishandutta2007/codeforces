#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<vector<int>> E(n);
		vector<int> u(n-1),v(n-1);
		rep(i,n-1){
			scanf("%d %d",&u[i],&v[i]);
			u[i]--;v[i]--;
			E[u[i]].push_back(i);
			E[v[i]].push_back(i);
		}
		
		int M = 0;
		rep(i,n){
			M = max(M,(int)E[i].size());
		}
		if(M>=3){
			cout<<-1<<endl;
			continue;
		}
		
		int s;
		rep(i,n){
			if(E[i].size()<=1){
				s = i;
				break;
			}
		}
		vector<bool> f(n,false);
		f[s] = true;
		queue<int> Q;
		Q.push(s);
		vector<int> ind;
		while(Q.size()>0){
			int U = Q.front();
			Q.pop();
			ind.push_back(U);
			rep(i,E[U].size()){
				int ii = E[U][i];
				int V = u[ii] ^ v[ii] ^ U;
				if(f[V])continue;
				f[V] = true;
				Q.push(V);
			}
		}
		
		vector<int> ans(n-1);
		rep(i,n-1){
			rep(j,E[ind[i]].size()){
				int ii = E[ind[i]][j];
				int V = u[ii] ^ v[ii] ^ ind[i];
				if(ind[i+1] == V){
					if(i%2==0)ans[ii] = 2;
					else ans[ii] = 3;
					break;
				}
			}
		}
		rep(i,n-1){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}cout<<endl;
	}
	
	return 0;
}