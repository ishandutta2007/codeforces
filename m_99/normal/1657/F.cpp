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

using namespace atcoder;
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
	
	int n,q;
	cin>>n>>q;
	vector<vector<int>> E(n);
	rep(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--,v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	HLD H(E);
	two_sat T(q);
	vector<int> x(q),y(q);
	vector<string> s(q);
	vector<vector<pair<int,int>>> qs(n);
	rep(i,q){
		scanf("%d %d",&x[i],&y[i]);
		x[i]--;y[i]--;
		cin>>s[i];
		auto ret= H.query(x[i],y[i]);
		int C = 0;
		rep(j,ret.size()){
			int l = ret[j].first,r = ret[j].second;
			//if(l>r)swap(l,r);
			if(l<=r){
				for(int k=l;k<=r;k++){
					qs[H.arr[k]].emplace_back(i,C);
					C++;
				}
			}
			else{
				for(int k=l;k>=r;k--){
					qs[H.arr[k]].emplace_back(i,C);
					C++;
				}
			}
		}
		//cout<<C<<endl;
	}
	
	rep(i,n){
		
		char c = '-';
		rep(j,qs[i].size()){
			int ind = qs[i][j].first;
			int pos = qs[i][j].second;
			int nn = s[ind].size();
			if(s[ind][pos] == s[ind][nn-1-pos]){
				c = s[ind][pos];
				break;
			}
		}
		
		if(c!='-'){
			rep(j,qs[i].size()){
				int ind = qs[i][j].first;
				int pos = qs[i][j].second;
				int nn = s[ind].size();
				char cx = s[ind][pos];
				char cy = s[ind][nn-1-pos];
				
				if(cy!=c){
					T.add_clause(ind,true,ind,true);
				}
				if(cx!=c){
					T.add_clause(ind,false,ind,false);
				}
			}
		}
		else{
			vector<int> cnt(26,0);
			rep(j,qs[i].size()){
				int ind = qs[i][j].first;
				int pos = qs[i][j].second;
				int nn = s[ind].size();
				char cx = s[ind][pos];
				char cy = s[ind][nn-1-pos];
				cnt[cx-'a']++;
				cnt[cy-'a']++;
			}
			rep(j,qs[i].size()){
				int ind = qs[i][j].first;
				int pos = qs[i][j].second;
				int nn = s[ind].size();
				char cx = s[ind][pos];
				char cy = s[ind][nn-1-pos];
				if(cnt[cx-'a']!=qs[i].size())T.add_clause(ind,false,ind,false);
				else{
					int nxt = j+1;
					nxt %= qs[i].size();
					int i2 = qs[i][nxt].first;
					int p2 = qs[i][nxt].second;
					if(cx == s[i2][p2]){
						T.add_clause(ind,false,i2,true);
					}
					else{
						T.add_clause(ind,false,i2,false);
					}
				}
				if(cnt[cy-'a']!=qs[i].size())T.add_clause(ind,true,ind,true);
				else{
					int nxt = j+1;
					nxt %= qs[i].size();
					int i2 = qs[i][nxt].first;
					int p2 = qs[i][nxt].second;
					if(cy == s[i2][p2]){
						T.add_clause(ind,true,i2,true);
					}
					else{
						T.add_clause(ind,true,i2,false);
					}
				}
				
				
			}
		}
	}
	
	if(!T.satisfiable()){
		cout<<"NO"<<endl;
		return 0;
	}
	
	auto bs = T.answer();
	string ans(n,'a');
	rep(i,bs.size()){
		auto ret= H.query(x[i],y[i]);
		vector<int> inds;
		rep(j,ret.size()){
			int l = ret[j].first,r = ret[j].second;
			if(l<=r){
				for(int k=l;k<=r;k++){
					inds.push_back(H.arr[k]);
				}
			}
			else{
				for(int k=l;k>=r;k--){
					inds.push_back(H.arr[k]);
				}
			}
		}
		if(bs[i]==false)reverse(inds.begin(),inds.end());
		rep(j,s[i].size()){
			ans[inds[j]] = s[i][j];
		}
	}
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	
	return 0;
}