#include<cstdio>
#include<vector>
#include<algorithm>
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
struct dat{
	int cnt;
	int sum;
	dat(){}
	dat(int a,int b):cnt(a),sum(b){}
};
dat op(dat a,dat b){return dat(a.cnt+b.cnt,a.sum+b.sum);}
dat e(){return dat(0,0);}
int N,M,K;
int use[2<<17];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	vector<pair<int,int> >A,B,C,D;
	atcoder::segtree<dat,op,e>P(10001);
	for(int i=0;i<N;i++)
	{
		int t,a,b;scanf("%d%d%d",&t,&a,&b);
		if(a&&b)
		{
			C.push_back(make_pair(t,i));
			P.set(t,op(P.get(t),dat(1,t)));
		}
		else if(a)A.push_back(make_pair(t,i));
		else if(b)B.push_back(make_pair(t,i));
		else
		{
			D.push_back(make_pair(t,i));
			P.set(t,op(P.get(t),dat(1,t)));
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	int two=M+1;
	int ans=(int)2e9+1;
	int ab=A.size();
	if(ab>B.size())ab=B.size();
	if(ab>M)ab=M;
	int now=0;
	for(int i=0;i<ab;i++)now+=A[i].first+B[i].first;
	for(int i=ab;i<A.size();i++)
	{
		P.set(A[i].first,op(P.get(A[i].first),dat(1,A[i].first)));
	}
	for(int i=ab;i<B.size();i++)
	{
		P.set(B[i].first,op(P.get(B[i].first),dat(1,B[i].first)));
	}
	int r=0;
	int cnt=ab*2;
	while(ab>=0)
	{
		while(r<C.size()&&ab+r<K)
		{
			P.set(C[r].first,op(P.get(C[r].first),dat(-1,-C[r].first)));
			cnt++;
			now+=C[r].first;
			r++;
		}
		if(ab+r<K)break;
		if(cnt==M)
		{
			if(ans>now)
			{
				ans=now;
				two=ab;
			}
		}
		else if(cnt<M)
		{
			int r=P.max_right(0,[&cnt](dat x){return x.cnt+cnt<M;});
			if(r<10001)
			{
				int nowcnt=cnt+P.prod(0,r).cnt;
				int nowsum=now+P.prod(0,r).sum;
				nowsum+=(M-nowcnt)*r;
				if(ans>nowsum)
				{
					ans=nowsum;
					two=ab;
				}
			}
		}
		ab--;
		if(ab>=0)
		{
			now-=A[ab].first;
			now-=B[ab].first;
			P.set(A[ab].first,op(P.get(A[ab].first),dat(1,A[ab].first)));
			P.set(B[ab].first,op(P.get(B[ab].first),dat(1,B[ab].first)));
			cnt-=2;
		}
	}
	if(two==M+1)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",ans);
	vector<int>ret;
	for(int i=0;i<two;i++)
	{
		ret.push_back(A[i].second);
		ret.push_back(B[i].second);
	}
	priority_queue<pair<int,int> >Q;
	for(int i=two;i<A.size();i++)Q.push(make_pair(-A[i].first,A[i].second));
	for(int i=two;i<B.size();i++)Q.push(make_pair(-B[i].first,B[i].second));
	for(pair<int,int>d:D)Q.push(make_pair(-d.first,d.second));
	{
		int r=0;
		while(r<C.size()&&two+r<K)
		{
			ret.push_back(C[r].second);
			r++;
		}
		for(int i=r;i<C.size();i++)Q.push(make_pair(-C[i].first,C[i].second));
		while(ret.size()<M)
		{
			int cost=-Q.top().first,id=Q.top().second;
			Q.pop();
			ret.push_back(id);
		}
	}
	for(int i=0;i<M;i++)printf("%d%c",ret[i]+1,i+1==M?10:32);
}