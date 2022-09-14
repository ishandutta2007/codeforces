#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n,m;
int e[50][50];
int re[50][50];

int efrom[1225];
int eto[1225];
int ecntv[1225];
int efirstv[1225];
int elastv[1225];
int eself[1225];
int nv;
int vval[100000];
int vnext[100000];
int vprev[100000];

int qh,qt;
int q[100];

int p[101];

int ntrans;
int firsttrans[100]; // 2*node+0/1 (0=need current node,1=have current node)
int nexttrans[122500];
int translen[122500];
int transto[122500];

const int MOD=1000000007;
int cntways[102][100][100];

void run(int casenr) {
	memset(e,-1,sizeof(e)); nv=0; ntrans=0; memset(firsttrans,-1,sizeof(firsttrans));
	scanf("%d%d",&n,&m);
	REP(i,m) {
		scanf("%d%d%d",&efrom[i],&eto[i],&ecntv[i]); efrom[i]--; eto[i]--;
		e[efrom[i]][eto[i]]=i; re[eto[i]][efrom[i]]=i;
		efirstv[i]=elastv[i]=-1;
		REP(j,ecntv[i]) {
			scanf("%d",&vval[nv]); --vval[nv];
			if(j==0) {
				efirstv[i]=elastv[i]=nv; vnext[nv]=vprev[nv]=-1;
			} else {
				vprev[nv]=elastv[i]; vnext[nv]=-1;
				vnext[vprev[nv]]=nv; elastv[i]=nv;
			}
			++nv;
		}
	}
//	REP(i,m) { printf("%d:",ecntv[i]); for(int j=efirstv[i];j!=-1;j=vnext[j]) printf(" %d",vval[j]); puts(""); }
//	REP(i,m) { printf("%d:",ecntv[i]); for(int j=elastv[i];j!=-1;j=vprev[j]) printf(" %d",vval[j]); puts(""); }

	REP(i,m) { eself[i]=-1; for(int j=efirstv[i];j!=-1;j=vnext[j]) if(vval[j]==efrom[i]&&vnext[j]!=-1&&vval[vnext[j]]==eto[i]) { eself[i]=j; break; } }
	REP(i,m) if(eself[i]!=-1) {
//		printf("eself %d = %d -> %d\n",i,eself[i],vval[eself[i]]);
		bool ok=true; int plen=2; int at;
		//before
		qh=qt=0;
		for(int j=vprev[eself[i]];j!=-1;j=vprev[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
		at=efrom[i];
		while(qt<qh) {
			int to=q[qt++];
//			printf("rev %d->%d [%d]\n",to,at,e[to][at]);
			if(e[to][at]==-1||eself[e[to][at]]!=-1) { ok=false; break; }
			for(int j=elastv[e[to][at]];j!=-1;j=vprev[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
			at=to;
		}
		if(!ok) continue;
		int pstart=at;
		plen=0; for(int j=qh-1;j>=0;--j) p[plen++]=q[j]; p[plen++]=efrom[i]; p[plen++]=eto[i];
		//after
		qh=qt=0;
		for(int j=vnext[vnext[eself[i]]];j!=-1;j=vnext[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
		at=eto[i];
		while(qt<qh) {
			int to=q[qt++];
//			printf("for %d->%d [%d]\n",at,to,e[at][to]);
			if(e[at][to]==-1) { ok=false; break; }
			for(int j=efirstv[e[at][to]];j!=-1;j=vnext[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
			at=to;
		}
		int pend=at;
		if(!ok) continue;
		plen-=qh; for(int j=0;j<qh;++j) p[plen++]=q[j];
//		printf("%d\n",plen);
//		REP(j,plen) { if(j!=0) printf(" "); printf("%d",p[j]+1); } puts("");
//		return;
//		printf("found path from %d to %d of length %d\n",pstart,pend,plen);
		nexttrans[ntrans]=firsttrans[n+pstart];
		firsttrans[n+pstart]=ntrans;
		translen[ntrans]=plen;
		transto[ntrans]=pend;
		++ntrans;
	}
	REP(i,m) if(eself[i]==-1&&elastv[i]!=-1&&vval[elastv[i]]==efrom[i]) {
		bool ok=true; int plen=1; int at;
		qh=qt=0;
		for(int j=vprev[elastv[i]];j!=-1;j=vprev[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
		at=efrom[i];
		while(qt<qh) {
			int to=q[qt++];
			if(e[to][at]==-1||eself[e[to][at]]!=-1) { ok=false; break; }
			for(int j=elastv[e[to][at]];j!=-1;j=vprev[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
			at=to;
		}
		if(!ok) continue;
		int pstart=at,pend=eto[i];
//		printf("found prefix from %d to %d of length %d\n",pstart,pend,plen);
		nexttrans[ntrans]=firsttrans[n+pstart];
		firsttrans[n+pstart]=ntrans;
		translen[ntrans]=plen;
		transto[ntrans]=n+pend;
		++ntrans;
	}
	REP(i,m) if(efirstv[i]!=-1&&vval[efirstv[i]]==eto[i]) {
		bool ok=true; int plen=1; int at;
		qh=qt=0;
		for(int j=vnext[efirstv[i]];j!=-1;j=vnext[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
		at=eto[i];
		while(qt<qh) {
			int to=q[qt++];
			if(e[at][to]==-1) { ok=false; break; }
			for(int j=efirstv[e[at][to]];j!=-1;j=vnext[j]) if(plen<2*n+1) { q[qh++]=vval[j]; ++plen; } else ok=false;
			at=to;
		}
		if(!ok) continue;
		int pstart=efrom[i],pend=at;
//		printf("found suffix from %d to %d of length %d\n",pstart,pend,plen);
		nexttrans[ntrans]=firsttrans[pstart];
		firsttrans[pstart]=ntrans;
		translen[ntrans]=plen;
		transto[ntrans]=pend;
		++ntrans;
	}
	REP(i,m) if(ecntv[i]==0) {
		int pstart=efrom[i],pend=eto[i],plen=0;
//		printf("found empty edge from %d to %d\n",pstart,pend);
		nexttrans[ntrans]=firsttrans[pstart];
		firsttrans[pstart]=ntrans;
		translen[ntrans]=plen;
		transto[ntrans]=n+pend;
		++ntrans;
	}
//	REP(k,2*n) for(int x=firsttrans[k];x!=-1;x=nexttrans[x]) printf("%d%c -> %d -> %d%c\n",k%n,'B'-k/n,translen[x],transto[x]%n,'B'-transto[x]/n);

	memset(cntways,0,sizeof(cntways));
	REP(j,n) cntways[0][n+j][n+j]=1;
	REP(i,2*n+1) REP(j,2*n) REP(k,2*n) if(cntways[i][j][k]!=0) for(int x=firsttrans[k];x!=-1;x=nexttrans[x]) if(i+translen[x]<=2*n+1) {
		cntways[i+translen[x]][j][transto[x]]+=cntways[i][j][k];
		if(cntways[i+translen[x]][j][transto[x]]>=MOD) cntways[i+translen[x]][j][transto[x]]-=MOD;
	}
	FORE(i,2,2*n+1) {
		int cur=0;
		REP(j,n) REP(k,n) {
			cur+=cntways[i][n+j][k];
			if(cur>=MOD) cur-=MOD;
		}
//		printf("%d nodes = ",i);
		printf("%d\n",cur);
	}

//	printf("0\n");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}