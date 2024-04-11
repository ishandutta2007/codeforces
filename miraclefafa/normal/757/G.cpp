#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
void myassert(bool f) { assert(f); }
ll powmod(ll a,ll b) {ll res=1;a%=mod; myassert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
namespace fastIO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    //fread->read 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
            //{printf("IO error!\n");system("pause");for (;;);exit(0);} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(double &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (ch=='.'){ 
            double tmp=1; ch=nc(); 
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0'); 
        } 
        if (sign)x=-x; 
    } 
    inline void read(char *s){ 
        char ch=nc(); 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch; 
        *s=0; 
    } 
    inline void read(char &c){ 
        for (c=nc();blank(c);c=nc()); 
        if (IOerror){c=-1;return;} 
    } 
    //getchar->read 
    inline void read1(int &x){ 
        char ch;int bo=0;x=0; 
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
        if (bo)x=-x; 
    } 
    inline void read1(ll &x){ 
        char ch;int bo=0;x=0; 
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
        if (bo)x=-x; 
    } 
    inline void read1(double &x){ 
        char ch;int bo=0;x=0; 
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
        if (ch=='.'){ 
            double tmp=1; 
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar()); 
        } 
        if (bo)x=-x; 
    } 
    inline void read1(char *s){ 
        char ch=getchar(); 
        for (;blank(ch);ch=getchar()); 
        for (;!blank(ch);ch=getchar())*s++=ch; 
        *s=0; 
    } 
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());} 
    //scanf->read 
    inline void read2(int &x){scanf("%d",&x);} 
    inline void read2(ll &x){ 
        #ifdef _WIN32 
            scanf("%I64d",&x); 
        #else 
        #ifdef __linux 
            scanf("%lld",&x); 
        #else 
            puts("error:can't recognize the system!"); 
        #endif 
        #endif 
    } 
    inline void read2(double &x){scanf("%lf",&x);} 
    inline void read2(char *s){scanf("%s",s);} 
    inline void read2(char &c){scanf(" %c",&c);} 
    inline void readln2(char *s){gets(s);} 
    //fwrite->write 
    struct Ostream_fwrite{ 
        char *buf,*p1,*pend; 
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
        void out(char ch){ 
            if (p1==pend){ 
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
            } 
            *p1++=ch; 
        } 
        void print(int x){ 
            static char s[15],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); 
        } 
        void println(int x){ 
            static char s[15],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void print(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); 
        } 
        void println(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void print(double x,int y){ 
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000, 
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL, 
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL}; 
            if (x<-1e-12)out('-'),x=-x;x*=mul[y]; 
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; 
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2); 
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);} 
        } 
        void println(double x,int y){print(x,y);out('\n');} 
        void print(char *s){while (*s)out(*s++);} 
        void println(char *s){while (*s)out(*s++);out('\n');} 
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
        ~Ostream_fwrite(){flush();} 
    }Ostream; 
    inline void print(int x){Ostream.print(x);} 
    inline void println(int x){Ostream.println(x);} 
    inline void print(char x){Ostream.out(x);} 
    inline void println(char x){Ostream.out(x);Ostream.out('\n');} 
    inline void print(ll x){Ostream.print(x);} 
    inline void println(ll x){Ostream.println(x);} 
    inline void print(double x,int y){Ostream.print(x,y);} 
    inline void println(double x,int y){Ostream.println(x,y);} 
    inline void print(char *s){Ostream.print(s);} 
    inline void println(char *s){Ostream.println(s);} 
    inline void println(){Ostream.out('\n');} 
    inline void flush(){Ostream.flush();} 
    //puts->write 
    char Out[OUT_SIZE],*o=Out; 
    inline void print1(int x){ 
        static char buf[15]; 
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
        while(x)*p1++=x%10+'0',x/=10; 
        while(p1--!=buf)*o++=*p1; 
    } 
    inline void println1(int x){print1(x);*o++='\n';} 
    inline void print1(ll x){ 
        static char buf[25]; 
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
        while(x)*p1++=x%10+'0',x/=10; 
        while(p1--!=buf)*o++=*p1; 
    } 
    inline void println1(ll x){print1(x);*o++='\n';} 
    inline void print1(char c){*o++=c;} 
    inline void println1(char c){*o++=c;*o++='\n';} 
    inline void print1(char *s){while (*s)*o++=*s++;} 
    inline void println1(char *s){print1(s);*o++='\n';} 
    inline void println1(){*o++='\n';} 
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}} 
    struct puts_write{ 
        ~puts_write(){flush1();} 
    }_puts; 
    inline void print2(int x){printf("%d",x);} 
    inline void println2(int x){printf("%d\n",x);} 
    inline void print2(char x){printf("%c",x);} 
    inline void println2(char x){printf("%c\n",x);} 
    inline void print2(ll x){ 
        #ifdef _WIN32 
            printf("%I64d",x); 
        #else 
        #ifdef __linux 
            printf("%lld",x); 
        #else 
            puts("error:can't recognize the system!"); 
        #endif 
        #endif 
    } 
    inline void println2(ll x){print2(x);printf("\n");} 
    inline void println2(){printf("\n");} 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 
using namespace fastIO; 

