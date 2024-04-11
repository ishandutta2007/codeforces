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
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int n,m,A,B;
	scanf("%d %d %d %d",&n,&m,&A,&B);
	
	vector d(n,vector<int>(n,Inf));
	dsu DD(n);
	vector<vector<int>> EA(n),EB(n);
	
	rep(i,n){
		d[i][i] = 0;
	}
	
	rep(i,m){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		u--;v--;
		
		if(c==A){
			EA[u].push_back(v);
			EA[v].push_back(u);
			DD.merge(u,v);
		}
		else{
			EB[u].push_back(v);
			EB[v].push_back(u);
		}
	}
	
	{
		vector<vector<int>> E(n);
		
		rep(i,n){
			rep(j,EB[i].size()){
				int u = i,v = EB[i][j];
				if(DD.same(u,v))continue;
				E[u].push_back(v);
			}
		}
		swap(E,EB);
	}
	
	rep(i,n){
		rep(j,n){
			rep(k,n){
				d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	
	vector<int> L;
	rep(i,n){
		if(DD.leader(i)!=i)continue;
		if(DD.size(i)>=4){
			L.push_back(i);
		}
	}
	
	vector<int> b(n,-1);
	rep(i,n){
		if(DD.size(i)>=4){
			b[i] = distance(L.begin(),lower_bound(L.begin(),L.end(),DD.leader(i)));
		}
	}
	
	vector dis(n*(1<<L.size()),Inf);
	queue<pair<int,int>> Q0,Q1;
	{
		int bb = 0;
		if(b[0]!=-1)bb |= 1<<b[0];
		Q0.emplace(0,bb);
		Q1.emplace(0,bb);
		dis[bb] = 0;
	}

	int Mask = (1<<L.size())-1;

	while(Q0.size()>0||Q1.size()>0){
		if(Q0.size()>0 && (Q1.size()==0 || Q0.front().first+A < Q1.front().first+B)){
			int D = Q0.front().first;
			int u = Q0.front().second>>L.size();
			int bu = Q0.front().second&Mask;
			Q0.pop();
			if(dis[(u<<L.size())|bu]!=D)continue;
			rep(i,EA[u].size()){
				int v = EA[u][i];
				int bv = bu;
				if(dis[(v<<L.size())|bv]>D+A){
					dis[(v<<L.size())|bv] = D+A;
					Q0.emplace(dis[(v<<L.size())|bv],(v<<L.size())|bv);
					Q1.emplace(dis[(v<<L.size())|bv],(v<<L.size())|bv);
				}
			}
		}
		else{
			int D = Q1.front().first;
			int u = Q1.front().second>>L.size();
			int bu = Q1.front().second&Mask;
			Q1.pop();
			
			rep(i,EB[u].size()){
				int v = EB[u][i];
				int mask = 0;
				if(b[v]!=-1)mask |= 1<<b[v];
				if(mask&bu)continue;
				int bv = bu|mask;
				if(dis[(v<<L.size())|bv]>D+B){
					dis[(v<<L.size())|bv] = D+B;
					Q0.emplace(dis[(v<<L.size())|bv],(v<<L.size())|bv);
					Q1.emplace(dis[(v<<L.size())|bv],(v<<L.size())|bv);
				}
			}
		}
		
	}

	vector<int> ans(n,Inf);
	rep(i,n){
		rep(j,1<<L.size()){
			ans[i] = min(ans[i],dis[(i<<L.size())|j]);
		}
	}
	
	rep(i,n){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}