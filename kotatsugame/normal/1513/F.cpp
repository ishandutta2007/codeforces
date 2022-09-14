#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

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
using dat=pair<int,int>;
dat op(dat a,dat b){return a.second<b.second?b:a;}
dat oq(dat a,dat b){return a.first-a.second<b.first-b.second?a:b;}
dat oR(dat a,dat b){return a.first<b.first?a:b;}
dat e(){return make_pair((int)2e9,0);}
int N;
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >AB(N);
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		AB[i].first=a;
	}
	for(int i=0;i<N;i++)
	{
		int b;
		scanf("%d",&b);
		AB[i].second=b;
	}
	sort(AB.begin(),AB.end());
	long long ans=0;
	for(pair<int,int>p:AB)ans+=abs(p.first-p.second);
	atcoder::segtree<dat,op,e>P(AB.size());
	atcoder::segtree<dat,oq,e>Q(AB.size());
	atcoder::segtree<dat,oR,e>R(AB.size());
	long long diff=0;
	priority_queue<pair<int,int> >Y;
	for(pair<int,int>p:AB)
	{
		int a=p.first,b=p.second;
		int ai=lower_bound(AB.begin(),AB.end(),make_pair(a,b))-AB.begin();
		if(a<=b)
		{
			P.set(ai,make_pair(a,b));
			R.set(ai,make_pair(a,b));
			Y.push(make_pair(-b,a));
		}
		if(a>=b)
		{
			while(!Y.empty()&&-Y.top().first<a)
			{
				int a1=Y.top().second,b1=-Y.top().first;
				int ai=lower_bound(AB.begin(),AB.end(),make_pair(a1,b1))-AB.begin();
				Y.pop();
				R.set(ai,e());
				Q.set(ai,make_pair(a1,b1));
			}
			int bi=lower_bound(AB.begin(),AB.end(),make_pair(b,0))-AB.begin();
			{
				dat q=Q.prod(bi,AB.size());
				int a1=q.first,b1=q.second;
				if(b1>0)
				{
					diff=min(diff,2LL*(a1-b1));
				}
			}
			{
				dat q=R.prod(bi,AB.size());
				int a1=q.first,b1=q.second;
				if(b1>0)
				{
					diff=min(diff,2LL*(a1-a));
				}
			}
			{
				dat q=P.prod(0,bi);
				int a1=q.first,b1=q.second;
				if(b1>0)
				{
					long long now;
					if(b1>=a)now=-a;
					else now=a-2LL*b1;
					now+=2LL*b;
					now-=a;
					diff=min(diff,now);
				}
			}
		}
	}
	printf("%lld\n",ans+diff);
}