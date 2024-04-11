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

int n,m;
int head[MAXN],nxt[2*MAXM],to[2*MAXM]; char c[MAXM];

int type[MAXN];
int q[MAXN],qhead,qtail;

int cur[MAXN],ncur;
int ret[MAXN],nret;

void calc(char want) {
	//printf("making %c\n",want);
	REP(i,n) type[i]=-1; ncur=0;
	REP(i,n) if(type[i]==-1) {
		qhead=qtail=0; type[i]=0,q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++]; //printf("%d=%d\n",at,type[at]);
			for(int x=head[at];x!=-1;x=nxt[x]) {
				int ntype=type[at]; if(c[x>>1]!=want) ntype=1-ntype;
				if(type[to[x]]==-1) type[to[x]]=ntype,q[qhead++]=to[x]; else if(type[to[x]]!=ntype) return;
			}
		}
		int n0=0,n1=0; REP(j,qhead) if(type[q[j]]==0) ++n0; else if(type[q[j]]==1) ++n1; int ctype=n0<n1?0:1;
		REP(j,qhead) if(type[q[j]]==ctype) cur[ncur++]=q[j];
	}
	if(ncur<nret) { nret=ncur; REP(i,ncur) ret[i]=cur[i]; }
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) head[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d %c",&a,&b,&c[i]); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}

	nret=INT_MAX;
	calc('R');
	calc('B');
	if(nret==INT_MAX) printf("-1\n"); else { printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts(""); }
}

int main() {
	run();
	return 0;
}