#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

vector<int> bfs(vector<vector<int>> &E){
	vector<int> ret(E.size(),Inf);
	ret[0] = 0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()!=0){
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



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<bool>> e(n,vector<bool>(n,false));
	
	rep(i,m){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		e[a][b]=  true;
		e[b][a] = true;
	}
	
	vector<vector<int>> E1(n,vector<int>());
	auto E2 = E1;
	
	rep(i,n){
		rep(j,n){
			if(i==j)continue;
			if(e[i][j])E1[i].push_back(j);
			else E2[i].push_back(j);
		}
	}
	
	vector<int> d1 = bfs(E1),d2 = bfs(E2);
	
	if(d1.back()==Inf||d2.back()==Inf){
		cout<<-1<<endl;
		return 0;
	}
	
	rep(i,n){
		vector<int> ne;
		rep(j,E1[i].size()){
			if(d1[i]+1==d1[E1[i][j]])ne.push_back(E1[i][j]);
		}
		ne.push_back(i);
		E1[i] = ne;
	}
	rep(i,n){
		vector<int> ne;
		rep(j,E2[i].size()){
			if(d2[i]+1==d2[E2[i][j]])ne.push_back(E2[i][j]);
		}
		ne.push_back(i);
		E2[i] = ne;
	}
	
	vector<vector<int>> dp(n,vector<int>(n,Inf));
	dp[0][0] = 0;
	
	queue<pair<int,int>> Q;
	Q.emplace(0,0);
	
	while(Q.size()!=0||dp.back().back()==Inf){
		int u = Q.front().first;
		int v = Q.front().second;
		Q.pop();
		rep(i,E1[u].size()){
			rep(j,E2[v].size()){
				int U = E1[u][i],V = E2[v][j];
				if(dp[U][V]!=Inf)continue;
				if(U!=n-1&&U==V)continue;
				dp[U][V] = dp[u][v] + 1;
				Q.emplace(U,V);
			}
		}
	}
	
	cout<<dp.back().back()<<endl;
	
    return 0;
}