#include<cstdio>
#include<vector>
#include<algorithm>
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
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
            if (((r >> i) << i) != r) push(r >> i);
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
int Q;
int qt[1<<17],t[1<<17],l[1<<17],r[1<<17],v[1<<17],s[1<<17];
struct dat{
	long long diff,min;
	int dur;
	dat(){}
	dat(long long a,long long b,int c):diff(a),min(b),dur(c){}
};
dat op(dat a,dat b){return dat(a.diff+b.diff,min(a.min,a.diff+b.min),a.dur+b.dur);}
dat e(){return dat(0,0,0);}
const int Fid=-2e9;
dat mapping(int f,dat x){return f==Fid?x:dat((long long)f*x.dur,min(0LL,(long long)f*x.dur),x.dur);}
int comp(int f,int g){return f==Fid?g:f;}
int id(){return Fid;}
main()
{
	scanf("%d",&Q);
	vector<int>ts;
	for(int i=0;i<Q;i++)
	{
		scanf("%d",&qt[i]);
		if(qt[i]==1)
		{
			scanf("%d%d",&t[i],&s[i]);
			ts.push_back(t[i]);
		}
		else if(qt[i]==2)
		{
			scanf("%d",&t[i]);
			ts.push_back(t[i]);
		}
		else
		{
			scanf("%d%d%d",&l[i],&r[i],&v[i]);
			ts.push_back(l[i]);
			ts.push_back(r[i]);
		}
	}
	ts.push_back((int)2e9);
	sort(ts.begin(),ts.end());
	ts.erase(unique(ts.begin(),ts.end()),ts.end());
	vector<dat>init(ts.size()-1);
	for(int i=0;i+1<ts.size();i++)init[i]=dat(0,0,ts[i+1]-ts[i]);
	atcoder::lazy_segtree<dat,op,e,int,mapping,comp,id>P(init);
	set<pair<int,int> >S;
	S.insert(make_pair((int)2e9,0));
	for(int i=0;i<Q;i++)
	{
		if(qt[i]==1)
		{
			int ti=lower_bound(ts.begin(),ts.end(),t[i])-ts.begin();
			int nxti=lower_bound(ts.begin(),ts.end(),S.lower_bound(make_pair(t[i],0))->first)-ts.begin();
			P.apply(ti,nxti,s[i]);
			S.insert(make_pair(t[i],s[i]));
		}
		else if(qt[i]==2)
		{
			int ti=lower_bound(ts.begin(),ts.end(),t[i])-ts.begin();
			set<pair<int,int> >::iterator it=S.lower_bound(make_pair(t[i],(int)-2e9));
			it++;
			int nxti=lower_bound(ts.begin(),ts.end(),it->first)-ts.begin();
			it--;
			if(it!=S.begin())
			{
				--it;
				P.apply(ti,nxti,it->second);
				++it;
			}
			else
			{
				P.apply(ti,nxti,0);
			}
			S.erase(it);
		}
		else
		{
			if(v[i]==0)
			{
				printf("%d\n",l[i]);
				continue;
			}
			int li=lower_bound(ts.begin(),ts.end(),l[i])-ts.begin();
			set<pair<int,int> >::iterator it=S.lower_bound(make_pair(l[i],(int)-2e9));
			if(it!=S.begin())
			{
				set<pair<int,int> >::iterator jt=it;
				--jt;
				P.apply(lower_bound(ts.begin(),ts.end(),jt->first)-ts.begin(),
					lower_bound(ts.begin(),ts.end(),it->first)-ts.begin(),0);
			}
			long long V=v[i];
			int nr=P.max_right(li,[&V](dat x){return x.min+V>0;});
			int ri=lower_bound(ts.begin(),ts.end(),r[i])-ts.begin();
			if(ri<=nr)puts("-1");
			else
			{
				V+=P.prod(li,nr).diff;
				dat now=P.get(nr);
				printf("%.16f\n",ts[nr]-V*(double)now.dur/now.diff);
			}
			if(it!=S.begin())
			{
				set<pair<int,int> >::iterator jt=it;
				--jt;
				P.apply(lower_bound(ts.begin(),ts.end(),jt->first)-ts.begin(),
					lower_bound(ts.begin(),ts.end(),it->first)-ts.begin(),jt->second);
			}
		}
	}
}