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
#include <chrono>
#include <random>
#include <bitset>
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
ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=100000;
const int MAXDIFF=200000;
const int MAXG=100;

int n,forbidden;
int a[MAXN],b[MAXN],c[MAXN];

int pmn[MAXDIFF+1];
int g[MAXDIFF+1];
bitset<MAXDIFF+1> moves;
bitset<MAXDIFF+1> reachable[MAXG+1];



bool solve() {
	int mxdiff=0; REP(i,n) mxdiff=max(mxdiff,max(b[i]-a[i]-1,c[i]-b[i]-1));
	moves.reset(); REPE(i,MAXG) reachable[i].reset();
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,mxdiff) if(pmn[i]==-1) for(int j=i;j<=mxdiff;j+=i) if(pmn[j]==-1) pmn[j]=i;
	FORE(i,2,mxdiff) if(i!=forbidden&&(pmn[i]==i||pmn[i/pmn[i]]==i/pmn[i])) moves.set(i);
	REPE(i,mxdiff) {
		g[i]=0; while(g[i]<=MAXG&&reachable[g[i]][i]) ++g[i]; assert(g[i]<=MAXG);
		reachable[g[i]]|=moves<<i;
	}
	//int gmx=0; REPE(i,mxdiff) gmx=max(gmx,g[i]); printf("gmx=%d\n",gmx);
	//printf("g:"); REP(i,100) printf(" %d",g[i]); puts("");
	int ret=0; REP(i,n) { int x=b[i]-a[i]-1,y=c[i]-b[i]-1; ret^=g[x]^g[y]; } return ret!=0;
}

void run() {
	scanf("%d%d",&n,&forbidden);
	REP(i,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	bool firstwin=solve();
	printf("%s\n%s\n",firstwin?"Alice":"Bob",firstwin?"Bob":"Alice");
}

int main() {
	run();
	return 0;
}