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

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 10000000000000000

long long op(long long a,long long b){
	return min(a,b);
}

long long e(){
	return Inf;
}


int main(){
	

	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<long long> a(n);
		long long O=0LL,E=0LL;
		rep(i,n){
			scanf("%d",&a[i]);
			if(i%2==0)E+=a[i];
			else O += a[i];
		}
		
		vector<segtree<long long,op,e>> seg(2,segtree<long long,op,e>(n));
		
		long long cur = 0LL;
		rep(i,n){
			cur *= -1;
			seg[i&1].set(i,a[i]+cur);
			cur += a[i];
		}

		if(E==O&&seg[0].all_prod()>=0&&seg[1].all_prod()>=0){
			printf("YES\n");
			continue;
		}
		bool f = false;
		rep(i,n-1){
			if(i%2==0){
				if(E-a[i]+a[i+1]!=O-a[i+1]+a[i])continue;
			}
			else{
				if(E-a[i+1]+a[i]!=O-a[i]+a[i+1])continue;
			}

			if(min(seg[0].prod(0,i),seg[1].prod(0,i))<0)break;
			long long x = min(seg[0].get(i),seg[1].get(i));
			long long y = min(seg[0].get(i+1),seg[1].get(i+1));
			//cout<<i<<endl;
			x -= a[i];
			y -= a[i+1];
			if(x+a[i+1]<0)continue;
			y += a[i];
			y -= a[i+1];
			if(y+a[i]<0)continue;
		//	cout<<i<<endl;
			if(seg[i&1].prod(i+2,n)-a[i]*2+a[i+1]*2<0)continue;
			if(seg[(i&1)^1].prod(i+2,n)+a[i]*2-a[i+1]*2<0)continue;
			f=true;
			break;
			
		}
		
		if(f)printf("YES\n");
		else printf("NO\n");
		
	}
	
    return 0;
}