#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

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

int main() {

	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	lca L(0,E);
	
	for(int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		
		int maxi = -1;
		int ind = 0;
		
		vector<int> v(k);
		for(int j=0;j<k;j++){
			scanf("%d",&v[j]);
			v[j]--;
			if(L.depth[v[j]]>maxi){
				maxi = L.depth[v[j]];
				ind = v[j];
			}
		}
		//cout<<ind<<endl;
		
		bool f = true;
		for(int j=0;j<k;j++){
			if(L.query(ind,v[j])==v[j])continue;
			if(L.query(ind,L.kth_parent(v[j],1))==L.kth_parent(v[j],1))continue;
			f=false;
			break;
		}
		
		if(f)printf("YES\n");
		else printf("NO\n");
	}

    return 0;
}