/*
Author: QAQ Automaton
LANG: C++
PROG: E.cpp
Mail: cnyalilk@vip.qq.com
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
//#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
const int inf=0x3f3f3f3f;
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
		x=gc();
		return x!=EOF;
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
struct blk{
	int xl,yl,xr,yr;
} a[55];
vector<int> vx,vy;
int to[2100005],lst[2100005],beg[255],w[2100005],e=1;
void add(int u,int v,int flow){
	to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=flow;
	to[++e]=u;lst[e]=beg[v];beg[v]=e;w[e]=0;
}
int tag[255],cntx,cnty;
int q[255],*l,*r;
bool bfs(int s,int t){
	for(int i=1;i<=2+cntx+cnty;++i)	tag[i]=0;
	tag[s]=1;
	*(l=r=q)=s;
	while(l<=r){
		for(int i=beg[*l];i;i=lst[i])if(w[i]){
			if(!tag[to[i]]){
				tag[to[i]]=tag[*l]+1;
				*(++r)=to[i];
			}
		}
		++l;
	}
	return tag[t];
}
int dfs(int s,int t,int flow){
	if(s==t){return flow;}
	if(tag[s]==tag[t])return 0;
	int cnt=0;
	for(int i=beg[s];i;i=lst[i])if(w[i] && (tag[s]+1==tag[to[i]])){
		int nf=dfs(to[i],t,min(flow,w[i]));
		cnt+=nf;flow-=nf;
		w[i]-=nf;w[i^1]+=nf;
	}
	return cnt;
}
int dinic(){
	int cnt=0;
	while(bfs(1,2)){
		cnt+=dfs(1,2,inf);
	}
	return cnt;
}
int main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(a[i].xl,a[i].yl,a[i].xr,a[i].yr);
		++a[i].xr;++a[i].yr;
		vx.push_back(a[i].xl);
		vy.push_back(a[i].yl);
		vx.push_back(a[i].xr);
		vy.push_back(a[i].yr);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)),vx.end());
	sort(all(vy));
	vy.erase(unique(all(vy)),vy.end());
	cntx=vx.size()-1,cnty=vy.size()-1;
	for(int i=1;i<=cntx;++i)add(1,2+i,vx[i]-vx[i-1]);
	for(int i=1;i<=cnty;++i)add(2+cntx+i,2,vy[i]-vy[i-1]);
	for(int i=1;i<=m;++i){
		a[i].xl=lower_bound(all(vx),a[i].xl)-vx.begin();
		a[i].yl=lower_bound(all(vy),a[i].yl)-vy.begin();
		a[i].xr=lower_bound(all(vx),a[i].xr)-vx.begin();
		a[i].yr=lower_bound(all(vy),a[i].yr)-vy.begin();
		for(int x=a[i].xl+1;x<=a[i].xr;++x)
		for(int y=a[i].yl+1;y<=a[i].yr;++y)
			add(2+x,2+cntx+y,inf);
	}
	printf("%d\n",dinic());
	return 0;
}