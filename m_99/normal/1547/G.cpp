#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000



int main(){
	
	int _t;
	cin>>_t;
	

	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		vector<int> a(m),b(m);
		vector<bool> loop(n,false);
		scc_graph S(n);
		rep(i,m){
			scanf("%d %d",&a[i],&b[i]);
			a[i]--;b[i]--;
			S.add_edge(a[i],b[i]);
			if(a[i]==b[i]){
				loop[a[i]] = true;
			}
		}
		
		vector<int> ind(n);
		auto ret = S.scc();
		int s;
		rep(i,ret.size()){
			rep(j,ret[i].size()){
				ind[ret[i][j]] = i;
				if(ret[i][j]==0)s = i;
			}
		}
		
		vector<vector<int>> E(ret.size());
		vector<int> dp(ret.size(),0);
		vector<bool> f(ret.size(),false);
		rep(i,m){
			int x = ind[a[i]],y = ind[b[i]];
			if(x==y){
				f[x] = true;
			}
			else{
				E[x].push_back(y);
			}
		}
		dp[s] = 1;
		for(int i=s;i<ret.size();i++){
			if(dp[i]==0)continue;
			if(f[i])dp[i] = -1;
			rep(j,E[i].size()){
				int to = E[i][j];
				if(dp[to]==-1)continue;
				if(dp[i]==-1){
					dp[to] = -1;
				}
				else{
					dp[to] = min(dp[to]+dp[i],2);
				}
			}
		}
		
		vector<int> ans(n);
		rep(i,n){
			ans[i] = dp[ind[i]];
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}