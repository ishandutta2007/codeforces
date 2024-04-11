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
#define Inf 1000000001
int n,m;

void solve0(vector<int> u,vector<int> v,vector<long long> w){
	vector<vector<bool>> f(n,vector<bool>(n,false));
	rep(i,n)f[i][i] = true;
	long long X = 0LL;
	rep(i,u.size()){
		f[u[i]][v[i]] = true;
		f[v[i]][u[i]] = true;
		X ^= w[i];
	}
	
	vector<pair<long long,pair<int,int>>> E;
	int cnt = 0;
	rep(i,n){
		rep(j,n){
			if(f[i][j]==false){
				f[i][j] = true;
				f[j][i] = true;
				E.emplace_back(0,make_pair(i,j));
				cnt ++;
			}
		}
	}
	
	rep(i,m){
		E.emplace_back(w[i],make_pair(u[i],v[i]));
	}
	
	sort(E.begin(),E.end());
	
	dsu D(n);
	
	long long ans = 0LL;
	vector<bool> used(E.size(),false);
	rep(i,E.size()){
		int x = E[i].second.first,y = E[i].second.second;
		long long z = E[i].first;
		if(D.same(x,y))continue;
		D.merge(x,y);
		ans += z;
		if(z==0)cnt--;
		else{
			used[i] = true;
		}
	}
	
	if(cnt!=0){
		cout<<ans<<endl;
		return;
	}
	dsu D2(n);
	rep(i,E.size()){
		if(used[i])D2.merge(E[i].second.first,E[i].second.second);
	}
	
	rep(i,E.size()){
		if(used[i])continue;
		int x = E[i].second.first,y = E[i].second.second;
		long long z = E[i].first;
		if(D2.same(x,y))continue;
		if(z==0)continue;
		X = min(X,z);
	}
	
	cout<<ans+X<<endl;
	
	
}

using P = pair<int,int>;

P op(P a,P b){
	return max(a,b);
}

P e(){
	return make_pair(-Inf,-1);
}

P mapping(int a,P b){
	b.first += a;
	return b;
}

int composition(int a,int b){
	return a+b;
}

int id(){
	return 0;
}

void solve1(vector<int> u,vector<int> v,vector<long long> w){

	lazy_segtree<P,op,e,int,mapping,composition,id> seg(n);
	
	vector<vector<pair<int,long long>>> E(n);
	rep(i,u.size()){
		E[u[i]].emplace_back(v[i],w[i]);
		E[v[i]].emplace_back(u[i],w[i]);
	}
	
	rep(i,n){
		E[i].emplace_back(-1,0);
		E[i].emplace_back(n,0);
		sort(E[i].begin(),E[i].end());
	}
	
	rep(i,n){
		seg.set(i,make_pair(0,i));
	}
	
	long long ans = 0LL;
	
	priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,P>>,greater<pair<long long,P>>> Q;
	
	set<int> used;
	used.insert(0);
	
	
	rep(j,E[0].size()-1){
		seg.apply(E[0][j].first+1,E[0][j+1].first,1);
	}
	rep(j,E[0].size()-1){
		if(j==0)continue;
		Q.emplace(E[0][j].second,make_pair(0,E[0][j].first));
	}
	
	
	seg.set(0,e());
	
	while(used.size()!=n){
		auto p = seg.all_prod();
		int cur;
		if(p.second==-1||p.first<=0){
			while(Q.size()>0){
				auto temp = Q.top();
				Q.pop();
				long long x = temp.first;
				int y = temp.second.first;
				int z = temp.second.second;
				if(used.count(y)&&used.count(z))continue;
				if(!used.count(y)){
					cur = y;
				}
				else{
					cur = z;
				}
				ans += x;
				break;
			}
			
		}
		else{
			cur = p.second;
		}
		
		used.insert(cur);
		
		
		rep(j,E[cur].size()-1){
			seg.apply(E[cur][j].first+1,E[cur][j+1].first,1);
		}
		rep(j,E[cur].size()-1){
			if(j==0)continue;
			Q.emplace(E[cur][j].second,make_pair(cur,E[cur][j].first));
		}
		
		
		seg.set(cur,e());
		
	}
	
	cout<<ans<<endl;
	
}

int main(){
	
	
	
	scanf("%d %d",&n,&m);
	
	vector<int> u(m),v(m);
	vector<long long> w(m);
	
	rep(i,m){
		scanf("%d %d %lld",&u[i],&v[i],&w[i]);
		u[i]--;
		v[i]--;
	}
	
	if(n<=1000){
		solve0(u,v,w);
	}
	else{
		solve1(u,v,w);
	}
	
	
	
    return 0;
}