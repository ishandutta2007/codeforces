#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

bool check(int c0,int c1,int cq){
	if(c0>c1+cq||c1>c0+cq)return false;
	return true;
}

struct tree_diameter{
	const long long X = 1000000000000000000;
	pair<long long,vector<int>> get(vector<vector<pair<int,long long>>> &E){
		vector<long long> dis = bfs(E,0);
		long long maxi = -1;
		int ind = 0;
		for(int i=0;i<E.size();i++){
			if(dis[i]>maxi){
				maxi=dis[i];
				ind=i;
			}
		}

		dis = bfs(E,ind);
		maxi = -1;

		for(int i=0;i<E.size();i++){
			if(dis[i]>maxi){
				maxi=dis[i];
				ind=i;
			}
		}

		vector<int> ret;
		ret.push_back(ind);
		while(dis[ind]!=0LL){
			for(int i=0;i<E[ind].size();i++){
				if(dis[ind] == dis[E[ind][i].first] + E[ind][i].second){
					ind = E[ind][i].first;
					ret.push_back(ind);
					break;
				}
			}
		}
		
		return make_pair(maxi,ret);
		
	}
	
	pair<long long,vector<int>> get(vector<vector<int>> &E){
		vector<vector<pair<int,long long>>> e(E.size(),vector<pair<int,long long>>());
		for(int i=0;i<E.size();i++){
			for(int j=0;j<E[i].size();j++){
				e[i].emplace_back(E[i][j],1LL);
			}
		}
		return get(e);
	}
	
	vector<long long> bfs(vector<vector<pair<int,long long>>> &E,int start){
		vector<long long> dis(E.size(),X);
		dis[start] = 0LL;
		queue<int> Q;
		Q.push(start);
		
		while(Q.size()!=0){
			int u = Q.front();
			Q.pop();
			for(int i=0;i<E[u].size();i++){
				int v = E[u][i].first;
				if(dis[v]!=X)continue;
				dis[v] = dis[u] + E[u][i].second;
				Q.push(v);
			}
		}
		return dis;
	}
	
};

int main(){

	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,a,b,da,db;
		cin>>n>>a>>b>>da>>db;
		
		vector<vector<pair<int,long long>>> E(n,vector<pair<int,long long>>());
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].emplace_back(v,1);
			E[v].emplace_back(u,1);
		}
		tree_diameter X;
		
		a--;b--;
		if(X.bfs(E,a)[b]<=da){
			cout<<"Alice"<<endl;
			continue;
		}
		
		db = min(db,(int)X.get(E).first);
		
		if(2*da + 1 <= db)cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
		
		
	}
    
    return 0;
}