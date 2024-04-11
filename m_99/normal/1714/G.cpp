#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 10000000000000000

struct lca{
	
	vector<int> depth;
	vector<vector<int>> parents;
	
	int max_j=18;
	
	lca(int n,vector<vector<int>> &E){
		rep(i,100){
			if((1<<i)>E.size()){
				max_j = i;
				break;
			}
		}
		depth.assign(E.size(),-1);
		parents.assign(E.size(),vector<int>(max_j,-1));
		
		
		
		stack<int> s;
		s.push(n);
		depth[n] = 0;
		while(s.size()!=0){
			int k = s.top();
			s.pop();
			for(int i=0;i<E[k].size();i++){
				int x = E[k][i];
				if(depth[x]!=-1)continue;
				s.push(x);
				depth[x] = depth[k]+1;
				for(int j=0;j<max_j;j++){
					if(j==0){
						parents[x][j] = k;
					}
					else{
						parents[x][j] = parents[parents[x][j-1]][j-1];
					}
					if(parents[x][j] == -1)break;
				}
			}
		}
	}
	
	
	int kth_parent(int u,int k){
		for(int i=0;i<max_j;i++){
			if(k==0)break;
			if(u==-1)break;
			if(k%2){
				u = parents[u][i];
			}
			k/=2;
		}
		return u;
	}
	
	int query(int u,int v){
		if(depth[u]<depth[v])swap(u,v);
		u = kth_parent(u,depth[u]-depth[v]);
		
		if(u==v){
			return u;
		}
		
		for(int i=max_j-1;i>=0;i--){
			if(parents[u][i]!=parents[v][i]){
				u = parents[u][i];
				v = parents[v][i];
			}
		}
		
		return parents[u][0];
		
	}
	
	int get_distance(int u,int v){
		return depth[u]+depth[v]-2*depth[query(u,v)];
	}
	
	
};

vector<long long> get(vector<vector<pair<int,int>>> E){
	int n  =E.size();
	vector<long long> ret(n,Inf);
	ret[0] = 0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i].first;
			long long dd = ret[u] + E[u][i].second;
			ret[v] = dd;
			Q.push(v);
		}
	}
	return ret;
}

int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<vector<pair<int,int>>> Ea(n),Eb(n);
		vector<vector<int>> E(n);
		rep(i,n-1){
			int p,a,b;
			scanf("%d %d %d",&p,&a,&b);
			p--;
			E[p].push_back(i+1);
			Ea[p].emplace_back(i+1,a);
			Eb[p].emplace_back(i+1,b);
		}
		auto da = get(Ea),db = get(Eb);
		
		lca L(0,E);
		for(int i=1;i<n;i++){
			if(i!=1)printf(" ");
			long long dd = da[i];
			int d2 = L.get_distance(0,i);
			int ok = 0,ng = d2+1;
			while(ng-ok>1){
				int mid = (ok+ng)/2;
				int tu = L.kth_parent(i,d2 - mid);
				if(db[tu] > dd)ng = mid;
				else ok = mid;
			}
			printf("%d",ok);
		}
		cout<<endl;
		
	}
	
    return 0;
}