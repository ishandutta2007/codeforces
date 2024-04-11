#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

vector<vector<int>> E;
vector<int> G;
vector<int> h;

void dfs(int cur){
	if(G[cur]!=-1)return;
	set<int> S;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		dfs(to);
		S.insert(G[to]);
	}
	
	rep(i,Inf){
		if(!(S.count(i))){
			G[cur] = i;
			break;
		}
	}
}

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	h.resize(n);
	rep(i,n)scanf("%d",&h[i]);
	
	E.resize(n);
	G.resize(n,-1);
	
	rep(i,m){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		
		E[u].push_back(v);
	}
	
	rep(i,n){
		dfs(i);
	}
	
	vector<int> Gs(1000,0);
	
	
	
	rep(i,n){
		Gs[G[i]] ^= h[i];
	}

	
	for(int i=999;i>=0;i--){
		if(Gs[i]==0)continue;
		int maxi = -1,ind = -1;
		rep(j,n){
			if(G[j]==i){
				if((Gs[i]^h[j])<h[j]){
					h[j] = Gs[i]^h[j];
					Gs[i] = 0;
					ind = j;
					break;
				}
			}
		}

		h[ind] = Gs[i]^h[ind];
		Gs[i] = 0;
		
		rep(j,E[ind].size()){
			int to = E[ind][j];
			h[to] = Gs[G[to]]^h[to];
			Gs[G[to]] = 0;
		}
		cout<<"WIN"<<endl;
		rep(j,n){
			if(j!=0)printf(" ");
			printf("%d",h[j]);
		}
		cout<<endl;
		return 0;
		
	}
	
	cout<<"LOSE"<<endl;
		
	
	return 0;
}