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

const int MAXN=2000;
const int MAXM=2000;

int n1,n2,m;
vector<int> ladj[MAXN],radj[MAXN];

const int GMAXN=2*MAXN+2;
const int GMAXM=MAXM+2*MAXN;
struct G {
	int n,m;
	int ghead[GMAXN],gnxt[2*GMAXM],gto[2*GMAXM],gcap[2*GMAXM];
	void init(int _n) { n=_n; m=0; REP(i,n) ghead[i]=-1; }
	int addedge(int a,int b,int c) {
		int ret=m;
		gnxt[m]=ghead[a]; ghead[a]=m; gto[m]=b; gcap[m]=c; ++m;
		gnxt[m]=ghead[b]; ghead[b]=m; gto[m]=a; gcap[m]=0; ++m;
		return ret;
	}
	int back[MAXN],flow[MAXN],q[MAXN],qhead,qtail;
	int mf(int s,int t) {
		int ret=0;
		while(true) {
			REP(i,n) back[i]=-1,flow[i]=0; qhead=qtail=0;
			flow[s]=INT_MAX; q[qhead++]=s;
			while(qtail<qhead) {
				int at=q[qtail++];
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]!=0) {
					int to=gto[x]; if(flow[to]!=0) continue;
					flow[to]=min(flow[at],gcap[x]); back[to]=x^1; q[qhead++]=to;
				}
			}
			if(flow[t]==0) return ret; else ret+=flow[t];
			for(int x=t;x!=s;x=gto[back[x]]) {
				gcap[back[x]]+=flow[t];
				gcap[back[x]^1]-=flow[t];
			}
		}
	}

};

G g;
int e[MAXM][2];
int eid1[MAXN],eid2[MAXN],eid3[MAXM];

bool use[MAXM];
int cnt1[MAXN],cnt2[MAXN];

void run() {
	scanf("%d%d%d",&n1,&n2,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[i][0]=a,e[i][1]=b; ladj[a].PB(b); radj[b].PB(a); }
	
	int dmin=INT_MAX; REP(i,n1) dmin=min(dmin,SZ(ladj[i])); REP(i,n2) dmin=min(dmin,SZ(radj[i]));
	g.init(2+n1+n2);
	int s=n1+n2,t=n1+n2+1;
	REP(i,n1) eid1[i]=g.addedge(s,i,0);
	REP(i,n2) eid2[i]=g.addedge(n1+i,t,0);
	REP(i,m) eid3[i]=g.addedge(e[i][0],n1+e[i][1],1);
	FORE(k,0,dmin) {
		int extraflow=g.mf(s,t);
		//printf("extraflow=%d\n",extraflow);
		REP(i,m) use[i]=g.gcap[eid3[i]]==0;
		REP(i,n1) cnt1[i]=0; REP(i,n2) cnt2[i]=0; REP(i,m) if(use[i]) ++cnt1[e[i][0]],++cnt2[e[i][1]];
		REP(i,m) if(cnt1[e[i][0]]<k||cnt2[e[i][1]]<k) use[i]=true,cnt1[e[i][0]]++,cnt2[e[i][1]]++;
		int nuse=0; REP(i,m) if(use[i]) ++nuse;
		printf("%d",nuse); REP(i,m) if(use[i]) printf(" %d",i+1); puts("");
		REP(i,n1) ++g.gcap[eid1[i]];
		REP(i,n2) ++g.gcap[eid2[i]];
	}
}

int main() {
	run();
	return 0;
}