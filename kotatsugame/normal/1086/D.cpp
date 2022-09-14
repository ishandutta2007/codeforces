#include<cstdio>
#include<algorithm>
#include<utility>

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
int op(int a,int b){return a+b;}
int e(){return 0;}
int N,Q;
char Sin[2<<17];
int S[2<<17];
atcoder::segtree<int,op,e>cnt[3];
int ctoi(char c)
{
	if(c=='R')return 0;
	else if(c=='P')return 1;
	else return 2;
}
int lose[3][3]={
	{0,0,2},
	{0,1,1},
	{2,1,2}
};
main()
{
	scanf("%d%d%s",&N,&Q,Sin);
	for(int i=0;i<3;i++)cnt[i]=atcoder::segtree<int,op,e>(N);
	for(int i=0;i<N;i++)
	{
		S[i]=ctoi(Sin[i]);
		cnt[S[i]].set(i,1);
	}
	for(int i=0;i<=Q;i++)
	{
		int ans=N;
		pair<int,int>L[3];
		for(int j=0;j<3;j++)
		{
			L[j].first=cnt[j].max_right(0,[](int c){return c==0;});
			L[j].second=j;
		}
		sort(L,L+3);
		if(L[2].first==N)
		{
			if(L[1].first<N)
			{
				int t=lose[L[0].second][L[1].second];
				ans-=cnt[t].prod(0,N);
			}
		}
		else
		{
			ans-=cnt[lose[L[0].second][L[1].second]].prod(L[1].first,L[2].first);
			pair<int,int>R[3];
			for(int j=0;j<3;j++)
			{
				R[j].first=cnt[j].min_left(N,[](int c){return c==0;});
				R[j].second=j;
			}
			sort(R,R+3);
			ans-=cnt[lose[R[1].second][R[2].second]].prod(R[0].first,R[1].first);
		}
		printf("%d\n",ans);
		if(i<Q)
		{
			int pos;char c;
			scanf("%d %c",&pos,&c);
			pos--;
			cnt[S[pos]].set(pos,0);
			S[pos]=ctoi(c);
			cnt[S[pos]].set(pos,1);
		}
	}
}