#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

template <typename T>
struct Dinic{
	struct edge{
		int to;
		T weight;
		int ind;
	};
	vector<vector<edge>> E;
	T inf;
	
	Dinic(vector<vector<pair<int,T>>> &e,T iv = 1000000001){
		inf = iv;
		E.resize(e.size(),vector<edge>());
		for(int i=0;i<e.size();i++){
			for(int j=0;j<e[i].size();j++){
				edge t = {e[i][j].first,e[i][j].second,0};
				E[i].push_back(t);
			}
		}
		for(int i=0;i<e.size();i++){
			for(int j=0;j<e[i].size();j++){
				E[i][j].ind = E[E[i][j].to].size();
				edge t = {i,0,j};
				E[E[i][j].to].push_back(t);
			}
		}
	}
	
	T maximum_flow(int s,int t){
		
		T ret = 0;
		
		while(true){
			vector<int> dis(E.size(),-1);
			queue<int> Q;
			Q.push(s);
			dis[s] = 0;
			while(Q.size()!=0){
				int u = Q.front();
				Q.pop();
				for(int i=0;i<E[u].size();i++){
					if(E[u][i].weight<=0)continue;
					int v = E[u][i].to;
					if(dis[v]!=-1)continue;
					dis[v] = dis[u]+1;
					Q.push(v);
				}
			}
			if(dis[t]==-1)break;
			
			vector<int> it(E.size(),0);
			
			while(true){
				T F = dfs(s,t,inf,it,dis);
				if(F==0)break;
				ret+=F;
			}
		}
		return ret;
	}
	
	T dfs(int now,int t,T f,vector<int> &it,vector<int> &dis){
		if(now==t)return f;
		
		for(int &i=it[now];i<E[now].size();i++){
			int to = E[now][i].to;
			T weight = E[now][i].weight;
			if(weight<=0||dis[now]+1!=dis[to]){
				continue;
			}
			T F = dfs(to,t,min(f,weight),it,dis);
			if(F!=0){
				E[now][i].weight-=F;
				E[E[now][i].to][E[now][i].ind].weight+=F;
				return F;
			}
		}
		return 0;
	}
	
};

int main(){

	int n,m;
	cin>>n>>m;
	
	vector<string> S(n);
	rep(i,n)cin>>S[i];
	
	vector<vector<pair<int,int>>> E(n*m*3+2,vector<pair<int,int>>());
	
	int s = n*m*3;
	int t = s+1;
	
	rep(i,n){
		rep(j,m){
			if(S[i][j]=='.')continue;
			int x = 3*(i*m+j);
			E[s].emplace_back(x,Inf);
			E[x+2].emplace_back(t,Inf);
			if(i!=0&&S[i-1][j]=='#'){
				E[x].emplace_back(x+1,0);
				int y = 3*((i-1)*m+j);
				E[y+1].emplace_back(x+1,1);
			}
			else{
				E[x].emplace_back(x+1,1);
			}
			if(j!=0&&S[i][j-1]=='#'){
				E[x+1].emplace_back(x+2,0);
				int y = 3*(i*m+(j-1));
				E[x+1].emplace_back(y+1,1);
			}
			else{
				E[x+1].emplace_back(x+2,1);
			}
		}
	}
	
	Dinic<int> D(E);
	cout<<D.maximum_flow(s,t)<<endl;
	
    return 0;
}