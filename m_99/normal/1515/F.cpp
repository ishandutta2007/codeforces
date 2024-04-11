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
#define Inf 1000000000000000001



int main(){
	
	int n,m;
	long long x;
	scanf("%d %d %lld",&n,&m,&x);
	
	vector<long long> a(n);
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	
	vector<int> u(m),v(m);
	vector<set<int>> E(n);
	rep(i,m){
		scanf("%d %d",&u[i],&v[i]);
		u[i]--;v[i]--;
		E[u[i]].insert(i);
		E[v[i]].insert(i);
	}
	
	long long sum = 0LL;
	rep(i,n){
		sum += a[i];
	}
	if(sum < x * (n-1)){
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<int> par(n);
	rep(i,n)par[i] = i;
	vector<vector<int>> inds(n);
	rep(i,n)inds[i] = {i};
	
	set<pair<long long,int>> Q;
	
	rep(i,n)Q.emplace(a[i],i);
	int cur = 0;
	vector<int> ans;
	while(true){
		if(Q.size()==0)break;
		auto p = *prev(Q.end());
		Q.erase(p);
		
		int ind = p.second;
		if(par[ind]!=ind)continue;
		if(E[ind].size()==0)continue;
		int id = *(E[ind].begin());
		int uu = par[u[id]],vv = par[v[id]];
		E[uu].erase(id);
		E[vv].erase(id);
		if(uu==vv){
			Q.insert(p);
			continue;
		}
		ans.push_back(id+1);
		
		if(E[uu].size()+inds[uu].size()<E[vv].size()+inds[vv].size())swap(uu,vv);
		Q.erase(make_pair(a[uu],uu));
		a[uu] = a[uu] + a[vv] - x;
		Q.insert(make_pair(a[uu],uu));
		
		while(E[vv].size()>0){
			E[uu].insert(*E[vv].begin());
			E[vv].erase(E[vv].begin());
		}
		
		while(inds[vv].size()>0){
			par[inds[vv].back()] = uu;
			inds[uu].push_back(inds[vv].back());
			inds[vv].pop_back();
		}
		
	}
	
	
	cout<<"YES"<<endl;
	rep(i,ans.size())printf("%d\n",ans[i]);
	
	
	
    return 0;
}