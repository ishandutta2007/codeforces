#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

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
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
            if (((r >> i) << i) != r) push((r - 1) >> i);
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

vector<int> t;
long long op(long long a,long long b){
	return a+b;
}

long long e(){
	return 0;
}

long long mapping(long long a,long long b){
	if(a==-1)return b;
	return a;
}

long long composition(long long a,long long b){
	if(a==-1)return b;
	if(b==-1)return a;
	return a;
}
long long id(){
	return -1;
}

void dfs(int cur,vector<int> &l,vector<int> &r){
	if(l[cur]!=-1)dfs(l[cur],l,r);
	t.push_back(cur);
	if(r[cur]!=-1)dfs(r[cur],l,r);
}

int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> l(n),r(n);
	vector<vector<int>> E(n);
	rep(i,n){
		scanf("%d %d",&l[i],&r[i]);
		l[i]--;r[i]--;
		if(l[i]!=-1){
			E[i].push_back(l[i]);
			E[l[i]].push_back(i);
		}
		if(r[i]!=-1){
			E[i].push_back(r[i]);
			E[r[i]].push_back(i);
		}
	}
	HLD H(E);
	dfs(0,l,r);
	
	vector<bool> need(n,false);
	char c = '*';
	for(int i=n-2;i>=0;i--){
		if(s[t[i+1]]!=s[t[i]])c = s[t[i+1]];
		if(c=='*')continue;
		if(c > s[t[i]]){
			need[t[i]] = true;
		}
	}
	
	lazy_segtree<long long,op,e,long long, mapping,composition,id> seg(n);
	rep(i,n)seg.set(i,1LL);
	
	string ans = "";
	
	rep(i,n){
		int ind  =t[i];
		//cout<<ind<<','<<seg.get(H.pos[ind])<<endl;
		if(seg.get(H.pos[ind])==0){
			ans += s[ind];
			ans += s[ind];
		}
		else{
			if(need[ind]==false){
				ans += s[ind];
				seg.set(H.pos[ind],Inf);
				continue;
			}
			auto ret = H.query(0,ind);
			long long S = 0;
			rep(j,ret.size()){
				int L = ret[j].first,R = ret[j].second;
				if(L>R)swap(L,R);
				R++;
				S += seg.prod(L,R);
				//cout<<L<<','<<R<<endl;
			}
			//cout<<S<<endl;
			if(S>k){
				ans += s[ind];
				seg.set(H.pos[ind],Inf);
				continue;
			}
			
			k -= S;
			ans += s[ind];
			ans += s[ind];
			rep(j,ret.size()){
				int L = ret[j].first,R = ret[j].second;
				if(L>R)swap(L,R);
				R++;
				seg.apply(L,R,0);
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}