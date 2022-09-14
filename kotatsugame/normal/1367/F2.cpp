#include<cstdio>
#include<algorithm>
#include<vector>

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
int op(int a,int b){return a<b?b:a;}
int e(){return 0;}
int T,N;
int A[2<<17];
int dp[2<<17];
int inv[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >X(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			dp[i]=0;
			X[i]=make_pair(A[i],i);
		}
		sort(X.begin(),X.end());
		for(int i=0;i<N;i++)inv[X[i].second]=i;
		int ans=N;
		vector<int>ONE(N);
		{
			int now=0,prev=-1;
			for(int i=N;i--;)
			{
				if(X[i].first==prev)now++;
				else prev=X[i].first,now=1;
				ans=min(ans,N-now);
				ONE[i]=now;
			}
		}
		vector<int>BEF(N);
		{
			int now=0,prev=-1;
			for(int i=0;i<N;i++)
			{
				if(X[i].first==prev)now++;
				else prev=X[i].first,now=1;
				BEF[i]=now;
			}
		}
		atcoder::segtree<int,op,e>P(N);
		atcoder::segtree<int,op,e>Q(N);
		for(int i=N;i--;)
		{
			int id=inv[i];
			int lst=0;
			if(id==N-1)dp[i]=1;
			else
			{
				dp[i]=P.get(id+1)+1;
				if(X[id].first!=X[N-1].first)
				{
					int l=id,r=N-1;
					while(r-l>1)
					{
						int mid=l+r>>1;
						if(X[mid].first!=X[id].first)r=mid;
						else l=mid;
					}
					int rl=r,rr=N;
					while(rr-rl>1)
					{
						int mid=rl+rr>>1;
						if(X[mid].first!=X[r].first)rr=mid;
						else rl=mid;
					}
					if(r==id+1)
					{
						lst=P.get(r)+BEF[id];
						ans=min(ans,N-lst);
						dp[i]=max(dp[i],Q.prod(r,rr)+1);
						lst=Q.prod(r,rr)+BEF[id];
						ans=min(ans,N-lst);
					}
					else
					{
						lst=Q.prod(r,rr)+BEF[id];
						lst=max(lst,P.get(r)+BEF[id]);
						ans=min(ans,N-lst);
					}
				}
			}
			Q.set(id,ONE[id]);
			P.set(id,dp[i]);
			ans=min(ans,N-dp[i]);
		}
		printf("%d\n",ans);
	}
}