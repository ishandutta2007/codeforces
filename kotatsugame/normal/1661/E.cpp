#include<iostream>
#include<array>

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
using dat=pair<int,array<char,6> >;
int pr[9];
int find(int u)
{
	if(pr[u]>=0)return pr[u]=find(pr[u]);
	else return u;
}
int usdTm[9],usdSz[9],Tmcnt=0;
dat op(dat l,dat r)
{
	if(l.first<0)return r;
	if(r.first<0)return l;
	dat ret;
	ret.first=l.first+r.first;
	for(int i=0;i<9;i++)pr[i]=-1;
	for(int i=0;i<3;i++)
	{
		if(l.second[i+3]!=0&&r.second[i]!=0)
		{
			int u=find(l.second[i+3]);
			int v=find(r.second[i]+4);
			if(u!=v)
			{
				if(-pr[u]<-pr[v])swap(u,v);
				pr[u]+=pr[v];
				pr[v]=u;
				ret.first--;
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		ret.second[i]=l.second[i]==0?0:find(l.second[i]);
		ret.second[i+3]=r.second[i+3]==0?0:find(r.second[i+3]+4);
	}
	Tmcnt++;
	int sz=0;
	for(int i=0;i<6;i++)if(ret.second[i]!=0)
	{
		if(usdTm[ret.second[i]]<Tmcnt)
		{
			usdTm[ret.second[i]]=Tmcnt;
			usdSz[ret.second[i]]=++sz;
		}
		ret.second[i]=usdSz[ret.second[i]];
	}
	return ret;
}
dat e(){return make_pair(-1,array<char,6>{});}
int N,Q;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	string S[3];
	for(int i=0;i<3;i++)cin>>S[i];
	vector<dat>init(N);
	for(int i=0;i<N;i++)
	{
		int V[3]={};
		int c=0;
		if(S[0][i]=='1')V[0]=c=1;
		if(S[1][i]=='1')V[1]=c=1;
		if(S[2][i]=='1')
		{
			if(V[1]!=0)V[2]=c=1;
			else if(V[0]!=0)V[2]=c=2;
			else V[2]=c=1;
		}
		init[i]=make_pair(c,array<char,6>{V[0],V[1],V[2],V[0],V[1],V[2]});
	}
	atcoder::segtree<dat,op,e>P(init);
	cin>>Q;
	for(;Q--;)
	{
		int L,R;cin>>L>>R;
		cout<<P.prod(L-1,R).first<<"\n";
	}
}