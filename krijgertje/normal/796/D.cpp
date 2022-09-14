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
#include <random>
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

const int MAXN=300000;
const int MAXM=MAXN-1;

int n,npol,mxdst;
bool pol[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int d[MAXN],use[MAXN];
int q[MAXN],qhead,qtail;
bool used[MAXM];

int ret[MAXM],nret;

void run() {
	scanf("%d%d%d",&n,&npol,&mxdst);
	REP(i,n) pol[i]=false;
	REP(i,npol) { int x; scanf("%d",&x); --x; pol[x]=true; }
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	qhead=qtail=0; REP(i,n) d[i]=INT_MAX;
	REP(at,n) if(pol[at]) { d[at]=0,use[at]=-1,q[qhead++]=at; }
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			if(d[to]!=INT_MAX) continue;
			d[to]=d[at]+1,use[to]=x>>1,q[qhead++]=to;
		}
	}
	REP(i,n-1) used[i]=false; REP(i,n) if(use[i]!=-1) used[use[i]]=true;
	nret=0; REP(i,n-1) if(!used[i]) ret[nret++]=i;
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}