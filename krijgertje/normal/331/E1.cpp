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


void run(int casenr) {
	memset(e,-1,sizeof(e)); nv=0;
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
			if(re[at][to]==-1) { ok=false; break; }
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
		printf("%d\n",plen);
		REP(j,plen) { if(j!=0) printf(" "); printf("%d",p[j]+1); } puts("");
		return;
	}
	printf("0\n");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}