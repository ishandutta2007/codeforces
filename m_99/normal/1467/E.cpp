#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int n;
vector<vector<int>> E;
vector<int> a;


struct lca{
	
	vector<int> depth;//depth[i]
	vector<vector<int>> parents;//parents[i][j]
	
	int max_j = 30;
	
	lca(){
	}
	
	lca(int n,vector<vector<int>> &E){
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

vector<int> L;
vector<int> sum;
vector<vector<int>> ind;

lca LCA;
bool f = true;
void dfs(int cur,int p){
	int color = a[cur];
	if(ind[color].size()>1){
		if(L[color]==cur)sum[0]++;
		else sum[cur]++;
	}
	int t = 0;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		if(ind[color].size()!=1){
			
			if(L[color]==cur){
				int x;
				rep(j,ind[color].size()){
					if(ind[color][j]==cur)continue;
					x = ind[color][j];
					break;
				}
				if(LCA.query(x,to)==to){
					sum[to]--;
					t++;
				}
			}
			
		}
		dfs(to,cur);
	}
	if(t>=2)f=false;
}

void dfs1(int cur,int p){
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		sum[to] += sum[cur];
		dfs1(to,cur);
	}
}

int op(int a,int b){
	return max(a,b);
}

int e(){
	return 0;
}

int mapping(int a,int b){
	return a+b;
}
int composition(int a,int b){
	return a+b;
}
int id(){
	return 0;
}

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

	
	cin>>n;
	
	vector<int> t;
	
	a.resize(n);
	rep(i,n){
		scanf("%d",&a[i]);
		t.push_back(a[i]);
	}
	
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	
	rep(i,n){
		a[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),a[i]));
	}
	
	E.resize(n,vector<int>());
	
	rep(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	ind.resize(t.size(),vector<int>());
	rep(i,n){
		ind[a[i]].push_back(i);
	}
	
	LCA = lca(0,E);
	L.resize(t.size(),-1);
	
	rep(i,t.size()){
		L[i] = ind[i][0];
		rep(j,ind[i].size()){
			L[i] = LCA.query(L[i],ind[i][j]);
		}
	}
	{
		HLD H(E);
		lazy_segtree<int,op,e,int,composition,mapping,id> seg(n);
		rep(i,ind.size()){
			if(!f)break;
			if(ind[i].size()<=1)continue;
			rep(j,ind[i].size()){
				int u = ind[i][j];
				int v = ind[i][(j+1)%ind[i].size()];
				auto ret = H.query(u,v);
				rep(k,ret.size()){
					int l = ret[k].first,r = ret[k].second;
					if(l>r){
						swap(l,r);
					}
					seg.apply(l,r+1,1);
				}
			}
			rep(j,ind[i].size()){
				if(seg.get(H.pos[ind[i][j]])>2){
					f=false;
					break;
				}
			}
			rep(j,ind[i].size()){
				int u = ind[i][j];
				int v = ind[i][(j+1)%ind[i].size()];
				auto ret = H.query(u,v);
				rep(k,ret.size()){
					int l = ret[k].first,r = ret[k].second;
					if(l>r){
						swap(l,r);
					}
					seg.apply(l,r+1,-1);
				}
			}
		}
	}

	sum.resize(n,0);
	if(f)dfs(0,-1);
	
	if(!f)sum[0] ++;
	dfs1(0,-1);
	
	int ans = 0;
	rep(i,sum.size()){
		if(sum[i]==0)ans++;
	}
	
	cout<<ans<<endl;
	
    return 0;
}