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

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int deg[MAXN];
int col[MAXN];
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d",&n); REP(i,n) ghead[i]=-1,deg[i]=0,col[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b; ++deg[a];
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a; ++deg[b];
	}

	int ret=0; REP(i,n) ret=max(deg[i]+1,ret);
	qhead=qtail=0; q[qhead++]=0; col[0]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		int have=-1; for(int x=ghead[at];x!=-1;x=gnxt[x]) if(col[gto[x]]!=-1) { assert(have==-1); have=col[gto[x]]; }
		int nxt=0; for(int x=ghead[at];x!=-1;x=gnxt[x]) if(col[gto[x]]==-1) { while(nxt==col[at]||nxt==have) ++nxt; col[gto[x]]=nxt++; q[qhead++]=gto[x]; }
	}
	printf("%d\n",ret);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",col[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}