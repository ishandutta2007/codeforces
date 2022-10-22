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



int main(){

	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<vector<int>> E(n);
		dsu D(n);

		rep(i,m){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			
			E[u].push_back(v);
			E[v].push_back(u);
			
			D.merge(u,v);
		}
		
		if(D.size(0)!=n){
			printf("NO\n");
			continue;
		}
		
		vector<int> d(n,Inf);
		
		
		vector<int> ans;
		
		queue<int> Q;
		Q.push(0);
		d[0] = 2;
		
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			
			if(d[u]!=2)continue;
			ans.push_back(u+1);
			d[u] = 0;
			rep(i,E[u].size()){
				int v  =E[u][i];
				if(d[v]<=1)continue;
				d[v] = 1;
				rep(j,E[v].size()){
					int x = E[v][j];
					if(d[x]<=2)continue;
					d[x] = 2;
					Q.push(x);
				}
			}
		}
			
			
		
		
		printf("YES\n");
		printf("%d\n",ans.size());
		
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
	
    return 0;
}