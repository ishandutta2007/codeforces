/*
Author: QAQ-Automaton
LANG: C++
PROG: D.cpp
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
const signed inf=0x3f3f3f3f;
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
int mnp[200005],p[200005],pri[200005],ps;
void init(int n){
	for(int i=2;i<=n;++i){
		if(!p[i]){pri[++ps]=i;mnp[i]=i;}
		for(int j=1;j<=ps && i*pri[j]<=n;++j){
			mnp[i*pri[j]]=pri[j];
			p[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}
vector<int> qwq[200005],to[200005];
int mx0[200005],mx1[200005],dep[200005],fa[200005],ans;
void dfs(int x,int f){
	dep[x]=dep[f]-1;	
	fa[x]=f;
	for(auto i:to[x])if(i!=f)dfs(i,x);
}
int main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,x,u,v;	
	read(n);
	init(200000);
	for(int i=1;i<=n;++i){
		for(read(x);x>1;){
			int mnpx=mnp[x];
			qwq[mnp[x]].push_back(i);
			while(!(x%mnpx))x/=mnpx;
		}
	}
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);to[v].push_back(u);
	}
	dfs(1,0);
	ans=0;
	for(int i=2;i<=200000;++i)if(qwq[i].size()){
		sort(all(qwq[i]),cmp_a<dep>);
		for(auto j:qwq[i])mx0[j]=mx1[j]=0;
		for(auto j:qwq[i]){
			chkmax(ans,mx0[j]+mx1[j]+1);
			if(mx1[j]+1 > mx1[fa[j]]){mx0[fa[j]]=mx1[fa[j]];mx1[fa[j]]=mx1[j]+1;}
			else if(mx1[j]+1>=mx0[fa[j]]){mx0[fa[j]]=mx1[j]+1;}
		}	
	}
	write(ans,'\n');
	return 0;
}