/*
Author: QAQAutomaton
LANG: C++
PROG: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n'||x=='\r')if(x==EOF)return 0;
		return 1;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// print a signed integer
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
vector<int> a[1000005];
vector<int> b[1000005];
vector<int> c[1000005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,m;
	read(n,m);
	for(int i=0;i<=n+1;++i)a[i].resize(m+2);
	for(int i=0;i<=n+1;++i)b[i].resize(m+2);
	for(int i=0;i<=n+1;++i)c[i].resize(m+2);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		char c;
		read(c);
		a[i][j]=(c=='X');
		b[i][j]=1-a[i][j]+b[i][j-1]+b[i-1][j]-b[i-1][j-1];
	}
	int l=0,r=min(n,m),mid;
	while(l<=r){
		mid=(l+r)>>1;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)c[i][j]=0;
		for(int i=1;i+mid*2<=n;++i){
			for(int j=1;j+mid*2<=m;++j){
				if(!(b[i+mid*2][j+mid*2]-b[i-1][j+mid*2]-b[i+mid*2][j-1]+b[i-1][j-1])){
					
					++c[i][j];
					--c[i+mid*2+1][j];
					--c[i][j+mid*2+1];
					++c[i+mid*2+1][j+mid*2+1];
				}
			}
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
		bool ok=1;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j] && !(c[i][j]))ok=0;
		if(ok)l=mid+1;
		else r=mid-1;
	}
	write(l-1,'\n');
	mid=l-1;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)c[i][j]=0;
		for(int i=1;i+mid*2<=n;++i){
			for(int j=1;j+mid*2<=m;++j){
				if(!(b[i+mid*2][j+mid*2]-b[i-1][j+mid*2]-b[i+mid*2][j-1]+b[i-1][j-1])){
					c[i+mid][j+mid]=1;
				}
			}
		}

	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)if(c[i][j])write('X');else write('.');
		write('\n');
	}
	return 0;
}