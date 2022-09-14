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

const int MAXN=100;
const int MAXM=200;
const int GMAXN=2*MAXN+2;
const int GMAXM=MAXN+MAXN+MAXN*MAXN;

typedef struct G {
	int n,m;
	int fst[GMAXN];
	int nxt[2*GMAXM],to[2*GMAXM],cap[2*GMAXM];

	void init() { n=0,m=0; }
	int addnode() { int ret=n++; fst[ret]=-1; return ret; }
	int addedge(int a,int b,int c) {
		nxt[m]=fst[a]; fst[a]=m; to[m]=b; cap[m]=c; m++;
		nxt[m]=fst[b]; fst[b]=m; to[m]=a; cap[m]=0; return m++;
	}

	int flow[GMAXN],bck[GMAXN];
	int q[GMAXN],qhead,qtail;

	int mf(int s,int t) {
		int ret=0;
		while(true) {
			REP(i,n) flow[i]=0,bck[i]=-1; qhead=qtail=0;
			flow[s]=INT_MAX; bck[s]=-2; q[qhead++]=s;
			while(qtail<qhead) {
				int at=q[qtail++];
				for(int x=fst[at];x!=-1;x=nxt[x]) {
					if(flow[to[x]]>0||cap[x]==0) continue;
					flow[to[x]]=min(cap[x],flow[at]); bck[to[x]]=x^1; q[qhead++]=to[x];
				}
			}
			if(flow[t]==0) break;
			ret+=flow[t];
			for(int x=t;x!=s;x=to[bck[x]]) {
				cap[bck[x]]+=flow[t];
				cap[bck[x]^1]-=flow[t];
			}
		}
		return ret;
	}

} G;

int n,m;
int a[MAXN],b[MAXN];
int fst[MAXN];
int nxt[2*MAXM],to[2*MAXM];

int s,lft[MAXN],rgt[MAXN],t;
int e[MAXN][MAXN];
G g;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int p,q; scanf("%d%d",&p,&q); --p,--q;
		nxt[2*i+0]=fst[p]; fst[p]=2*i+0; to[2*i+0]=q;
		nxt[2*i+1]=fst[q]; fst[q]=2*i+1; to[2*i+1]=p;
	}

	g.init();
	s=g.addnode(); REP(i,n) { lft[i]=g.addnode(); rgt[i]=g.addnode(); } t=g.addnode();
	REP(i,n) g.addedge(s,lft[i],a[i]);
	REP(i,n) REP(j,n) e[i][j]=-1;
	REP(i,n) e[i][i]=g.addedge(lft[i],rgt[i],max(a[i],b[i]));
	REP(i,n) for(int x=fst[i];x!=-1;x=nxt[x]) e[i][to[x]]=g.addedge(lft[i],rgt[to[x]],max(a[i],b[to[x]]));
	REP(i,n) g.addedge(rgt[i],t,b[i]);

	int asum=0; REP(i,n) asum+=a[i];
	int bsum=0; REP(i,n) bsum+=b[i];
	if(asum!=bsum||g.mf(s,t)!=asum) { printf("NO\n"); return; }

	printf("YES\n");
	REP(i,n) { REP(j,n) { if(j!=0) printf(" "); printf("%d",e[i][j]==-1?0:g.cap[e[i][j]]); } puts(""); }
	
}

int main() {
	run();
	return 0;
}