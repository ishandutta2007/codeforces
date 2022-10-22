#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000
vector<vector<int>> E;
vector<int> pos;
vector<int> ind;
void dfs0(int now){
	ind[now] = pos.size();
	pos.push_back(now);

	rep(i,E[now].size()){
		int to = E[now][i];
		dfs0(to);
	}
}
struct lca{
	
	vector<int> depth;//depth[i] i
	vector<vector<int>> parents;//parents[i][j] i2^j
	
	int max_j = 30;
	
	lca(int n,vector<vector<int>> &E){
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
	
	//uk
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

int main(){

	int n,q;
	cin>>n>>q;
	
	E.resize(n,vector<int>());
	
	rep(i,n-1){
		int p;
		scanf("%d",&p);
		p--;
		E[p].push_back(i+1);
	}
	
	lca L(0,E);
	
	ind.resize(n);
	dfs0(0);
	
	
	rep(i,q){
		int u,k;
		scanf("%d %d",&u,&k);
		u--;
		int x = ind[u];
		x += k-1;
		if(x>=n){
			printf("-1\n");
			continue;
		}
		//cout<<x<<endl;
		int y = pos[x];
		if(L.query(y,u)==u)printf("%d\n",y+1);
		else printf("-1\n");
	}
	
	return 0;
}