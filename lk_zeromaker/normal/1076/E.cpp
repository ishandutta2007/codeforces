/*
Author: CNYALI_LK
LANG: C++
PROG: 1076E.cpp
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
ll n,m,sum[300005],fa[300005],son[300005][2],rt,dep[300005],ans[300005];
pii a[300005];
vector<ll> to[300005],q[300005];
void dfs(ll x,ll f){
	dep[x]=dep[f]+1;
	for(auto i:to[x])if(i!=f)dfs(i,x);
}
#define push_up(x) sum[x]=sum[son[x][0]]+sum[son[x][1]]+a[x].y
void rotate(ll x){
	ll f=fa[x],g=fa[f],fx=son[f][1]==x;
	fa[son[g][son[g][1]==f]=x]=g;
	fa[son[f][fx]=son[x][fx^1]]=f;
	fa[son[x][fx^1]=f]=x;
	push_up(f);
	push_up(x);
}
void splay(ll x){
	while(fa[x]){
		ll f=fa[x];
		if(fa[f]){
			if((son[f][1]==x)==(son[fa[f]][1]==f))rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	rt=x;
}
void insert(ll x){
	if(!rt)rt=x;
	else{
		ll r=rt;
		while(1){
			if(son[r][a[x]>a[r]])
				r=son[r][a[x]>a[r]];
			else {fa[son[r][a[x]>a[r]]=x]=r;splay(x);break;}
		}
	}
}
void remove(ll x){
	splay(x);
	fa[son[x][0]]=fa[son[x][1]]=0;
	if(!son[x][0]){rt=son[x][1];return;}
	ll r=son[x][0];
	while(son[r][1])r=son[r][1];
	splay(r);
	fa[son[r][1]=son[x][1]]=r;
	push_up(r);
}
ll query(ll x){
	ll s=rt,w=0,ls;
	while(s){
		ls=s;
		if(a[s].x<x){s=son[s][1];}
		else{w+=sum[son[s][1]]+a[s].y;s=son[s][0];}
	}
	splay(ls);
	return w;
}
void DFS(ll x,ll f){
	for(auto i:q[x])insert(i);
	ans[x]=query(dep[x]);
	for(auto i:to[x])if(i!=f)DFS(i,x);
	for(auto i:q[x])remove(i);
}
int main(){
#ifdef cnyali_lk
	freopen("1076E.in","r",stdin);
	freopen("1076E.out","w",stdout);
#endif
	read(n);
	ll u,v,x;
	for(ll i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1,0);
	read(m);
	for(ll i=1;i<=m;++i){
		read(u,v,x);
		a[i]=make_pair(dep[u]+v,x);
		sum[i]=x;
		q[u].push_back(i);	
	}
	DFS(1,0);
	for(ll i=1;i<=n;++i)write(ans[i],i==n?'\n':' ');
	return 0;
}