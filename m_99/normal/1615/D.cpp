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
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000001

vector<int> X,Y,V;

void dfs(vector<vector<pair<int,int>>> &E,vector<int> &color,int cur,int p,int cv){

	rep(i,E[cur].size()){
		int to = E[cur][i].first,v = E[cur][i].second;
		if(to==p)continue;
		if(v!=-1){
			X.push_back(to);
			Y.push_back(cur);
			V.push_back(v);
			dfs(E,color,to,cur,color[to]);
		}
		else{
			X.push_back(to);
			Y.push_back(cur);
			if(color[cur]==color[to])V.push_back(0);
			else V.push_back(1);
			dfs(E,color,to,cur,color[to]);
			
		}
		
		
	}
	
}

int main(){
	

	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m;
		scanf("%d %d",&n,&m);
		dsu D(n);
		vector<int> x(n-1),y(n-1),v(n-1);
		rep(i,n-1){
			scanf("%d %d %d",&x[i],&y[i],&v[i]);
			x[i]--;y[i]--;
			if(v[i]!=-1 && __builtin_popcount(v[i])%2==0)D.merge(x[i],y[i]);
		}
		
		vector<int> a(m),b(m),p(m);
		rep(i,m){
			scanf("%d %d %d",&a[i],&b[i],&p[i]);
			a[i]--;b[i]--;
			if(p[i]==0)D.merge(a[i],b[i]);
		}
		
		auto g = D.groups();
		vector<int> pos(n);
		rep(i,g.size()){
			rep(j,g[i].size()){
				pos[g[i][j]] = i;
			}
		}
		
		vector<vector<int>> E(g.size());
		
		rep(i,n-1){
			if(v[i]!=-1&&__builtin_popcount(v[i])%2==1){
				E[pos[x[i]]].push_back(pos[y[i]]);
				E[pos[y[i]]].push_back(pos[x[i]]);
			}
		}
		rep(i,m){
			if(p[i]==1){
				E[pos[a[i]]].push_back(pos[b[i]]);
				E[pos[b[i]]].push_back(pos[a[i]]);
			}
		}			
		vector<int> color(g.size(),-1);
		bool f = true;
		rep(i,g.size()){
			if(color[i]!=-1)continue;
			queue<int> Q;
			Q.push(i);
			color[i] = 0;
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
							f = false;
							break;
						}
					}
				}
			}
		}
		if(!f){
			cout<<"NO"<<endl;
			continue;
		}
		
		vector<int> cc(n);
		rep(i,g.size()){
			rep(j,g[i].size()){
				cc[g[i][j]] = color[i];
			}
		}
		
		vector<vector<pair<int,int>>> EE(n);
		rep(i,n-1){
			EE[x[i]].emplace_back(y[i],v[i]);
			EE[y[i]].emplace_back(x[i],v[i]);
		}
		
		X.clear();
		Y.clear();
		V.clear();
		
		dfs(EE,cc,0,-1,0);
			
		cout<<"YES"<<endl;
		rep(i,n-1){
			printf("%d %d %d\n",X[i]+1,Y[i]+1,V[i]);
		}
		
	}
	
	return 0;
}