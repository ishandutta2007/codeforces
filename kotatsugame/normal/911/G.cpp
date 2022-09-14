#include<iostream>
#include<array>
using namespace std;
#include<cstdio>
#include<cctype>
#include<string>
const int buffer_size=1<<20;
//input
int rd_char()
{
	static char buf[buffer_size];
	static int l=buffer_size,r=buffer_size;
	if(l==r&&r==buffer_size)
	{
		r=fread(buf,sizeof(char),1<<20,stdin);
		l=0;
	}
	if(l==r)return EOF;
	return buf[l++];
}
unsigned int rd_uint()
{
	int c;
	unsigned int x=0;
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return x;
}
int rd_int()
{
	bool neg=false;
	int c=rd_char();
	long long x=0;
	if(c=='-')neg=true;
	else x=c-'0';
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return neg?-x:x;
}
unsigned long long rd_ull()
{
	int c;
	unsigned long long x=0;
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return x;
}
long long rd_ll()
{
	bool neg=false;
	int c=rd_char();
	long long x=0;
	if(c=='-')neg=true;
	else x=c-'0';
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return neg?-x:x;
}
string rd_str()
{
	string ret;
	int c;
	while((c=rd_char())!='\n'&&c!=' '&&c!=EOF)ret+=c;
	return ret;
}
//output
struct writer_struct{
	char buf[buffer_size];
	int l=0;
	~writer_struct(){fwrite(buf,sizeof(char),l,stdout);}
}writer;
void flush()
{
	fwrite(writer.buf,sizeof(char),writer.l,stdout);
	fflush(stdout);
	writer.l=0;
}
void wt(char c)
{
	if(writer.l==buffer_size)
	{
		fwrite(writer.buf,sizeof(char),buffer_size,stdout);
		writer.l=0;
	}
	writer.buf[writer.l++]=c;
}
void wt(unsigned int x)
{
	if(x==0)wt('0');
	else
	{
		char f[10];
		int sz=0;
		while(x)
		{
			f[sz++]=x%10+'0';
			x/=10;
		}
		while(sz)wt(f[--sz]);
	}
}
void wt(int x)
{
	if(x<0)wt('-'),x=-x;
	wt((unsigned int)x);
}
void wt(unsigned long long x)
{
	if(x==0)wt('0');
	else
	{
		char f[20];
		int sz=0;
		while(x)
		{
			f[sz++]=x%10+'0';
			x/=10;
		}
		while(sz)wt(f[--sz]);
	}
}
void wt(long long x)
{
	if(x<0)wt('-'),x=-x;
	wt((unsigned long long)x);
}
void wt(const char*s){while(*s!='\0')wt(*s++);}
void wt(const string&s){for(char c:s)wt(c);}

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

#include<vector>
using F=array<short,100>;
F op(const F g,const F f)
{
	F ret;
	for(int i=0;i<100;i++)ret[i]=f[g[i]];
	return ret;
}
F eye;
F e(){return eye;}
int N,Q;
int A[2<<17];
int x[2<<17],y[2<<17];
vector<int>X[2<<17];
main()
{
	for(int i=0;i<100;i++)eye[i]=i;
	N=rd_uint();
	for(int i=0;i<N;i++)A[i]=rd_uint()-1;
	Q=rd_uint();
	for(int i=0;i<Q;i++)
	{
		int l=rd_uint()-1;
		int r=rd_uint();
		x[i]=rd_uint()-1;
		y[i]=rd_uint()-1;
		X[l].push_back(i);
		X[r].push_back(~i);
	}
	atcoder::segtree<F,op,e>P(Q);
	for(int i=0;i<N;i++)
	{
		for(int id:X[i])
		{
			if(id>=0)
			{
				F now=eye;
				now[x[id]]=y[id];
				P.set(id,now);
			}
			else
			{
				id=~id;
				P.set(id,eye);
			}
		}
		F now=P.all_prod();
		wt((unsigned)(now[A[i]]+1));
		wt(i+1==N?'\n':' ');
	}
}