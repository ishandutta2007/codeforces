/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
int a[3005],b[3005];
vector<int> to[3005];
pii f[3005][3005],g[3005];
int siz[3005];
pii operator +(pii a,pii b){return make_pair(a.x+b.x,a.y+b.y);}
void dfs(int x,int fa){
	f[x][0]=make_pair(0,b[x]);
	siz[x]=0;
	for(auto i:to[x])if(i!=fa){
		dfs(i,x);
		for(int j=0;j<=siz[x]+siz[i]+1;++j)g[j]=make_pair(-1,-1);
		for(int j=0;j<=siz[x];++j)for(int k=0;k<=siz[i];++k){
			chkmax(g[j+k],f[x][j]+f[i][k]);
			chkmax(g[j+k+1],make_pair(f[x][j].x+f[i][k].x+(f[i][k].y>0),f[x][j].y));
		}
		for(int j=0;j<=siz[x]+siz[i]+1;++j)f[x][j]=g[j];
		siz[x]+=siz[i]+1;
	}
/*	write(x,':');
	for(int i=0;i<=siz[x];++i)write(f[x][i].x,',',f[x][i].y,i==siz[x]?'\n':' ');*/
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int t,n,m,u,v;
	read(t);
	for(;t;--t){
		read(n,m);	
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<=n;++i){read(b[i]);b[i]-=a[i];to[i].clear();}
//		for(int i=1;i<=n;++i)write(b[i],i==n?'\n':' ');
		for(int i=1;i<n;++i){
			read(u,v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dfs(1,0);
		write(f[1][m-1].x+(f[1][m-1].y>0),'\n');
	}
	return 0;
}