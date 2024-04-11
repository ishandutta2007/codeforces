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

const int MAXN=1000000;
const int MAXM=1000000;

int n,m;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],deg[MAXN];
int totloop,nloop[MAXN],totdeg;

bool been[MAXN];
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=-1,deg[i]=0,nloop[i]=0; totloop=totdeg=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b; if(a==b) { ++nloop[a],++totloop; continue; } else ++totdeg;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++deg[a];
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++deg[b];
	}

	REP(i,n) been[i]=false; qhead=qtail=0; REP(i,n) if(deg[i]+nloop[i]>0) { been[i]=true,q[qhead++]=i; break; }
	while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(been[to]) continue; been[to]=true,q[qhead++]=to; } }
	REP(i,n) if(deg[i]+nloop[i]>0&&!been[i]) { printf("0\n"); return; }

	ll ret=0;
	ret+=(ll)totloop*(totloop-1)/2;
	ret+=(ll)totdeg*totloop;
	REP(i,n) {
		ret+=(ll)deg[i]*(deg[i]-1)/2;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}