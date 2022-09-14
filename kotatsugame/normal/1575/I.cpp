#include<iostream>
#include<vector>

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
long long op(long long a,long long b){return a<b?a:b;}
long long e(){return 1e18;}
long long mp(long long f,long long x){return f+x;}
long long cmp(long long f,long long g){return f+g;}
long long id(){return 0;}
vector<long long>init;
int A[1<<17];
#include<vector>
struct euler_tour{
	vector<vector<int> >G;
	vector<int>V;
	vector<pair<int,int> >range;
	euler_tour(int N_=0):G(N_),range(N_),V(){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void build(int root=0){dfs(root,-1,0);}
	void dfs(int u,int p,long long cumsum)
	{
		range[u].first=V.size();
		V.push_back(u);
		init.push_back(cumsum);
		for(int v:G[u])if(v!=p)dfs(v,u,cumsum+A[u]+A[v]);
		range[u].second=V.size();
	}
	size_t size()const{return V.size();}
	int operator[](int k)const{return V[k];}
	const pair<int,int>&subtree(int v)const{return range[v];}
};
#include<vector>
struct LCA{
	int N;
	vector<vector<int> >G,parent;
	vector<int>depth;
	LCA(int N_=0):N(N_),G(N_),depth(N_)
	{
		int lg=0;
		while((1<<lg)+1<N_)lg++;
		parent.assign(lg+1,vector<int>(N_));
	}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void dfs(int u,int p,int d)
	{
		depth[u]=d;
		parent[0][u]=p;
		for(int v:G[u])if(v!=p)dfs(v,u,d+1);
	}
	void build(int root=0)
	{
		dfs(root,-1,0);
		for(int k=1;k<parent.size();k++)
		{
			for(int i=0;i<N;i++)
			{
				if(parent[k-1][i]==-1)parent[k][i]=-1;
				else parent[k][i]=parent[k-1][parent[k-1][i]];
			}
		}
	}
	int lca(int u,int v)
	{
		if(depth[u]>depth[v])swap(u,v);
		for(int k=0;k<parent.size();k++)if(depth[v]-depth[u]>>k&1)v=parent[k][v];
		if(u==v)return u;
		for(int k=parent.size();k--;)if(parent[k][u]!=parent[k][v])
		{
			u=parent[k][u];
			v=parent[k][v];
		}
		return parent[0][u];
	}
	int dist(int u,int v)
	{
		int w=lca(u,v);
		return depth[u]+depth[v]-2*depth[w];
	}
};
int N,Q;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		A[i]=abs(A[i]);
	}
	euler_tour P(N);
	LCA lca(N);
	for(int i=1;i<N;i++)
	{
		int u,v;cin>>u>>v;
		u--,v--;
		P.add_edge(u,v);
		lca.add_edge(u,v);
	}
	P.build();
	lca.build();
	atcoder::lazy_segtree<long long,op,e,long long,mp,cmp,id>seg(init);
	for(;Q--;)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int u,c;cin>>u>>c;u--;c=abs(c);
			pair<int,int>lr=P.subtree(u);
			seg.apply(lr.first,lr.second,2*(c-A[u]));
			seg.set(lr.first,seg.get(lr.first)+A[u]-c);
			A[u]=c;
		}
		else
		{
			int u,v;cin>>u>>v;u--,v--;
			int w=lca.lca(u,v);
			cout<<seg.get(P.subtree(u).first)+seg.get(P.subtree(v).first)-2*seg.get(P.subtree(w).first)<<"\n";
		}
	}
}