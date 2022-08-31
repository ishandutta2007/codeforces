#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,m;
struct edge{
	int v,next;
}e[11111];int etot=0;int g[5555];
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
	e[etot].v=u;e[etot].next=g[v];g[v]=etot++;
}
int k;
struct node{
	int pos,cnt,pri;
	void read(){
		gn(pos);gn(cnt);gn(pri);
	}
}a[5555];
int cmppri(const node&a,const node&b){
	return a.pri<b.pri;
}

struct queq{
	int pos,cnt,mon,id;
	void read(){
		gn(pos);gn(cnt);gn(mon);
	}
}que[1555];

vector<int> qpos[5555];


int q;int ans[5555];
int dis[5555];
int ord[5555];
int cmpdis(int i,int j){
	return dis[i]<dis[j];
}

void bfs(int rt){
	static int qu[5555];
	static int vis[5555];
	int p=0,q=0;
	rep(i,1,n+1)vis[i]=0,dis[i]=inf;
	qu[q++]=rt;
	vis[rt]=1;
	dis[rt]=0;
	while(p!=q){
		int u=qu[p++];
		forg(i,g[u])if(!vis[e[i].v]){
			vis[e[i].v]=1;
			qu[q++]=e[i].v;
			dis[e[i].v]=dis[u]+1;
		}
	}
	rep(i,1,n+1)ord[i]=i;
	sort(ord+1,ord+1+n,cmpdis);
}

int ask(int id){
	int cnt=que[id].cnt,mon=que[id].mon;
	int lef=0,rig=n;
	while(lef<=rig){
		int mid=lef+rig>>1;

		ll cursu=0;
		int curcnt=cnt;

		rep(i,1,k+1)if(dis[a[i].pos]<=mid){
			int del=min(curcnt,a[i].cnt);
			cursu+=1ll*del*a[i].pri;
			if(cursu>mon)break;
			curcnt-=del;
			if(curcnt==0)break;
		}
		if(cursu<=mon && curcnt==0){
			rig=mid-1;
		}
		else lef=mid+1;
	}
	return lef==n+1?-1:lef;
}
	
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	fil(g,-1);
	rep(i,1,m+1){
		int u,v;gn(u);gn(v);
		ae(u,v);
	}
	gn(k);
	rep(i,1,k+1){
		a[i].read();
	}
	sort(a+1,a+1+k,cmppri);
	gn(q);
	rep(i,1,q+1){
		que[i].read();
		que[i].id=i;
		qpos[que[i].pos].pb(i);
	}

	rep(u,1,n+1)if(!qpos[u].empty()){
		bfs(u);
		rep(i,0,siz(qpos[u])){
			int j=qpos[u][i];
			ans[j]=ask(j);
		}
	}
	rep(i,1,q+1)printf("%d\n",ans[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}