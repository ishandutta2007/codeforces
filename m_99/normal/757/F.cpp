#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

struct dominator_tree{
	
	
	struct potentialized_dsu {
		using S = pair<int,int>;
	  public:
		potentialized_dsu() : _n(0) {}
		potentialized_dsu(int n) : _n(n), parent_or_size(n, -1), d(n,e()) {}

		int merge(int a, int b, S v) {
			assert(0 <= a && a < _n);
			assert(0 <= b && b < _n);
			int x = leader(a), y = leader(b);
			if (x == y) return x;
			
			d[y] = op(d[y],op(d[x],v));
			
			parent_or_size[x] += parent_or_size[y];
			parent_or_size[y] = x;
			
			return x;
		}

		bool same(int a, int b) {
			assert(0 <= a && a < _n);
			assert(0 <= b && b < _n);
			return leader(a) == leader(b);
		}

		int leader(int a) {
			assert(0 <= a && a < _n);
			if (parent_or_size[a] < 0) return a;
			int l = leader(parent_or_size[a]);
			if(parent_or_size[a] != l){
				d[a] = op(d[parent_or_size[a]],d[a]);
				parent_or_size[a] = l;
			}
			return parent_or_size[a];
		}

		int size(int a) {
			assert(0 <= a && a < _n);
			return -parent_or_size[leader(a)];
		}
		
		S get(int a){
			assert(0 <= a && a < _n);
			leader(a);
			return d[a];
		}

		std::vector<std::vector<int>> groups() {
			std::vector<int> leader_buf(_n), group_size(_n);
			for (int i = 0; i < _n; i++) {
				leader_buf[i] = leader(i);
				group_size[leader_buf[i]]++;
			}
			std::vector<std::vector<int>> result(_n);
			for (int i = 0; i < _n; i++) {
				result[i].reserve(group_size[i]);
			}
			for (int i = 0; i < _n; i++) {
				result[leader_buf[i]].push_back(i);
			}
			result.erase(
				std::remove_if(result.begin(), result.end(),
							   [&](const std::vector<int>& v) { return v.empty(); }),
				result.end());
			return result;
		}
		
		pair<int,int> op(pair<int,int> a,pair<int,int> b){
			return min(a,b);
		}

		pair<int,int> e(){
			return make_pair(1000000000,0);
		}

	  private:
		int _n;
		// root node: -1 * component size
		// otherwise: parent
		std::vector<int> parent_or_size;
		std::vector<S> d;
	};

	dominator_tree(){
	}
	
	
	vector<vector<int>> get(vector<vector<int>> E,int r){

		int n = E.size();
		vector<int> ind;
		vector<int> pos(n,n);
		vector<int> p(n,-1);
		dfs(r,E,ind,pos,p);

		vector<vector<int>> rE(n);
		rep(i,E.size()){
			rep(j,E[i].size()){
				rE[E[i][j]].push_back(i);
			}
		}
		

		vector<pair<int,int>> sdom(n,make_pair(n,n));
		vector<pair<int,int>> idom(n,make_pair(n,n));
		vector<vector<int>> L(n);
		potentialized_dsu D(n);
		
		for(int i=ind.size()-1;i>=1;i--){
			int u = ind[i];
			rep(j,rE[u].size()){
				int v = rE[u][j];
				sdom[u] = min(sdom[u],make_pair(pos[v],u));
				sdom[u] = min(sdom[u],D.get(v));
			}
			sdom[u].second = u;
			
			L[ind[sdom[u].first]].push_back(u);
			
			rep(j,L[p[u]].size()){
				int v = L[p[u]][j];
				idom[v] = min(D.get(v),sdom[u]);
			}
			L[p[u]].clear();
			D.merge(p[u],u,sdom[u]);
			
		}
		
		rep(i,ind.size()){
			if(i==0)continue;
			int u = ind[i];
			if(idom[u].first==n){
				//idom[u] = make_pair(sdom[u].first,u);
			}
			else if(sdom[u].first == sdom[idom[u].second].first){
				idom[u] = sdom[u];
			}
			else{
				idom[u] = idom[idom[u].second];
			}
		}

		vector<vector<int>> ret(n);
		rep(i,n){
			if(idom[i].first==n)continue;
			ret[ind[idom[i].first]].push_back(i);
		}
		return ret;
		
	}
	
	void dfs(int cur,vector<vector<int>> &E,vector<int> &ind,vector<int> &pos,vector<int> &p){
		pos[cur] = ind.size();
		ind.push_back(cur);
		rep(i,E[cur].size()){
			int to = E[cur][i];
			if(pos[to]!=E.size())continue;
			p[to] = cur;
			dfs(to,E,ind,pos,p);
		}
	}
	
	
	
};

void dfs(int cur,vector<vector<int>> &E,vector<int> &cnt){
	cnt[cur] = 1;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		dfs(to,E,cnt);
		cnt[cur] += cnt[to];
	}
}

int main(){
	
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	s--;
	
	vector<vector<pair<int,long long>>> E(n);
	rep(i,m){
		int u,v;
		long long w;
		scanf("%d %d %lld",&u,&v,&w);
		u--;v--;
		
		E[u].emplace_back(v,w);
		E[v].emplace_back(u,w);
	}
	
	vector<long long> d(n,Inf);
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> Q;
	d[s] = 0LL;
	Q.emplace(0LL,s);
	
	while(Q.size()>0){
		long long D = Q.top().first;
		int u = Q.top().second;
		Q.pop();
		
		if(d[u]!=D)continue;
		rep(i,E[u].size()){
			int v = E[u][i].first;
			long long D2 = E[u][i].second;
			if(d[v]>D+D2){
				d[v] = D+D2;
				Q.emplace(d[v],v);
			}
		}
	}
	
	vector<vector<int>> EE(n);
	rep(i,n){
		rep(j,E[i].size()){
			int u = i,v = E[i][j].first;
			long long w = E[i][j].second;
			if(d[v]==d[u]+w){
				EE[u].push_back(v);
			}
		}
	}
	
	dominator_tree D;
	auto ret = D.get(EE,s);

	vector<int> cnt(n,0);
	dfs(s,ret,cnt);
	
	int ans = 0;
	rep(i,cnt.size()){
		if(i==s)continue;
		ans = max(ans,cnt[i]);
	}
	
	printf("%d\n",ans);
	
    return 0;
}