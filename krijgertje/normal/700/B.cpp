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

const int MAXN=200000;
const int MAXM=MAXN-1;

int n,nz;
bool z[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int q[MAXN],qhead,qtail;
int par[MAXN],sz[MAXN];


void run() {
	scanf("%d%d",&n,&nz); nz*=2;
	REP(i,n) z[i]=false; REP(i,nz) { int x; scanf("%d",&x); --x; z[x]=true; }
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}

	REP(i,n) par[i]=-1; qhead=qtail=0; q[qhead++]=0;
	while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gto[x]!=par[at]) { par[gto[x]]=at; q[qhead++]=gto[x]; } }
	REP(i,n) sz[i]=z[i]?1:0; for(int i=n-1;i>=1;--i) { int at=q[i]; sz[par[at]]+=sz[at]; }

	ll ret=0;
	REP(at,n) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gto[x]!=par[at]) {
		int a=sz[gto[x]],b=nz-a; ret+=min(a,b);
		//printf("%d-%d: %d vs %d\n",at,gto[x],a,b);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}