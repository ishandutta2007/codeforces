#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


struct HLD{
	vector<int> sz,parent,depth,root,pos;
	vector<int> arr;
	HLD(vector<vector<int>> &E){
		sz.resize(E.size(),1);
		parent.resize(E.size(),0);
		depth.resize(E.size(),0);
		root.resize(E.size(),0);
		pos.resize(E.size(),0);
		
		dfs(0,-1,E);
		dfs2(0,-1,E,0);
	}
	
	void dfs(int now,int p,vector<vector<int>> &E){
		parent[now] = p;
		if(p==-1){
			depth[now] = 0;
		}
		else{
			depth[now] = depth[p]+1;
		}
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(to==p)continue;
			dfs(to,now,E);
			sz[now] += sz[to];
		}
	}
	
	void dfs2(int now,int p,vector<vector<int>> &E,int r){
		pos[now] = arr.size();
		arr.push_back(now);
		root[now] = r;
		int maxi = 0;
		int ind = -1;
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(to==p)continue;
			if(maxi<sz[to]){
				maxi = sz[to];
				ind = to;
			}
		}
		if(ind==-1)return;
		dfs2(ind,now,E,r);
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(to==p||to==ind)continue;
			dfs2(to,now,E,to);
		}
	}
	
	vector<pair<int,int>> query(int u,int v){
		vector<pair<int,int>> ret;
		int t = 0;
		while(root[u]!=root[v]){
			if(depth[root[u]] <= depth[root[v]]){
				ret.insert(ret.begin()+t,{pos[root[v]], pos[v]});
				v = parent[root[v]];
			}
			else{
				ret.insert(ret.begin()+t,{pos[u],pos[root[u]]});
				u = parent[root[u]];
				t++;
			}
		}
		ret.insert(ret.begin()+t,{pos[u],pos[v]});
		return ret;
	}
	
	int lca(int u,int v){
		for(;;v=parent[root[v]]){
			if(pos[u]>pos[v])swap(u,v);
			if(root[u]==root[v])return u;
		}
	}
	
	int get_distance(int u,int v){
		return depth[u] + depth[v] - 2 * depth[lca(u,v)];
	}
	
};

int main(){
	
	int _t;
	//cin>>_t;
	_t = 1;
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> c(n);
		vector<int> ind;
		rep(i,n){
			scanf("%d",&c[i]);
			if(c[i])ind.push_back(i);
		}
		
		vector<vector<int>> E(n);
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		HLD H(E);
		vector<int> sum(n+1,0);
		rep(i,n){
			sum[H.pos[i]+1]+=c[i];
		}
		rep(i,n)sum[i+1] += sum[i];
		
		vector<int> ans(n,0);
		
		queue<int> Q;
		rep(i,ind.size()){
			Q.push(ind[i]);
			ans[ind[i]] = 1;
		}
		
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			bool F = binary_search(ind.begin(),ind.end(),u);
			rep(i,E[u].size()){
				int v = E[u][i];
				if(ans[v])continue;
				if(F){
					ans[v] = 1;
					Q.push(v);
					continue;
				}
				if(H.parent[u]==v){
					int l = H.pos[u];
					int r = H.pos[u] + H.sz[u];
					int num = sum[r] - sum[l];
					if(num >= 2){
						ans[v] = true;
						Q.push(v);
					}
				}
				else{
					int l = H.pos[v];
					int r = H.pos[v] + H.sz[v];
				
					int num = sum[r] - sum[l];
					/*if(v==4){
						cout<<l<<','<<r<<','<<u<<','<<v<<','<<sum[r]<<','<<sum[l]<<','<<num<<endl;
					}
					*/
					if(num<=ind.size()-2){
						ans[v] = true;
						Q.push(v);
					}
				}
			}
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}