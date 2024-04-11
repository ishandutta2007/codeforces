#include <stdio.h>
#include <bits/stdc++.h>

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

void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	dsu D(n);
	vector<int> a,b;
	rep(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		string s;
		cin>>s;
		
		if(s[0]=='c'){
			D.merge(x,y);
		}
		else{
			a.push_back(x);
			b.push_back(y);
		}
	}
	
	auto g = D.groups();
	vector<int> pos(n);
	rep(i,g.size()){
		rep(j,g[i].size()){
			pos[g[i][j]] = i;
		}
	}
	dsu D2(g.size());
	vector<vector<int>> E(g.size());
	rep(i,a.size()){
		int x = pos[a[i]],y = pos[b[i]];
		if(x==y){
			printf("-1\n");
			return;
		}
		E[x].push_back(y);
		E[y].push_back(x);
		D2.merge(x,y);
	}
	n = g.size();
	auto g1 = g;
	g = D2.groups();
	vector<int> color(n,-1);
	int ans = 0;
	rep(i,g.size()){
		queue<int> Q;
		Q.push(g[i][0]);
		color[g[i][0]] = 0;
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			rep(j,E[u].size()){
				int v = E[u][j];
				if(color[v]==-1){
					color[v] = color[u]^1;
					Q.push(v);
				}
				else{
					if(color[v]==color[u]){
						printf("-1\n");
						return;
					}
				}
			}			
		}
		int t = 0;
		int sum  = 0;
		rep(j,g[i].size()){
			if(color[g[i][j]]){
				t += g1[g[i][j]].size();
			}
			sum += g1[g[i][j]].size();
		}
		ans += max(t,sum-t);
		
	}
	printf("%d\n",ans);
	return;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		solve();
			
		
	}
	
	return 0;
}