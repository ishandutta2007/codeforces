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

struct lca{
	
	vector<int> depth;
	vector<vector<int>> parents;
	
	int max_j=18;
	
	lca(int n,vector<vector<int>> &E){
		depth.assign(E.size(),-1);
		parents.assign(E.size(),vector<int>(max_j,-1));
		
		rep(i,100){
			if((1<<i)>E.size()){
				max_j = i;
				break;
			}
		}
		
		stack<int> s;
		s.push(n);
		depth[n] = 0;
		while(s.size()!=0){
			int k = s.top();
			s.pop();
			for(int i=0;i<E[k].size();i++){
				int x = E[k][i];
				if(depth[x]!=-1)continue;
				s.push(x);
				depth[x] = depth[k]+1;
				for(int j=0;j<max_j;j++){
					if(j==0){
						parents[x][j] = k;
					}
					else{
						parents[x][j] = parents[parents[x][j-1]][j-1];
					}
					if(parents[x][j] == -1)break;
				}
			}
		}
	}
	
	
	int kth_parent(int u,int k){
		for(int i=0;i<max_j;i++){
			if(k==0)break;
			if(u==-1)break;
			if(k%2){
				u = parents[u][i];
			}
			k/=2;
		}
		return u;
	}
	
	int query(int u,int v){
		if(depth[u]<depth[v])swap(u,v);
		u = kth_parent(u,depth[u]-depth[v]);
		
		if(u==v){
			return u;
		}
		
		for(int i=max_j-1;i>=0;i--){
			if(parents[u][i]!=parents[v][i]){
				u = parents[u][i];
				v = parents[v][i];
			}
		}
		
		return parents[u][0];
		
	}
	
	int get_distance(int u,int v){
		return depth[u]+depth[v]-2*depth[query(u,v)];
	}
	
	
};

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		scanf("%lld",&n);
		
		vector<vector<int>> E(n);
		rep(i,n){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		long long ans = n;
		ans *= n-1;
		vector<int> u,v;
		
		{
			pair<int,int> P;
			vector<vector<int>> e(n);
			dsu D(n);
			rep(i,n){
				rep(j,E[i].size()){
					if(i<E[i][j]){
						if(D.same(i,E[i][j])){
							P = make_pair(i,E[i][j]);
							continue;
						}
						D.merge(i,E[i][j]);
						e[i].push_back(E[i][j]);
						e[E[i][j]].push_back(i);
					}
				}
			}
			lca L(0,e);
			int d = L.get_distance(P.first,P.second);
			rep(i,n){
				rep(j,E[i].size()){
					if(i<E[i][j]){
						
						int x = min(L.get_distance(P.first,i)+L.get_distance(P.second,E[i][j]),
						L.get_distance(P.first,E[i][j])+L.get_distance(P.second,i));
						if(x+L.get_distance(i,E[i][j])!=d){
							u.push_back(i);
							v.push_back(E[i][j]);
						}
					}
				}
			}
			
		}
		
		dsu D(n);
		rep(i,u.size()){
			//cout<<u[i]<<','<<v[i]<<endl;
			D.merge(u[i],v[i]);
		}
		
		rep(i,n){
			if(D.leader(i)==i){
				long long t = D.size(i);
				t *= D.size(i)-1;
				t /= 2;
				ans -= t;
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}