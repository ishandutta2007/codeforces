#include<iostream>
#include<vector>
#include<array>

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

using namespace std;
using dat=array<array<long long,2>,2>;
dat op(dat l,dat r)
{
	dat ret;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)
	{
		ret[i][j]=min(l[i][0]+r[0][j],l[i][1]+r[1][j]);
	}
	return ret;
}
dat e(){return (dat){{{0LL,(long long)1e18},{(long long)1e18,0LL}}};}
int N,Q;
int d1x[2<<17],d1y[2<<17],d2x[2<<17],d2y[2<<17];
int dist(int x1,int y1,int x2,int y2){return abs(x1-x2)+abs(y1-y2);}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=1;i<N;i++)
	{
		cin>>d1x[i]>>d1y[i]>>d2x[i]>>d2y[i];
		d1x[i]++;
		d2y[i]++;
	}
	vector<dat>init(N-2);
	for(int i=0;i<N-2;i++)
	{
		init[i][0][0]=dist(d1x[i+1],d1y[i+1],d1x[i+2],d1y[i+2]);
		init[i][0][1]=dist(d1x[i+1],d1y[i+1],d2x[i+2],d2y[i+2]);
		init[i][1][0]=dist(d2x[i+1],d2y[i+1],d1x[i+2],d1y[i+2]);
		init[i][1][1]=dist(d2x[i+1],d2y[i+1],d2x[i+2],d2y[i+2]);
	}
	atcoder::segtree<dat,op,e>P(init);
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int X1,Y1,X2,Y2;
		cin>>X1>>Y1>>X2>>Y2;
		int m1=max(X1,Y1),m2=max(X2,Y2);
		if(m1>m2)
		{
			swap(X1,X2);
			swap(Y1,Y2);
			swap(m1,m2);
		}
		if(m1==m2)
		{
			cout<<dist(X1,Y1,X2,Y2)<<"\n";
		}
		else
		{
			dat now=P.prod(m1-1,m2-2);
			long long ans=1e18;
			ans=min(ans,dist(X1,Y1,d1x[m1],d1y[m1])+now[0][0]+dist(d1x[m2-1],d1y[m2-1],X2,Y2));
			ans=min(ans,dist(X1,Y1,d1x[m1],d1y[m1])+now[0][1]+dist(d2x[m2-1],d2y[m2-1],X2,Y2));
			ans=min(ans,dist(X1,Y1,d2x[m1],d2y[m1])+now[1][0]+dist(d1x[m2-1],d1y[m2-1],X2,Y2));
			ans=min(ans,dist(X1,Y1,d2x[m1],d2y[m1])+now[1][1]+dist(d2x[m2-1],d2y[m2-1],X2,Y2));
			cout<<ans<<"\n";
		}
	}
}