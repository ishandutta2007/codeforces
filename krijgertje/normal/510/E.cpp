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

const int MAXMFN=200+2;
const int MAXMFM=2*(100*100+200);

typedef struct MF {
	int n,m;

	int fst[MAXMFN];
	int nxt[MAXMFM];
	int to[MAXMFM];
	int cap[MAXMFM];

	bool been[MAXMFN];
	int back[MAXMFN];
	int q[MAXMFN],qhead,qtail;

	void init(int _n) {
		n=_n; m=0;
		REP(i,n) fst[i]=-1;
	}

	void addedge(int a,int b,int c) {
		nxt[m]=fst[a]; fst[a]=m; to[m]=b; cap[m]=c; ++m;
		nxt[m]=fst[b]; fst[b]=m; to[m]=a; cap[m]=0; ++m;
	}

	int calc(int s,int t) {
		int ret=0;
		while(true) {
			REP(i,n) been[i]=false;
			qhead=qtail=0; q[qhead++]=s; back[s]=-1; been[s]=true;
			while(qtail<qhead) {
				int at=q[qtail++];
				for(int x=fst[at];x!=-1;x=nxt[x]) if(!been[to[x]]&&cap[x]>0) {
					q[qhead++]=to[x]; back[to[x]]=x^1; been[to[x]]=true;
				}
			}
			if(!been[t]) return ret;
			++ret;
			for(int u=t;u!=s;u=to[back[u]]) {
				++cap[back[u]];
				--cap[back[u]^1];
			}
		}
	}
} MF;
MF mf;

const int MAXSUM=20000;
bool isp[MAXSUM+1];

int n;
int x[200];
bool done[200];

int nret;
int retfst[200];
int retnxt[200];
int retcnt[200];

void run() {
	REPE(i,MAXSUM) isp[i]=true; isp[0]=isp[1]=false;
	FORE(i,2,MAXSUM) if(isp[i]) { for(int j=i+i;j<=MAXSUM;j+=i) isp[j]=false; }

	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);

	mf.init(n+2);
	REP(i,n) if(x[i]%2==0) mf.addedge(n,i,2); else mf.addedge(i,n+1,2);
	REP(i,n) if(x[i]%2==0) REP(j,n) if(x[j]%2==1&&isp[x[i]+x[j]]) mf.addedge(i,j,1);

	int res=mf.calc(n,n+1);
	if(res!=n) { printf("Impossible\n"); return; }

	REP(i,n) done[i]=false; nret=0;
	REP(i,n) if(x[i]%2==0&&!done[i]) {
		int at=i; retcnt[nret]=0; retfst[nret]=-1;
		//	printf("%d\n",i);
		while(true) {
			//printf("\t%d\n",at);
			int to1=-1,to2=-2;
			for(int x=mf.fst[at];x!=-1;x=mf.nxt[x]) if(mf.to[x]!=n&&mf.cap[x]==0&&!done[mf.to[x]]) {
				for(int y=mf.fst[mf.to[x]];y!=-1;y=mf.nxt[y]) if(mf.to[y]!=n+1&&mf.cap[y]==1&&mf.to[y]!=at) {
					to1=mf.to[x]; to2=mf.to[y];
					break;
				}
				break;
			}
			assert(to1!=-1&&to2!=-1);
			done[to1]=done[to2]=true;
			retnxt[to1]=retfst[nret]; retfst[nret]=to1; ++retcnt[nret];
			retnxt[to2]=retfst[nret]; retfst[nret]=to2; ++retcnt[nret];
			if(to2==i) break;
			at=to2;
		}
		++nret;
	}
	printf("%d\n",nret);
	REP(i,nret) { printf("%d",retcnt[i]); for(int x=retfst[i];x!=-1;x=retnxt[x]) printf(" %d",x+1); puts(""); }
}

int main() {
	run();
	return 0;
}