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
#define Inf 1000000300


int main(){	
	
	int m,n;
	cin>>m>>n;
	
	vector<long long> a(m),b(n);
	rep(i,m)scanf("%lld",&a[i]);
	rep(i,n)scanf("%lld",&b[i]);
	
	vector<vector<int>> s(m);
	
	vector<vector<pair<long long,int>>> P(n,vector<pair<long long,int>>());
	
	
	rep(i,m){
		int sz;
		scanf("%d",&sz);
		s[i].resize(sz);
		rep(j,sz){
			scanf("%d",&s[i][j]);
			s[i][j]--;
			P[s[i][j]].emplace_back(a[i] + b[s[i][j]],i);
		}
	}
	
	long long ans = 0LL;
	
	vector<vector<long long>> E;
	
	rep(i,n){
		sort(P[i].rbegin(),P[i].rend());
		
		while(P[i].size()>1){
			ans += P[i].back().first;
			E.push_back({P[i].back().first,P[i].back().second,P[i][0].second});
			P[i].pop_back();
		}
	}
	
	sort(E.rbegin(),E.rend());
	
	dsu D(m);
	
	rep(i,E.size()){
		long long c = E[i][0];
		int u = E[i][1];
		int v = E[i][2];
		if(D.same(u,v))continue;
		D.merge(u,v);
		ans -= c;
	}
	
	cout<<ans<<endl;
	
	
	
    return 0;
}