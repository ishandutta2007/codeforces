#include<iostream>
#include<vector>
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
struct dat{
	long long L,R,val;
};
dat op(dat l,dat r){return dat{max(l.L,r.L),max(l.R,r.R),max(max(l.val,r.val),l.L+r.R)};}
dat e(){return dat{-(long long)1e18,-(long long)1e18,-(long long)1e18};}
long long opmax(long long l,long long r){return max(l,r);}
long long emax(){return -(long long)1e18;}
int N,Q;
int A[3][500001];
long long mid[500001],L[500001],R[500002];
long long dp[500001];
vector<pair<int,int> >qs[500001];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q;
	for(int i=0;i<3;i++)for(int j=1;j<=N;j++)cin>>A[i][j];
	for(int j=1;j<=N;j++)mid[j]=mid[j-1]+A[1][j];
	for(int j=1;j<=N;j++)L[j]=L[j-1]+A[0][j];
	for(int j=N;j>=1;j--)R[j]=R[j+1]+A[2][j];
	for(int j=1;j<=N;j++)L[j]-=mid[j-1];
	for(int j=1;j<=N;j++)R[j]+=mid[j];
	for(int j=0;j<=N;j++)dp[j]=-1e18;
	for(int i=0;i<Q;i++)
	{
		int l,r,k;cin>>l>>r>>k;
		qs[r].push_back(make_pair(l,k));
	}
	vector<long long>init_max(N+1);
	init_max[0]=emax();
	for(int i=1;i<=N;i++)init_max[i]=L[i];
	atcoder::segtree<long long,opmax,emax>PL(init_max),Pdp(N+1);
	for(int i=1;i<=N;i++)
	{
		long long now=-1e18;
		for(pair<int,int>p:qs[i])
		{
			long long tmp=max(
				Pdp.prod(p.first-1,i+1)-p.second,
				PL.prod(p.first,i+1)-p.second
			);
			now=max(now,tmp);
		}
		Pdp.set(i,now);
	}
	vector<dat>init(N+1);
	init[0]=e();
	for(int i=1;i<=N;i++)
	{
		init[i].L=max(L[i],Pdp.get(i-1));
		init[i].R=R[i];
		init[i].val=init[i].L+init[i].R;
	}
	atcoder::segtree<dat,op,e>seg(init);
	long long ans=-1e18;
	for(int r=1;r<=N;r++)
	{
		for(pair<int,int>p:qs[r])
		{
			ans=max(ans,seg.prod(p.first,r+1).val-p.second);
		}
	}
	cout<<ans<<endl;
}