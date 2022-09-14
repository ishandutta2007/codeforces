#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=100000;
const int GMAXN=4+2*MAXN;
const int GMAXM=2*(5*MAXN+2);

typedef struct G {
	int n,m,s,t;
	int ghead[GMAXN],gnxt[GMAXM],gto[GMAXM];
	int lcap[GMAXM],cap[GMAXM],flow[GMAXM],cur[GMAXN];
	int d[GMAXN];
	int q[GMAXN],qhead,qtail;
	void init(int _n) { n=_n; REP(i,n) ghead[i]=-1; }
	int addedge(int a,int b,int l,int h) {
		gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,lcap[m]=l,cap[m]=h-l,flow[m]=0,++m;
		gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,lcap[m]=0,cap[m]=0,flow[m]=0,++m;
		return m-2;
	}
	int lmaxflow(int _s,int _t) {
		int nn=n,mm=m,ss=n++,tt=n++,want=0; ghead[ss]=ghead[tt]=-1;
		REP(at,nn) {
			int sum=0; for(int x=ghead[at];x!=-1;x=gnxt[x]) sum+=lcap[x]-lcap[x^1];
			if(sum>0) addedge(at,tt,0,sum),want+=sum;
			if(sum<0) addedge(ss,at,0,-sum);
		}
		int retid=addedge(_t,_s,0,INT_MAX);
		int now=maxflow(ss,tt);
		if(now!=want) return -1;
		int ret=flow[retid];
		n=nn,m=mm; REP(i,n) while(ghead[i]!=-1&&ghead[i]>=m) ghead[i]=gnxt[ghead[i]];
		ret+=maxflow(_s,_t);
		return ret;
	}
	int maxflow(int _s,int _t) {
		s=_s,t=_t;
		//REP(at,n) { printf("%d: ",at); for(int x=ghead[at];x!=-1;x=gnxt[x]) printf(" %d[%d]",gto[x],cap[x]); puts(""); } puts("");
		int ret=0;
		while(true) {
			bfs();
			//printf("\td[t]=%d\n",d[t]);
			if(d[t]==INT_MAX) return ret;
			REP(i,n) cur[i]=ghead[i];
			int now=dfs(s,INT_MAX);
			//printf("\tnow=%d\n",now);
			ret+=now;
		}
	}
	void bfs() {
		REP(i,n) d[i]=INT_MAX; qhead=qtail=0; d[s]=0,q[qhead++]=s;
		while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) if(cap[x]>flow[x]) { int to=gto[x]; if(d[to]==INT_MAX) d[to]=d[at]+1,q[qhead++]=to; } }
	}
	int dfs(int at,int left,int dd=0) {
		//printf("\t\t"); REP(i,dd) printf(" "); printf("dfs(%d,%d)\n",at,left);
		if(at==t) return left;
		int ret=0;
		for(int x=cur[at];x!=-1;x=cur[at]=gnxt[cur[at]]) if(cap[x]>flow[x]&&d[at]+1==d[gto[x]]) {
			int now=dfs(gto[x],min(left,cap[x]-flow[x]),dd+1);
			flow[x]+=now; flow[x^1]-=now; left-=now; ret+=now; if(left==0) return ret;
		}
		return ret;
	}
} G;

int n,m;
int r,b;
int x[MAXN],y[MAXN],id[MAXN];
int qxy[MAXM],qidx[MAXM],qmxdiff[MAXM];
int xx[MAXN],nxx;
int yy[MAXN],nyy;
int degx[MAXN],degy[MAXN],lx[MAXN],hx[MAXN],ly[MAXN],hy[MAXN];

G g;

void input() {
	scanf("%d%d%d%d",&n,&m,&r,&b); 
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,m) scanf("%d%d%d",&qxy[i],&qidx[i],&qmxdiff[i]);
}

void solve() {
	char rc='r',bc='b'; if(r>b) swap(r,b),swap(rc,bc);
	nxx=0; REP(i,n) xx[nxx++]=x[i]; sort(xx,xx+nxx); nxx=unique(xx,xx+nxx)-xx; REP(i,n) x[i]=lower_bound(xx,xx+nxx,x[i])-xx;
	nyy=0; REP(i,n) yy[nyy++]=y[i]; sort(yy,yy+nyy); nyy=unique(yy,yy+nyy)-yy; REP(i,n) y[i]=lower_bound(yy,yy+nyy,y[i])-yy;
	REP(i,nxx) degx[i]=0; REP(i,n) ++degx[x[i]]; REP(i,nxx) lx[i]=0,hx[i]=degx[i];
	REP(i,nyy) degy[i]=0; REP(i,n) ++degy[y[i]]; REP(i,nyy) ly[i]=0,hy[i]=degy[i];
	REP(i,m) {
		int xy=qxy[i],idx=qidx[i],mxdiff=qmxdiff[i];
		if(xy==1) {
			int cx=lower_bound(xx,xx+nxx,idx)-xx; if(cx>=nxx||xx[cx]!=idx||mxdiff>=degx[cx]) continue;
			// |nr-nl|<=mxdiff -> (degx[cx]-mxdiff)/2<=nr<=(degx[cx]+mxdiff)/2
			int cl=(degx[cx]-mxdiff+1)/2,cr=(degx[cx]+mxdiff)/2;
			if(cl>lx[cx]) lx[cx]=cl; if(cr<hx[cx]) hx[cx]=cr;
		}
		if(xy==2) {
			int cy=lower_bound(yy,yy+nyy,idx)-yy; if(cy>=nyy||yy[cy]!=idx||mxdiff>=degy[cy]) continue;
			// |nr-nl|<=mxdiff -> (degy[cy]-mxdiff)/2<=nr<=(degy[cy]+mxdiff)/2
			int cl=(degy[cy]-mxdiff+1)/2,cr=(degy[cy]+mxdiff)/2;
			if(cl>ly[cy]) ly[cy]=cl; if(cr<hy[cy]) hy[cy]=cr;
		}
	}
	//printf("xx ="); REP(i,nxx) printf(" %d",xx[i]); puts("");
	//printf("yy ="); REP(i,nyy) printf(" %d",yy[i]); puts("");
	//REP(i,n) printf("%d-%d\n",x[i],y[i]);
	//REP(i,nxx) printf("%d..%d ",lx[i],hx[i]); puts("");
	//REP(i,nyy) printf("%d..%d ",ly[i],hy[i]); puts("");
	REP(i,nxx) if(lx[i]>hx[i]) { printf("-1\n"); return; }
	REP(i,nyy) if(ly[i]>hy[i]) { printf("-1\n"); return; }

	int s=nxx+nyy,t=s+1;
	g.init(nxx+nyy+2);
	REP(i,nxx) g.addedge(s,i,lx[i],hx[i]);
	REP(i,nyy) g.addedge(nxx+i,t,ly[i],hy[i]);
	REP(i,n) id[i]=g.addedge(x[i],nxx+y[i],0,1);

	int ret=g.lmaxflow(s,t);
	if(ret==-1) { printf("-1\n"); return; }
	printf("%lld\n",(ll)r*ret+(ll)b*(n-ret));
	REP(i,n) printf("%c",g.flow[id[i]]>0?rc:bc); puts("");
}

void run() {
	input();
	solve();
}

void test() {
	n=MAXN,m=MAXM,r=1,b=2;
	REP(i,n) x[i]=rand()%10000,y[i]=rand()%10000;
	REP(i,m) qxy[i]=rand()%2+1,qidx[i]=rand()%10000,qmxdiff[i]=1+rand()%10;
	solve();

}

int main() {
	run();
	//test();
	return 0;
}