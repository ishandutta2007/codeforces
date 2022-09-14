#include<cstdio>
#include<queue>
#include<map>
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
	int u[3],w[3];
	dat(){}
};
dat op(const dat a,const dat b)
{
	dat ret;
	int ai=0,bi=0;
	if(a.w[ai]<b.w[bi])
	{
		ret.w[0]=a.w[ai];
		ret.u[0]=a.u[ai];
	}
	else
	{
		ret.w[0]=b.w[bi];
		ret.u[0]=b.u[bi];
	}
	if(ret.u[0]==a.u[ai])ai++;
	if(ret.u[0]==b.u[bi])bi++;
	if(a.w[ai]<b.w[bi])
	{
		ret.w[1]=a.w[ai];
		ret.u[1]=a.u[ai];
	}
	else
	{
		ret.w[1]=b.w[bi];
		ret.u[1]=b.u[bi];
	}
	while(ret.u[0]==a.u[ai]||ret.u[1]==a.u[ai])ai++;
	while(ret.u[0]==b.u[bi]||ret.u[1]==b.u[bi])bi++;
	if(a.w[ai]<b.w[bi])
	{
		ret.w[2]=a.w[ai];
		ret.u[2]=a.u[ai];
	}
	else
	{
		ret.w[2]=b.w[bi];
		ret.u[2]=b.u[bi];
	}
	return ret;
}
dat eye;
dat e(){return eye;}
int N,M;
map<pair<int,int>,int>ei;int esz;
int U[2<<17],V[2<<17],W[2<<17];
bool del[2<<17];
set<pair<int,int> >EW;
atcoder::segtree<dat,op,e>P;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >EQ[1<<17];
void add(int u,int v,int w)
{
	if(u>v)swap(u,v);
	U[esz]=u;
	V[esz]=v;
	W[esz]=w;
	ei[make_pair(u,v)]=esz;
	EW.insert(make_pair(w,esz));
	EQ[u].push(make_pair(w,esz));
	dat now=P.get(u);
	if(now.w[2]>w)
	{
		now.u[2]=v;
		now.w[2]=w;
		if(now.w[1]>w)
		{
			now.u[2]=now.u[1];
			now.w[2]=now.w[1];
			now.u[1]=v;
			now.w[1]=w;
			if(now.w[0]>w)
			{
				now.u[1]=now.u[0];
				now.w[1]=now.w[0];
				now.u[0]=v;
				now.w[0]=w;
			}
		}
	}
	P.set(u,now);
	esz++;
}
int check(int Ei,int Ej)
{
	if(U[Ei]==U[Ej]||U[Ei]==V[Ej])return U[Ei];
	else if(V[Ei]==U[Ej]||V[Ei]==V[Ej])return V[Ei];
	else return -1;
}
int calc(int u,int v)
{
	if(u>v)swap(u,v);
	//printf("calc(%d,%d):",u,v);
	int ans=2e9;
	dat ret=P.prod(0,u);
	if(ret.u[0]!=u&&ret.u[0]!=v)ans=ret.w[0];
	else if(ret.u[1]!=u&&ret.u[1]!=v)ans=ret.w[1];
	else if(ret.u[2]!=u&&ret.u[2]!=v)ans=ret.w[2];
	//printf(" %d",ans);
	ret=P.prod(u+1,v);
	if(ret.u[0]!=u&&ret.u[0]!=v)ans=min(ans,ret.w[0]);
	else if(ret.u[1]!=u&&ret.u[1]!=v)ans=min(ans,ret.w[1]);
	else if(ret.u[2]!=u&&ret.u[2]!=v)ans=min(ans,ret.w[2]);
	ret=P.prod(v+1,N);
	//printf(" %d",ans);
	if(ret.u[0]!=u&&ret.u[0]!=v)ans=min(ans,ret.w[0]);
	else if(ret.u[1]!=u&&ret.u[1]!=v)ans=min(ans,ret.w[1]);
	else if(ret.u[2]!=u&&ret.u[2]!=v)ans=min(ans,ret.w[2]);
	//printf(" %d\n",ans);
	return ans;
}
void answer()
{
	int e[4];
	{
		auto it=EW.begin();
		for(int i=0;i<4;i++)
		{
			e[i]=it->second;
			it++;
		}
	}
	//printf("DBG : %d %d %d %d\n",W[e[0]],W[e[1]],W[e[2]],W[e[3]]);
	int p=check(e[0],e[1]);
	if(p<0)
	{
		printf("%d\n",W[e[0]]+W[e[1]]);
		return;
	}
	long long ans=1e10;
	if(check(e[2],e[3])<0)ans=W[e[2]]+W[e[3]];
	//printf("(2,3) : %lld\n",ans);
	ans=min(ans,(long long)calc(U[e[0]],V[e[0]])+W[e[0]]);
	//printf("(1,*) : %lld\n",ans);
	ans=min(ans,(long long)calc(U[e[1]],V[e[1]])+W[e[1]]);
	//printf("(2,*) : %lld\n",ans);
	ans=min(ans,(long long)calc(U[e[0]]==p?V[e[0]]:U[e[0]],U[e[1]]==p?V[e[1]]:U[e[1]])+W[e[0]]+W[e[1]]);
	printf("%lld\n",ans);
}
main()
{
	scanf("%d%d",&N,&M);
	eye.u[0]=N;
	eye.u[1]=N+1;
	eye.u[2]=N+2;
	eye.w[0]=2e9;
	eye.w[1]=2e9;
	eye.w[2]=2e9;
	P=atcoder::segtree<dat,op,e>(N);
	for(int i=0;i<M;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		add(u,v,w);
	}
	int Q;scanf("%d",&Q);
	answer();
	for(int q=0;q<Q;q++)
	{
		int t;scanf("%d",&t);
		if(t==1)
		{
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			add(u,v,w);
		}
		else
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			if(u>v)swap(u,v);
			int idx=ei[make_pair(u,v)];
			EW.erase(make_pair(W[idx],idx));
			del[idx]=true;
			dat now;
			int ui[3]={-1,-1,-1};
			for(int i=0;i<3;i++)
			{
				while(!EQ[u].empty()&&del[EQ[u].top().second])EQ[u].pop();
				if(EQ[u].empty())
				{
					now.u[i]=N+i;
					now.w[i]=2e9;
				}
				else
				{
					int eid=EQ[u].top().second;EQ[u].pop();
					now.u[i]=V[eid];
					now.w[i]=W[eid];
					ui[i]=eid;
				}
			}
			P.set(u,now);
			for(int i=0;i<3;i++)
			{
				if(ui[i]<0)break;
				EQ[u].push(make_pair(W[ui[i]],ui[i]));
			}
		}
		answer();
	}
}