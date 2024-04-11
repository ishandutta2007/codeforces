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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXQ=100000;

int n,m,nq;
int q[MAXQ][3];

int p[MAXN];
int fst[MAXN];
int nxt[MAXM],to[MAXM];

int l[MAXN],r[MAXN],nid;
void dfs(int at) {
	l[at]=r[at]=nid++;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		dfs(to[x]);
		r[at]=r[to[x]];
	}
}
bool isanc(int x,int y) { return l[x]<=l[y]&&r[y]<=r[x]; }

int grp[MAXN],rnk[MAXN];
int np,fstq[MAXQ],nxtq[MAXQ],ret[MAXQ];
int find(int x) { if(grp[x]==x) return x; return grp[x]=find(grp[x]); }
void unite(int x,int y) {
	x=find(x),y=find(y); if(x==y) return;
	if(rnk[x]<rnk[y]) swap(x,y);
	grp[y]=x; if(rnk[x]==rnk[y]) ++rnk[x];
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(qi,nq) { scanf("%d%d",&q[qi][0],&q[qi][1]); if(q[qi][0]!=2) scanf("%d",&q[qi][2]); }

	REP(i,n) p[i]=-1,fst[i]=-1,l[i]=-1,r[i]=-1; m=0;
	REP(qi,nq) if(q[qi][0]==1) { int x=q[qi][1]-1,y=q[qi][2]-1; assert(p[x]==-1); p[x]=y; nxt[m]=fst[y]; fst[y]=m; to[m]=x; ++m; }
	nid=0; REP(i,n) if(p[i]==-1) dfs(i);
	//REP(i,n) { printf("%d: %d, %d..%d ->",i,p[i],l[i],r[i]); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	REP(qi,nq) fstq[qi]=nxtq[qi]=ret[qi]=-1;
	REP(qi,nq) if(q[qi][0]==3) { int x=q[qi][1]-1,idx=q[qi][2]-1; nxtq[qi]=fstq[idx]; fstq[idx]=qi; }

	REP(i,n) grp[i]=i,rnk[i]=0; np=0;
	REP(qi,nq) {
		if(q[qi][0]==1) {
			int x=q[qi][1]-1,y=q[qi][2]-1;
			unite(x,y);
		}
		if(q[qi][0]==2) {
			int x=q[qi][1]-1;
			for(int qi2=fstq[np];qi2!=-1;qi2=nxtq[qi2]) {
				int x2=q[qi2][1]-1;
				ret[qi2]=isanc(x2,x)&&find(x)==find(x2)?1:0;
			}
			++np;
		}
	}
	REP(qi,nq) if(q[qi][0]==3) printf("%s\n",ret[qi]?"YES":"NO");
}

int main() {
	run();
	return 0;
}