#include<cstdio>
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


#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;
int N,Q;
bool ans[5<<17];
vector<pair<int,pair<int,int> > >G[3<<17];
vector<int>RG[5<<17];
vector<pair<pair<int,int>,pair<int,int> > >Qs;
bool vis[3<<17];
int depth[3<<17],L[3<<17],R[3<<17];
int pr[3<<17],pri[3<<17];
vector<pair<int,int> >D;
vector<int>cumX;
void dfs(int u,int d)
{
	depth[u]=d;
	vis[u]=true;
	L[u]=D.size();
	for(pair<int,pair<int,int> >e:G[u])
	{
		int v=e.first;
		if(!vis[v])
		{
			int x=e.second.first;
			int ei=e.second.second;
			RG[ei].push_back((int)D.size());
			D.push_back(make_pair(d,u));
			int b=cumX.back();cumX.push_back(b^x);
			pr[v]=u;pri[v]=ei;
			dfs(v,d+1);
			RG[ei].push_back(~(int)D.size());
			D.push_back(make_pair(d+1,v));
			b=cumX.back();cumX.push_back(b^x);
		}
	}
	R[u]=D.size();
}
int opadd(int a,int b){return a+b;}
int eadd(){return 0;}
using dat=pair<int,int>;
dat opmin(dat a,dat b){return a<b?a:b;}
dat emin(){return make_pair(1e9,-1);}
main()
{
	scanf("%d%d",&N,&Q);
	atcoder::dsu P(N);
	for(int i=0;i<Q;i++)
	{
		int u,v,x;scanf("%d%d%d",&u,&v,&x);u--,v--;
		if(P.same(u,v))
		{
			Qs.push_back(make_pair(make_pair(u,v),make_pair(i,x)));
		}
		else
		{
			P.merge(u,v);
			ans[i]=true;
			G[u].push_back(make_pair(v,make_pair(x,i)));
			G[v].push_back(make_pair(u,make_pair(x,i)));
		}
	}
	cumX.push_back(0);
	for(int i=0;i<N;i++)if(!vis[i])dfs(i,0);
	atcoder::segtree<dat,opmin,emin>Min(D);
	atcoder::segtree<int,opadd,eadd>Cnt(D.size());
	//for(pair<int,int>d:D)printf("%d %d\n",d.first,d.second+1);
	//for(pair<int,int>e:E)printf("%d ",e.second);puts("");
	for(pair<pair<int,int>,pair<int,int> >q:Qs)
	{
		int u=q.first.first,v=q.first.second;
		int id=q.second.first,x=q.second.second;
		//printf("%d\n",id);
		if(!(cumX[L[u]]^cumX[L[v]]^x))continue;
		//printf("%d\n",id);
		int w;
		if(L[u]<L[v])
		{
			w=Min.prod(L[u],R[v]).second;
		}
		else
		{
			w=Min.prod(L[v],R[u]).second;
		}
		//for(int i=0;i<E.size();i++)printf("%d ",Cnt.prod(i,i+1).first);puts("");
		//printf("%d-%d, %d-%d\n",Cnt.prod(L[w],L[u]).first,Cnt.prod(R[u],R[w]).first,Cnt.prod(L[w],L[v]).first,Cnt.prod(R[v],R[w]).first);
		if(Cnt.prod(L[w],L[u])>0||Cnt.prod(L[w],L[v])>0)continue;
		//printf("%d\n",id);
		ans[id]=true;
		while(u!=w)
		{
			int ei=pri[u];u=pr[u];
			for(int id:RG[ei])
			{
				if(id>=0)Cnt.set(id,Cnt.get(id)+1);
				if(id<0)Cnt.set(~id,Cnt.get(~id)-1);
			}
		}
		while(v!=w)
		{
			int ei=pri[v];v=pr[v];
			for(int id:RG[ei])
			{
				if(id>=0)Cnt.set(id,Cnt.get(id)+1);
				if(id<0)Cnt.set(~id,Cnt.get(~id)-1);
			}
		}
	}
	for(int i=0;i<Q;i++)puts(ans[i]?"YES":"NO");
}