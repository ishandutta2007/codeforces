/*
Author: QAQAutomaton
Lang: C++
Code: B.cpp
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
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n' || x=='\r');
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
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
char s[65][65];
signed main(){
#ifdef QAQAutoMaton 
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	int t,n,m;
	read(t);
	for(;t;--t){
		read(n,m);
		for(int i=1;i<=n;++i)read(s[i]+1);
		int a0=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s[i][j]=='P'){a0=0;break;}
			}
		}
		if(a0){write("0\n");continue;}
		int a1=15;
		for(int i=1;i<=n;++i){
			if(s[i][1]=='P')a1&=~1;
			if(s[i][m]=='P')a1&=~2;
		}
		for(int i=1;i<=m;++i){
			if(s[1][i]=='P')a1&=~4;
			if(s[n][i]=='P')a1&=~8;
		}
		if(a1){write("1\n");continue;}
		int a2=s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A';
		for(int i=1;i<=n;++i){
			int x=1;
			for(int j=1;j<=m;++j)if(s[i][j]=='P')x=0;
			a2|=x;
		}

		for(int j=1;j<=m;++j){
			int x=1;
			for(int i=1;i<=n;++i)if(s[i][j]=='P')x=0;
			a2|=x;
		}
		if(a2)write("2\n");
		else{
			int a3=0;
			for(int i=1;i<=n;++i)a3|=s[i][1]=='A'||s[i][m]=='A';
			for(int i=1;i<=m;++i)a3|=s[1][i]=='A'||s[n][i]=='A';
			if(a3){write("3\n");}
			else{
				int a4=0;
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j){
						if(s[i][j]=='A'){a4=1;break;}
					}
				}
				if(a4){write("4\n");}else write("MORTAL\n");
			}
		}
	}
	return 0;
}