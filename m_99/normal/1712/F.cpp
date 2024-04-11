#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
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

int main() {
	
	int n;
	cin>>n;
	
	vector<vector<int>> E(n);
	rep(i,n-1){
		int p;
		scanf("%d",&p);
		p--;
		E[i+1].push_back(p);
		E[p].push_back(i+1);
	}
	
	vector<int> d(n,Inf);
	queue<int> Q;
	rep(i,n){
		if(E[i].size()==1){
			d[i] = 0;
			Q.push(i);
		}
	}
	
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(d[v]!=Inf)continue;
			d[v] = d[u] + 1;
			Q.push(v);
		}
	}
	HLD H(E);
	
	vector<vector<int>> ind(n+1);
	rep(i,n){
		ind[d[i]].push_back(i);
	}
	
	vector<pair<int,int>> p(n+1);
	pair<int,int> t(-1,-1);
	int dd = 0;
	for(int i=n;i>=0;i--){
		rep(j,ind[i].size()){
			if(t.first==-1){
				t.first = ind[i][j];
				t.second = ind[i][j];
			}
			else{
				if(dd <= H.get_distance(t.first,ind[i][j])){
					dd =  H.get_distance(t.first,ind[i][j]);
					t.second = ind[i][j];
				}
				else if(dd <= H.get_distance(t.second,ind[i][j])){
					dd = H.get_distance(t.second,ind[i][j]);
					t.first = ind[i][j];
				}
			}
		}
		p[i] = t;
	}
	
	int qq;
	cin>>qq;
	rep(_,qq){
		int x;
		cin>>x;
		int ok = 0,ng = n;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			bool f = false;
			rep(i,n){
				int y = mid - d[i] - x;
				if(y<0)y = 0;
				if(p[y].first==-1)continue;
				if(mid <= H.get_distance(i,p[y].first) || mid <= H.get_distance(i,p[y].second)){
					f = true;
					break;
				}
			}
			if(f)ok = mid;
			else ng = mid;
		}
		
		if(_!=0)cout<<' ';
		cout<<ok;
		
	}
	cout<<endl;
			
	
	
    return 0;
}