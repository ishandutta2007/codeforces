#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo N
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

vector<int> G;
vector<int> sz;
void dfs(vector<vector<int>> &E,int now,int p){
	sz[now] = 1;
	bool f = true;
	rep(i,E[now].size()){
		int to = E[now][i];
		if(to==p)continue;
		dfs(E,to,now);
		sz[now] += sz[to];
		if(sz[to]*2>E.size())f=false;
	}
	if((E.size()-sz[now])*2>E.size())f=false;
	if(f)G.push_back(now);
}

void dfs2(vector<vector<int>> &E,int now,int p){

	rep(i,E[now].size()){
		int to = E[now][i];
		if(to==p)continue;
		sz[to] = sz[now]+1;
		dfs2(E,to,now);
	}
}

int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		int n;
		cin>>n;
		
		vector<vector<int>> E(n,vector<int>());
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		G.resize(0);
		sz.resize(0);
		sz.resize(n,0);
		dfs(E,0,-1);
		int T;
		rep(i,E.size()){
			if(E[i].size()==1){
				T = i;
				break;
			}
		}
		if(G.size()==1){
			printf("%d %d\n",T+1,E[T][0]+1);
			printf("%d %d\n",T+1,E[T][0]+1);
		}
		else{
			printf("%d %d\n",T+1,E[T][0]+1);
			sz.resize(0);
			sz.resize(n,0);
			dfs2(E,T,-1);
			if(sz[G[0]]>sz[G[1]])swap(G[0],G[1]);
			printf("%d %d\n",T+1,G[1]+1);
		}
	}
	
    return 0;
}