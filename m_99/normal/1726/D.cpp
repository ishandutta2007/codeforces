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

using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

struct lca{
	
	vector<int> depth;
	vector<vector<int>> parents;
	
	int max_j=18;
	
	lca(int n,vector<vector<int>> &E){
		rep(i,100){
			if((1<<i)>E.size()){
				max_j = i;
				break;
			}
		}
		depth.assign(E.size(),-1);
		parents.assign(E.size(),vector<int>(max_j,-1));
		
		
		
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
		
		int n,m;
		scanf("%d %d",&n,&m);
		vector<int> a(m),b(m);
		vector<vector<int>> E(n);
		vector<int> is;
		{
			dsu D(n);
			rep(i,m){
				scanf("%d %d",&a[i],&b[i]);
				a[i]--,b[i]--;
				if(D.same(a[i],b[i])){
					is.push_back(i);
				}
				else{
					D.merge(a[i],b[i]);
					E[a[i]].push_back(b[i]);
					E[b[i]].push_back(a[i]);
				}
			}
		}
		
		lca L(0,E);
		int sz = is.size();
		rep(i,sz){
			if(L.get_distance(a[is[i]],b[is[i]])==2){
				int l = L.query(a[is[i]],b[is[i]]);
				
				rep(j,m){
					int t = l ^ a[j] ^ b[j];
					if(t==a[is[i]] || t==b[is[i]]){
						is.push_back(j);
					}
				}
			}
		}
		//cout<<sz<<endl;
		
		sort(is.begin(),is.end());
		is.erase(unique(is.begin(),is.end()),is.end());
		bool F = false;
		rep(i,1<<is.size()){
			dsu Da(n),Db(n);
			bool f = true;
			string S(m,'0');
			rep(j,is.size()){
				int x = a[is[j]],y = b[is[j]];
				if((i>>j)&1){
					if(Da.same(x,y)){
						f = false;
						break;
					}
					else Da.merge(x,y);
					S[is[j]] = '0';
				}
				else{
					if(Db.same(x,y)){
						f = false;
						break;
					}
					else Db.merge(x,y);
					S[is[j]] = '1';
				}
			}
			if(!f)continue;
			rep(j,m){
				if(binary_search(is.begin(),is.end(),j))continue;
				if(Da.same(a[j],b[j])){
					if(Db.same(a[j],b[j])){
						f = false;
						break;
					}
					else{
						Db.merge(a[j],b[j]);
						S[j] = '1';
					}
				}
				else{
					Da.merge(a[j],b[j]);
					S[j] = '0';
				}
			}
			if(!f)continue;
			cout<<S<<endl;
			break;
		}
		
		
	}
	
    return 0;
}