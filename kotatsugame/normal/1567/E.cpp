#include<cstdio>
#include<set>

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
struct dat{
	long long sum;
	int len;
	dat(){}
	dat(long long s,int l):sum(s),len(l){}
};
dat op(dat a,dat b){return dat(a.sum+b.sum,a.len+b.len);}
dat e(){return dat(0,0);}
dat mp(int f,dat x){return dat(x.sum+(long long)f*x.len,x.len);}
int cmp(int f,int g){return f+g;}
int id(){return 0;}
int N,Q;
int A[2<<17];
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	set<pair<int,int> >S;
	vector<dat>init(N);
	for(int i=0;i<N;)
	{
		int j=i+1;
		while(j<N&&A[j-1]<=A[j])j++;
		S.insert(make_pair(i,j));
		for(int k=i;k<j;k++)init[k]=dat(k-i+1,1);
		i=j;
	}
	atcoder::lazy_segtree<dat,op,e,int,mp,cmp,id>P(init);
	for(int q=0;q<Q;q++)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
		{
			x--;
			if(x+1<N)
			{
				if(A[x]<=A[x+1])
				{
					if(y>A[x+1])
					{
						auto it=S.upper_bound(make_pair(x,N+1));
						it--;
						int l=it->first,r=it->second;
						S.erase(it);
						S.insert(make_pair(l,x+1));
						S.insert(make_pair(x+1,r));
						P.apply(x+1,r,-(x+1-l));
					}
				}
				else
				{
					if(y<=A[x+1])
					{
						auto jt=S.upper_bound(make_pair(x,N+1));
						auto it=jt;
						it--;
						int l=it->first;
						int r=jt->second;
						S.erase(it);
						S.erase(jt);
						S.insert(make_pair(l,r));
						P.apply(x+1,r,x+1-l);
					}
				}
			}
			if(x>0)
			{
				if(A[x-1]<=A[x])
				{
					if(A[x-1]>y)
					{
						auto it=S.upper_bound(make_pair(x-1,N+1));
						it--;
						int l=it->first,r=it->second;
						S.erase(it);
						S.insert(make_pair(l,x));
						S.insert(make_pair(x,r));
						P.apply(x,r,-(x-l));
					}
				}
				else
				{
					if(A[x-1]<=y)
					{
						auto jt=S.lower_bound(make_pair(x,0));
						auto it=jt;
						it--;
						int l=it->first;
						int r=jt->second;
						S.erase(it);
						S.erase(jt);
						S.insert(make_pair(l,r));
						P.apply(x,r,x-l);
					}
				}
			}
			A[x]=y;
		}
		else
		{
			x--;
			int L,R;
			long long ret=0;
			auto it=S.upper_bound(make_pair(x,N+1));
			it--;
			L=it->second;
			if(L>=y)
			{
				long long d=y-x;
				ret+=d*(d+1)/2;
			}
			else
			{
				long long d=L-x;
				ret+=d*(d+1)/2;
				it=S.lower_bound(make_pair(y,0));
				it--;
				R=it->first;
				d=y-R;
				ret+=d*(d+1)/2;
				ret+=P.prod(L,R).sum;
			}
			printf("%lld\n",ret);
		}
	}
}