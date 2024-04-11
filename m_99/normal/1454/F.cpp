#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
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

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
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

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
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

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
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

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
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
#define Inf 1000000001

int opm(int a,int b){
	return min(a,b);
}

int em(){
	return Inf;
}

int opM(int a,int b){
	return max(a,b);
}

int eM(){
	return -Inf;
}

int X;
bool f(int t){
	return t<=X;
}
bool f2(int t){
	return t>=X;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		{
			vector<int> t;
			rep(i,n)t.push_back(a[i]);
			
			sort(t.begin(),t.end());
			
			t.erase(unique(t.begin(),t.end()),t.end());
			rep(i,n){
				a[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),a[i]));
			}
			
		}
		vector<vector<int>> cnt(n);
		rep(i,n){
			cnt[a[i]].push_back(i);
		}
		segtree<int,opm,em> segm(a);
		segtree<int,opM,eM> segM(a);
		
		
		bool F = false;
		int x,y,z;
		
		vector<int> mL(n,-1),mR(n,-1),ML(n,-1),MR(n,-1);
		
		{
			int cur = -1;
			rep(i,n){
				cur = max(cur,a[i]);
				if(mL[cur]==-1)mL[cur] = i+1;
				ML[cur] = i+1;
			}
		}
		{
			int cur = -1;
			rep(i,n){
				cur = max(cur,a[n-1-i]);
				if(mR[cur]==-1)mR[cur] = i+1;
				MR[cur] = i+1;
			}
		}
		
		rep(i,n){
			if(mL[i]==-1||mR[i]==-1)continue;
			if(ML[i]+MR[i]>=n)continue;
			
			int l = ML[i];
			int r = n-MR[i];
			
			{
				X = i;
				int temp = segm.min_left<f2>(r);
				l = max(mL[i],temp);
				
			}
			{
				X = i;
				int temp = segm.max_right<f2>(l);
				r = min(temp,n-mR[i]);
			}
			
			
			if(segM.prod(0,l)==segm.prod(l,r)&&segm.prod(l,r)==segM.prod(r,n)){
				F = true;
				x = l;
				y = r-l;
				z = n-x-y;
				break;
			}
			
		}
		
		if(!F){
			for(int i=1;i<n-1;i++){
				X = segM.prod(0,i);
				int Y = segm.prod(i,i+1);
				int Z = segM.prod(i+1,n);
				if(X==Y&&Y==Z){
					F = true;
					x = i;
					y = 1;
					z = n-x-y;
					break;
				}
				
			}
		}
		if(F){
			printf("YES\n");
			printf("%d %d %d\n",x,y,z);
		}
		else printf("NO\n");
	}
	
	return 0;
}