/*
Author: QAQ-Automaton
LANG: C++
PROG: 1117G.cpp
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
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
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
	// prll a signed lleger
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
struct smt{
	ll ls,rs;
	smt *l,*r;
	ll tag,sum;
	void push_up(){
		sum=l->sum+r->sum;
	}
	void put_tag(ll w){
		tag+=w;sum+=(rs-ls+1)*w;
	}
	void push_down(){
		l->put_tag(tag);r->put_tag(tag);tag=0;
	}
	smt(ll la,ll ra){
		ls=la;rs=ra;
		tag=0;sum=(rs-ls+1);
		if(ls==rs)l=r=0;
		else{
			ll mid=(ls+rs)>>1;
			l=new smt(ls,mid);r=new smt(mid+1,rs);
		}
	}
	void clear(){
		tag=0;sum=0;
		if(l){l->clear();r->clear();}
	}
	void Add(ll la,ll ra,ll w){
		if(la<=ls && rs<=ra){put_tag(w);return;}	
		push_down();
		if(la<=l->rs)l->Add(la,ra,w);
		if(r->ls<=ra)r->Add(la,ra,w);
		push_up();
	}
	ll Sum(ll la,ll ra){
		if(la<=ls && rs<=ra)return sum;
		push_down();
		ll s=0;
		if(la<=l->rs)s+=l->Sum(la,ra);
		if(r->ls<=ra)s+=r->Sum(la,ra);
		return s;
	}
};
smt *rt;
ll stk[1000005],top,id[1000005];
ll l[1000005],r[1000005],p[1000005],ans[1000005];
vector<pii> qwq[1000005];
int main(){
#ifdef QAQAutoMaton 
	freopen("1117G.in","r",stdin);
	freopen("1117G.out","w",stdout);
#endif
	ll n,q;
	read(n,q);
	rt=new smt(1,n);
	for(ll i=1;i<=n;++i)read(p[i]);
	for(ll i=1;i<=q;++i){
		read(l[i]);
	}
	for(ll i=1;i<=q;++i){
		read(r[i]);
		qwq[r[i]].push_back(make_pair(l[i],i));
	}
	for(ll i=1;i<=n;++i){
		while(top && stk[top]<p[i]){
			--top;
			rt->Add(id[top]+1,id[top+1],1);
		}
		stk[++top]=p[i];
		id[top]=i;
		for(auto s:qwq[i]){
			ans[s.y]+=rt->Sum(s.x,i);
		}
	}

	for(ll i=1;i<=n;++i)qwq[i].clear();
	rt->clear();
	id[top=0]=n+1;
	for(ll i=1;i<=q;++i)qwq[l[i]].push_back(make_pair(r[i],i));
	for(ll i=n;i;--i){
		while(top && stk[top]<p[i]){
			--top;
			rt->Add(id[top+1],id[top]-1,1);
		}
		stk[++top]=p[i];
		id[top]=i;
		for(auto s:qwq[i]){
			ans[s.y]+=rt->Sum(i,s.x);
		}
	}
	for(ll i=1;i<=q;++i)write(ans[i],i==q?'\n':' ');

	return 0;
}