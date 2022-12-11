#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<assert.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1LL<<62;
const int mod=1e9+7;

int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

namespace io {
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline char getc() {
		return gc();
	}
	inline void flush() {
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	inline void putc(char x) { *oS++=x; if (oS==oT) flush(); }
	template<class I> inline bool gi(I&x) {
		for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1; else if (c==-1) return false;
		for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
		return true;
	}
	template<class I> inline void print(I x) {
		if (!x) putc('0');
		if (x<0) putc('-'),x=-x;
		while (x) st[++tp]=x%10+'0',x/=10;
		while (tp) putc(st[tp--]);
	}
	inline bool gs(char*s, int&l) {
		for (c=gc();c<'a'||c>'z';c=gc()) if (c==-1) return false;
		for (l=0;c<='z'&&c>='a';c=gc()) s[l++]=c;
		s[l]=0;
		return true;
	}
	inline void printld(double x, int digit) {
		if (x < 0) putc('-'), x = -x;
		x += 0.5 * pow(0.1, digit);
		print((LL)x), putc('.');
		for (x -= (LL)x; digit; --digit) x = x * 10, putc((int)x + '0'), x -= (int)x;
	}
	inline void ps(const char*s) { for (int i=0,n=strlen(s);i<n;i++) putc(s[i]); }
	struct IOFLUSHER{ ~IOFLUSHER() { flush(); } } _ioflusher_;
};
using io::getc;
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;
using io::printld;

int f(int n) {
	n=(1<<n)-1;
	int ans=0,o;
	for (int i=1;i<n;i++)
		if (upmax(ans,__gcd(i^n,i&n)))
			o=i;
	return o;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,w,ans;
	gi(n);
	while (n--) {
		gi(w);
		for (int i=25;~i;i--)
			if (w>>i&1) {
				if (w==((1<<(i+1))-1)) {
					ans=1;
					for (int j=2;j*j<=w;j++)
						if (!(w%j))
							upmax(ans,w/j);
					print(ans);
				}
				else
					print((1<<(i+1))-1);
				putc(10);
				break;
			}
	}
	return 0;
}