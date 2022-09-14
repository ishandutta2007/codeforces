#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

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
int N,M;
long long op(long long a,long long b){return a<b?b:a;}
long long e(){return-1;}
int cnt[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	vector<pair<int,pair<long long,int> > >X(N);
	for(int i=0;i<N;i++)
	{
		int x,t;scanf("%d%d",&x,&t);
		X[i]=make_pair(x,make_pair(t,i));
	}
	sort(X.begin(),X.end());
	vector<long long>init(N);
	for(int i=0;i<N;i++)init[i]=X[i].first+X[i].second.first;
	atcoder::segtree<long long,op,e>P(init);
	multiset<pair<int,int> >S;
	for(int i=0;i<M;i++)
	{
		int p,b;scanf("%d%d",&p,&b);
		int id=P.max_right(0,[&p](long long x){return x<p;});
		if(id<N&&X[id].first<=p)
		{
			cnt[id]++;
			long long r=P.get(id)+b;
			auto it=S.lower_bound(make_pair(X[id].first,0));
			while(it!=S.end()&&it->first<=r)
			{
				cnt[id]++;
				r+=it->second;
				it=S.erase(it);
			}
			P.set(id,r);
		}
		else
		{
			S.insert(make_pair(p,b));
		}
	}
	vector<int>inv(N);
	for(int i=0;i<N;i++)inv[X[i].second.second]=i;
	for(int i=0;i<N;i++)
	{
		int id=inv[i];
		printf("%d %lld\n",cnt[id],P.get(id)-X[id].first);
	}
}