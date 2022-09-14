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
int fst[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];
int deg[MAXN];

bool done[MAXN];
int q[MAXN],qhead,qtail;
int comp[MAXN],ncomp;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	
	int ret=0;
	REP(i,n) done[i]=false;
	REP(i,n) if(!done[i]) {
		qhead=qtail=0; q[qhead++]=i; done[i]=true;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=fst[at];x!=-1;x=nxt[x]) if(!done[to[x]]) { q[qhead++]=to[x]; done[to[x]]=true; }
		}
		ncomp=qhead; REP(j,ncomp) comp[j]=q[j];
		REP(j,ncomp) deg[comp[j]]=0;
		REP(j,ncomp) for(int x=fst[comp[j]];x!=-1;x=nxt[x]) if(x%2==0) ++deg[to[x]];
		//REP(j,ncomp) printf("%d: %d\n",comp[j],deg[comp[j]]);
		qhead=qtail=0; REP(j,ncomp) if(deg[comp[j]]==0) q[qhead++]=comp[j];
		while(qtail<qhead) {
			int at=q[qtail++];
//			printf("%d\n",at);
			for(int x=fst[at];x!=-1;x=nxt[x]) {
//				printf("%d->%d\n",at,to[x]);
				if(x%2==0) if(--deg[to[x]]==0) q[qhead++]=to[x];
			}
		}
		//REP(j,ncomp) printf("%d: %d\n",comp[j],deg[comp[j]]);
		ret+=qhead==ncomp?ncomp-1:ncomp;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}