#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

vector<int> grundy;
vector<int> p;
void dfs(vector<vector<int>> &E,int cur,int par){
	p[cur] = par;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==par)continue;
		dfs(E,to,cur);
		grundy[cur] ^= grundy[to] + 1;
	}
}

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

int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> E(n);
	rep(i,n-1){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	grundy.resize(n,0);
	p.resize(n,-1);
	//dfs(E,0,-1);
	
	{
		stack<pair<int,int>> S;
		S.emplace(0,0);
		while(S.size()>0){
			auto tp = S.top();
			S.pop();
			if(tp.second==0){
				S.emplace(tp.first,1);
				rep(i,E[tp.first].size()){
					int to = E[tp.first][i];
					if(p[tp.first]==to)continue;
					p[to] = tp.first;
					S.emplace(to,0);
				}
			}
			else{
				rep(i,E[tp.first].size()){
					int to = E[tp.first][i];
					if(p[tp.first]==to)continue;
					grundy[tp.first] ^= grundy[to]+1;
				}
			}
		}
	}
	
	lca L(0,E);

	vector<bool> f(n,false);
	int c2 = 0;
	int cg = 0;
	int ce = 0;
	string ans(n,'0');
	
	rep(i,n){
		int d = L.depth[i];
		if(!f[i]){
			int ok = 0,ng = d+1;
			while(ng-ok>1){
				int mid = (ok+ng)/2;
				int u = L.kth_parent(i,mid);
			
				if(u<0 || f[u])ng = mid;
				else ok = mid;
			}
			
			while(ok>=0){
				int u = L.kth_parent(i,ok);
				if(u<0)break;
				if(u!=0){
					cg ^= grundy[u]+1;
					if(grundy[u]+1>=2)c2--;
				}
				
				f[u] = true;
				rep(j,E[u].size()){
					int to = E[u][j];
					if(to==p[u])continue;
					cg ^= grundy[to]+1;
					if(grundy[to]+1>=2)c2++;
				}
				ce++;
				ok--;
			}
		}
		if(ce%2==1){
			if(cg==0)ans[i] = '2';
			else ans[i] = '1';
		}
		else{
			if(cg==0)ans[i] = '1';
			else if(c2>0&&cg==0)ans[i] = '2';
			else if(cg==1)ans[i] = '2';
			else ans[i] = '1';
		}
	}
	
	cout<<ans<<endl;
	
		
	return 0;
}