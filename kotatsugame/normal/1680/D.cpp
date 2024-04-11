#include<iostream>
#include<algorithm>
#include<utility>

#include <algorithm>
#include <cassert>
#include <iostream>
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
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
            if (((r >> i) << i) != r) push((r - 1) >> i);
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

using namespace std;
long long opmax(long long a,long long b){return a<b?b:a;}
long long opmin(long long a,long long b){return a<b?a:b;}
long long emax(){return-(long long)1e18;}
long long emin(){return(long long)1e18;}
long long mp(long long f,long long x){return f+x;}
long long id(){return 0LL;}
int N,K;
int A[3000];
bool usd[3000];
long long solve(int pc,int nc)
{
	long long ret=-1;
	{
		vector<long long>init(N+1,0LL);
		vector<int>emp;
		{
			long long cur=0;
			for(int i=0;i<N;i++)
			{
				if(usd[i])
				{
					emp.push_back(i);
					if(emp.size()<=pc)cur+=K;
					else cur-=K;
				}
				else cur+=A[i];
				init[i+1]=cur;
			}
		}
		atcoder::lazy_segtree<long long,opmax,emax,long long,mp,mp,id>Pmax(init);
		atcoder::lazy_segtree<long long,opmin,emin,long long,mp,mp,id>Pmin(init);
		ret=max(ret,Pmax.all_prod()-Pmin.all_prod());
		for(int i=0;i<nc;i++)
		{
			int neg=emp[i]+1,pos=emp[i+pc]+1;
			Pmax.apply(neg,pos,-2LL*K);
			Pmin.apply(neg,pos,-2LL*K);
			ret=max(ret,Pmax.all_prod()-Pmin.all_prod());
		}
	}
	{
		vector<long long>init(N+1,0LL);
		vector<int>emp;
		{
			long long cur=0;
			for(int i=0;i<N;i++)
			{
				if(usd[i])
				{
					emp.push_back(i);
					if(emp.size()<=nc)cur-=K;
					else cur+=K;
				}
				else cur+=A[i];
				init[i+1]=cur;
			}
		}
		atcoder::lazy_segtree<long long,opmax,emax,long long,mp,mp,id>Pmax(init);
		atcoder::lazy_segtree<long long,opmin,emin,long long,mp,mp,id>Pmin(init);
		ret=max(ret,Pmax.all_prod()-Pmin.all_prod());
		for(int i=0;i<pc;i++)
		{
			int neg=emp[i]+1,pos=emp[i+nc]+1;
			Pmax.apply(neg,pos,2LL*K);
			Pmin.apply(neg,pos,2LL*K);
			ret=max(ret,Pmax.all_prod()-Pmin.all_prod());
		}
	}
	return ret+1;
}
main()
{
	cin>>N>>K;
	long long sum=0;
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		sum+=A[i];
		if(A[i]==0)usd[i]=true,cnt++;
	}
	if((abs(sum)+K-1)/K>cnt)
	{
		cout<<-1<<endl;
		return 0;
	}
	int nc=0,pc=0,mc,md;
	{
		bool neg=false;
		if(sum<0)sum=-sum,neg=true;
		nc=sum/K;
		sum%=K;
		int rest=cnt-nc;
		if(sum==0)
		{
			nc+=rest/2;
			pc+=rest/2;
			mc=rest%2;
			md=0;
		}
		else
		{
			rest--;
			nc+=rest/2;
			pc+=rest/2;
			rest%=2;
			if(rest==0)
			{
				mc=1;
				md=-sum;
			}
			else
			{
				mc=1;
				nc++;
				md=K-sum;
			}
		}
		if(neg)
		{
			swap(pc,nc);
			md=-md;
		}
	}
	long long ans=0;
	if(mc==0)ans=solve(pc,nc);
	else
	{
		for(int i=0;i<N;i++)if(usd[i])
		{
			usd[i]=false;
			A[i]=md;
			ans=max(ans,solve(pc,nc));
			A[i]=0;
			usd[i]=true;
		}
	}
	cout<<ans<<endl;
}