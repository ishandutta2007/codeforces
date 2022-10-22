#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
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
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
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

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

vector<int> get(vector<vector<int>> E,int s){
	int n= E.size();
	queue<int> Q;
	Q.push(s);
	vector<int> ret(n,Inf);
	ret[s] = 0;
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(ret[v]!=Inf)continue;
			ret[v] = ret[u]+1;
			Q.push(v);
		}
	}
	return ret;
}

vector<int> get(vector<vector<int>> E){
	int n = E.size();
	auto ret = get(E,0);
	int u = 0;
	rep(i,n){
		if(ret[u]<ret[i]){
			u = i;
		}
	}
	
	ret = get(E,u);
	int v = 0;
	rep(i,n){
		if(ret[v]<ret[i])v = i;
	}
	
	vector<int> ret2 = get(E,v);
	rep(i,n){
		ret[i] = max(ret[i],ret2[i]);
	}
	return ret;
	
	
}

int main(){
	
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	
	vector<vector<int>> E(n);
	dsu D(n);
	rep(i,m){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		D.merge(u,v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	vector<int> inds(n);
	vector<vector<int>> ds;
	
	auto ret = D.groups();
	rep(i,ret.size()){
		sort(ret[i].begin(),ret[i].end());
		inds[D.leader(ret[i][0])] = i;
		vector<vector<int>> e(ret[i].size());
		rep(j,ret[i].size()){
			int u = ret[i][j];
			rep(k,E[u].size()){
				int v = E[u][k];
				v = distance(ret[i].begin(),lower_bound(ret[i].begin(),ret[i].end(),v));
				e[j].push_back(v);
			}
		}
		ds.push_back(get(e));
	}
	
	vector<vector<long long>> dsum;
	vector<vector<long long>> dcnt;
	rep(i,ds.size()){
		sort(ds[i].begin(),ds[i].end());
		dsum.push_back(vector<long long>(ds[i].back()+1,0.0));
		dcnt.push_back(dsum.back());
		rep(j,ds[i].size()){
			dcnt.back()[ds[i][j]]++;
			dsum.back()[ds[i][j]]+=ds[i][j];
		}
		for(int j=dsum.back().size()-1;j>=0;j--){
			if(j==0)continue;
			dsum.back()[j-1] += dsum.back()[j];
			dcnt.back()[j-1] += dcnt.back()[j];
		}
		dsum.back().push_back(0);
		dcnt.back().push_back(0);
	}
	
	map<pair<int,int>,long long> mp;
	
	rep(_,q){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		
		u = inds[D.leader(u)],v = inds[D.leader(v)];
		if(u==v){
			printf("-1\n");
			continue;
		}
		if(ds[u].size()>ds[v].size())swap(u,v);
		if(ds[u].size()==ds[v].size()){
			if(u>v)swap(u,v);
		}
		if(mp.count(make_pair(u,v))){
			printf("%.10lf\n",(double)mp[make_pair(u,v)]/ds[u].size()/ds[v].size());
			continue;
		}
		
		long long M = max(ds[u].back(),ds[v].back());
		long long ans = 0;
		rep(i,ds[u].size()){
			long long t = M-ds[u][i];

			if(t>=dsum[v].size())t = dsum[v].size()-1;
			ans += dcnt[v][t] * (ds[u][i]+1);
			ans += dsum[v][t];
			ans += M * (dcnt[v][0] - dcnt[v][t]);			
		}
		
		mp[make_pair(u,v)] = ans;
		
		printf("%.10lf\n",(double)ans/ds[u].size()/ds[v].size());
		
	}
	
	
	
    return 0;
}