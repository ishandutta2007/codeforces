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
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int opm(int a,int b){
	return min(a,b);
}
int opM(int a,int b){
	return max(a,b);
}

int em(){
	return Inf;
}
int eM(){
	return -1;
}
int target;
bool check0(int x){
	return x<target;
}
bool check1(int x){
	return x>target;
}

int main(){
	
	int n;
	cin>>n;
	
	vector<int> h(n);
	rep(i,n)scanf("%d",&h[i]);
	
	
	vector<int> t = h;
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	
	rep(i,n){
		h[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),h[i]));
	}
	
	vector<int> dp(n,Inf);
	dp[0] = 0;
	segtree<int,opm,em> seg_minh(h);
	segtree<int,opM,eM> seg_maxh(h);
	
	segtree<int,opm,em> seg_low(n);
	segtree<int,opm,em> seg_high(n);
	
	seg_low.set(0,0);
	seg_high.set(0,0);
	stack<int> s_low,s_high;
	s_low.push(0);
	s_high.push(0);
	
	for(int i=1;i<n;i++){
		dp[i] = dp[i-1]+1;
		target = h[i];
		if(h[i]>h[i-1]){
			int l = seg_maxh.min_left<check0>(i);
			dp[i] = min(dp[i],seg_low.prod(max(0,l-1),n)+1);
		}
		if(h[i]<h[i-1]){
			int l = seg_minh.min_left<check1>(i);
			dp[i] = min(dp[i],seg_high.prod(max(0,l-1),n)+1);
		}
		while(true){
			if(s_low.size()==0)break;
			if(h[s_low.top()]<=h[i]){
				seg_low.set(s_low.top(),Inf);
				s_low.pop();
			}
			else break;
		}
		while(true){
			if(s_high.size()==0)break;
			if(h[s_high.top()]>=h[i]){
				seg_high.set(s_high.top(),Inf);
				s_high.pop();
			}
			else break;
		}
		s_low.push(i);
		s_high.push(i);
		seg_low.set(i,dp[i]);
		seg_high.set(i,dp[i]);
	}
	
	cout<<dp.back()<<endl;
	
    return 0;
}