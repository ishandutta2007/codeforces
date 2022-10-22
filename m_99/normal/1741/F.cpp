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
#define Inf32 1000000001
#define Inf64 2000000000000000001
using A = array<pair<int,int>,2>;

A e(){
	A ret;
	ret[0] = make_pair(-Inf32,-1);
	ret[1] = make_pair(-Inf32,-1);
	return ret;
}

A op(A a,A b){
	array<pair<int,int>,4> t;
	rep(i,2){
		t[i*2] = a[i];
		t[i*2+1] = b[i];
	}
	sort(t.rbegin(),t.rend());
	A ret = e();
	
	ret[0] = t[0];
	rep(i,4){
		if(ret[0].second!=t[i].second){
			ret[1] = t[i];
			return ret;
		}
	}
	ret[1] = make_pair(-Inf32,-1);
	return ret;
}




int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> l(n),r(n),c(n);
		vector<int> t;
		vector<int> is(n);
		rep(i,n){
			scanf("%d %d %d",&l[i],&r[i],&c[i]);
			t.push_back(l[i]);
			t.push_back(r[i]);
			is[i] = i;
		}
		sort(t.begin(),t.end());
		t.erase(unique(t.begin(),t.end()),t.end());
		sort(is.begin(),is.end(),[&](int x,int y){
			return r[x]<r[y];
		});
		vector<int> ans(n,Inf32);
		{
			segtree<A,op,e> s(t.size());
			
			rep(i,n){
				
				int ii = is[i];
				int R = distance(t.begin(),lower_bound(t.begin(),t.end(),r[ii]));
			//	cout<<ii<<endl;
				{
					auto ret = s.prod(0,t.size());
					rep(j,2){
						if(ret[j].second==c[ii])continue;
						//cout<<ret[j].first<<','<<ret[j].second<<endl;
						ans[ii] = min(ans[ii],l[ii] - ret[j].first);
					}
				}
				A temp = e();
				temp[0] = make_pair(r[ii],c[ii]);
				s.set(R,op(s.get(R),temp));
			}
			
		}
		
		{
			segtree<A,op,e> s(t.size());
			reverse(is.begin(),is.end());
			rep(i,n){
				
				int ii = is[i];
				int R = distance(t.begin(),lower_bound(t.begin(),t.end(),r[ii]));
			//	cout<<ii<<endl;
				{
					auto ret = s.prod(0,t.size());
					rep(j,2){
						if(ret[j].second==c[ii])continue;
						//cout<<ret[j].first<<','<<ret[j].second<<endl;
						if(ret[j].first!=-Inf32){
							ans[ii] = min(ans[ii],-ret[j].first-r[ii]);
						}
					}
				}
				A temp = e();
				temp[0] = make_pair(-l[ii],c[ii]);
				s.set(R,op(s.get(R),temp));
			}
			
		}
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",max(0,ans[i]));
		}
		cout<<endl;
	}
	
	return 0;
}