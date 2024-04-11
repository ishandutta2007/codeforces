/*
Author: CNYALI_LK
LANG: C++
PROG: 1076D.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;

const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
    const ll SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
    // getchar
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    // prll the remaining part
    inline void flush () {
        fwrite (obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
    // putchar
    inline void putc (char x) {
        *oS ++ = x;
        if (oS == oT) flush ();
    }
    // input a signed lleger
    inline void read (ll &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    inline void read (char &x) {
        x=gc();
    }
    inline void read(char *x){
        while((*x=gc())=='\n' || *x==' '||*x=='\r');
        while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
    }
    template<typename A,typename ...B>
    inline void read(A &x,B &...y){
        read(x);read(y...);
    }
    // prll a signed lleger
    inline void write (ll x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    inline void write (char x) {
        putc(x);
    }
    inline void write(const char *x){
        while(*x){putc(*x);++x;}
    }
    inline void write(char *x){
        while(*x){putc(*x);++x;}
    }
    template<typename A,typename ...B>
    inline void write(A x,B ...y){
        write(x);write(y...);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
ll beg[300005],to[600005],lst[600005],w[600005],e=1,dis[300005],pre[300005],out[300005];
void add(ll u,ll v,ll c){to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=c;}
priority_queue<pii,vector<pii>,greater<pii> >p;
ll n,m,k,u,v,c;
void dijkstra(ll u,ll k){
	p.push(make_pair(0,u));	
	for(ll i=1;i<=n;++i)dis[i]=inf;
	dis[u]=0;
	ll t=0;
	while(t<=k){
		u=p.top().y;		
		p.pop();
		if(out[u])continue;
		out[u]=1;
		if(t){write(pre[u],t==k?'\n':' ');}
		++t;
		for(ll i=beg[u];i;i=lst[i])if(chkmin(dis[to[i]],dis[u]+w[i])){pre[to[i]]=i/2;p.push(make_pair(dis[to[i]],to[i]));}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1076D.in","r",stdin);
	freopen("1076D.out","w",stdout);
#endif
	read(n,m,k);
	for(ll i=1;i<=m;++i){
		read(u,v,c);	
		add(u,v,c);
		add(v,u,c);
	}
	chkmin(k,n-1);
	write(k,'\n');
	dijkstra(1,k);
	return 0;
}