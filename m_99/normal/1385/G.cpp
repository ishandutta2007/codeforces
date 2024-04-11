#include <stdio.h>
#include <bits/stdc++.h>

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

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
};

}  // namespace atcoder


#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

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
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
vector<bool> get(vector<vector<int>> pos){
	int n = pos.size();
	//cout<<n<<endl;
	two_sat T(n);
	rep(i,n){
		int x = pos[i][0]%n;
		int y = pos[i][1]%n;
		bool fx = (pos[i][0]>=n);
		bool fy = (pos[i][1]>=n);
		T.add_clause(x,fx,y,fy);
	}
	vector<bool> ret;
	if(!T.satisfiable()){
		return ret;
	}
	
	ret = T.answer();
	{
		int c0 = 0,c1 = 0;
		rep(i,n){
			if(ret[i])c1++;
			else c0++;
		}
		if(c1>c0){
			rep(i,n){
				ret[i] = !ret[i];
			}
		}
	}
	return ret;
}
	

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		scanf("%d",&n);
		
		vector<vector<int>> pos(n);
		vector<int> a(n*2);
		rep(i,n*2){
			
			scanf("%d",&a[i]);
			a[i]--;
			pos[a[i]].push_back(i);
		}
		bool f = true;
		rep(i,n){
			if(pos[i].size()!=2)f = false;
		}
		if(!f){
			printf("-1\n");
			continue;
		}
		
		dsu D(n);
		rep(i,n){
			D.merge(a[i],a[i+n]);
		}
		
		auto g = D.groups();
		vector<bool> ret(n,false);
		
		rep(i,g.size()){
			//cout<<g[i].size()<<endl;
			vector<int> pp;
			vector<vector<int>> gg(g[i].size());
			rep(j,g[i].size()){
				rep(k,2){
					pp.push_back(pos[g[i][j]][k]);
				}
				gg[j] = pos[g[i][j]];
			}
			//cout<<g[i].size()<<endl;
			sort(pp.begin(),pp.end());
			pp.erase(unique(pp.begin(),pp.end()),pp.end());
			rep(j,gg.size()){
				rep(k,gg[j].size()){
					gg[j][k] = distance(pp.begin(),lower_bound(pp.begin(),pp.end(),gg[j][k]));
				}
			}
			//cout<<g[i].size()<<endl;
			vector<bool> r = get(gg);
			if(r.size()==0){
				f = false;
				break;
			}
			rep(j,r.size()){
				ret[pp[j]] = r[j];
			}
		}
		if(!f){
			printf("-1\n");
			continue;
		}
		
		
		
		
		vector<int> ans;
		rep(i,n){
			if(ret[i])ans.push_back(i);
		}
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
		}
		printf("\n");
		
	}
	
	return 0;
}