const int N=201000;
int q[N],f[N],vis[N],ss[N],ms[N];
int lev[N],brh[N][26],rt[N][26],u,v,w,n;
ll dep[N][26],tot;
vector<PII> e[N];
VI s[N];
int find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,SZ(e[u])) {
			int v=e[u][j].fi;
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		ss[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-ss[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		ss[f[q[i]]]+=ss[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],ss[q[i]]);
	}
	return 0;
}
int zs=0,zs2=0;
void dfs(int u,int f,ll d,int br,int l,int r) {
	zs++; zs2++;
	dep[u][l]=d; brh[u][l]=br; rt[u][l]=r;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i].fi;
		if (vis[v]||v==f) continue;
		dfs(v,u,d+e[u][i].se,br,l,r);
	}
}
typedef pair<int,pair<ll,int> > Z;
Z pool[N*55],*cur=pool;
Z *tdep[N],*bdep[N][26];
int st[N],sb[N][26];
void gao(int u,int l) {
	u=find(u);
	lev[u]=l; rt[u][l]=u;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i].fi;
		if (vis[v]) continue;
		s[u].pb(v);
		dep[v][l]=e[u][i].se;
	}
	zs=1;
	rep(i,0,SZ(s[u])) {
		int v=s[u][i]; zs2=0;
		dfs(v,u,dep[v][l],v,l,u);
		bdep[v][l]=cur; cur+=zs2;
	}
	tdep[u]=cur; cur+=zs;
	vis[u]=1;
	rep(i,0,SZ(s[u])) gao(s[u][i],l+1);
}
int pt[N][26],pb[N][26];
void build(int u,int t) {
	rep(i,0,lev[u]+1) {
		int rr=rt[u][i];
		Z* h=tdep[rr];
		pair<ll,int> r=mp(0,0);
		if (st[rr]) r=h[st[rr]-1].se;
		r.fi+=dep[u][i]; r.se++;
		pt[t][i]=st[rr];
		h[st[rr]++]=mp(t,r);
	}
	rep(i,0,lev[u]) {
		int rr=brh[u][i];
		Z* h=bdep[rr][i];
		pair<ll,int> r=mp(0,0);
		if (sb[rr][i]) r=h[sb[rr][i]-1].se;
		r.fi+=dep[u][i]; r.se++;
		pb[t][i]=sb[rr][i];
		h[sb[rr][i]++]=mp(t,r);
	}
}
int pp[30];
void modify(int u,int v,int t) {
	int lv=0;
	rep(i,0,lev[v]+1) pp[i]=pt[t+1][i];
	rep(i,0,lev[u]+1) {
		Z* h=tdep[rt[u][i]];
		auto p=h+pt[t][i];
		if (pt[t][i]!=st[rt[u][i]]-1&&(p+1)->fi==t+1) {p->se.fi-=dep[u][i]-dep[v][i]; lv=i+1; }
		else p->fi++,pt[t+1][i]=pt[t][i];
	}
	rep(i,lv,lev[v]+1) {
		Z* h=tdep[rt[v][i]];
		auto p=h+pp[i];
		p->fi--; pt[t][i]=pp[i];
	}
	lv=0;
	rep(i,0,lev[v]+1) pp[i]=pb[t+1][i];
	rep(i,0,lev[u]) {
		Z* h=bdep[brh[u][i]][i];
		auto p=h+pb[t][i];
		if (pb[t][i]!=sb[brh[u][i]][i]-1&&(p+1)->fi==t+1) { p->se.fi-=dep[u][i]-dep[v][i]; lv=i+1; }
		else p->fi++,pb[t+1][i]=pb[t][i];
	}
	rep(i,lv,lev[v]) {
		Z* h=bdep[brh[v][i]][i];
		auto p=h+pp[i];
		p->fi--; pb[t][i]=pp[i];
	}
}
ll query(int u,int t) {
	ll ret=0;
	rep(i,0,lev[u]+1) {
		Z* h=tdep[rt[u][i]];
		auto p=lower_bound(h,h+st[rt[u][i]],mp(t,mp(-1ll,-1)));
		pair<ll,int> r=mp(0,0);
		if (p!=h) --p,r=p->se; 
		ret+=r.fi+r.se*dep[u][i];
	}
	rep(i,0,lev[u]) {
		Z* h=bdep[brh[u][i]][i];
		auto p=lower_bound(h,h+sb[brh[u][i]][i],mp(t,mp(-1ll,-1)));
		pair<ll,int> r=mp(0,0);
		if (p!=h) --p,r=p->se; 
		ret-=r.fi+r.se*dep[u][i];
	}
	return ret;
}
int l,r,c,Q,a[N],ty;

int main() {
	read(n); read(Q);
	rep(i,1,n+1) read(a[i]);
	rep(i,1,n) {
		read(u); read(v); read(w);
		e[u].pb(mp(v,w)); e[v].pb(mp(u,w));
	}
	gao(1,0);
	rep(i,1,n+1) build(a[i],i);
	ll preans=0;
	rep(i,0,Q) {
		read(ty);
		if (ty==1) {
			read(l); read(r); read(c);
			int key=preans&((1<<30)-1);
			l^=key; r^=key; c^=key;
			preans=query(c,r+1)-query(c,l);
			println(preans);
		} else {
			read(l);
			int key=preans&((1<<30)-1);
			l^=key;
			modify(a[l],a[l+1],l);
			swap(a[l],a[l+1]);
		}
	}
}