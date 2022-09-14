#include<cstdio>
#include<vector>
#include<algorithm>

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
using dat=pair<int,int>;
dat op(dat a,dat b){return a<b?b:a;}
dat e(){return make_pair(0,-1);}
dat mp(dat f,dat x){return f.second==-1?x:f;}
dat cmp(dat f,dat g){return f.second==-1?g:f;}
dat id(){return make_pair(0,-1);}
int N,M;
vector<pair<int,int> >E[3<<17];
int pr[3<<17];
bool usd[3<<17];
main()
{
	scanf("%d%d",&N,&M);
	vector<int>vs;vs.reserve(M*2);
	for(int i=0;i<M;i++)
	{
		int I,L,R;
		scanf("%d%d%d",&I,&L,&R);
		I--;
		L--;
		vs.push_back(L);
		vs.push_back(R);
		E[I].push_back(make_pair(L,R));
	}
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<E[i].size();j++)
		{
			E[i][j].first=lower_bound(vs.begin(),vs.end(),E[i][j].first)-vs.begin();
			E[i][j].second=lower_bound(vs.begin(),vs.end(),E[i][j].second)-vs.begin();
		}
		sort(E[i].begin(),E[i].end());
		vector<pair<int,int> >now;
		for(pair<int,int>p:E[i])
		{
			if(now.empty()||now.back().second<p.first)now.push_back(p);
			else now.back().second=max(now.back().second,p.second);
		}
		E[i]=now;
	}
	atcoder::lazy_segtree<dat,op,e,dat,mp,cmp,id>P(vs.size());
	for(int i=0;i<N;i++)
	{
		int prid=-1,mx=-1;
		for(int j=0;j<E[i].size();j++)
		{
			int l=E[i][j].first,r=E[i][j].second;
			dat now=P.prod(l,r);
			if(mx<now.first)
			{
				mx=now.first;
				prid=now.second;
			}
		}
		pr[i]=prid;
		dat now=make_pair(mx+1,i);
		for(int j=0;j<E[i].size();j++)
		{
			int l=E[i][j].first,r=E[i][j].second;
			P.apply(l,r,now);
		}
	}
	dat ret=P.all_prod();
	int id=ret.second;
	while(id!=-1)
	{
		usd[id]=true;
		id=pr[id];
	}
	vector<int>ans;
	for(int i=0;i<N;i++)if(!usd[i])ans.push_back(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
}