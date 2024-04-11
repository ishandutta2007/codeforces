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

const int MAXN=300000;

int n,nq;
int par[MAXN];
int chead[MAXN],cnxt[MAXN];
int sz[MAXN],center[MAXN];
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) chead[i]=-1,cnxt[i]=-1;
	REP(i,n) cnxt[i]=chead[par[i]],chead[par[i]]=i;
	qhead=qtail=0; q[qhead++]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=chead[at];x!=-1;x=cnxt[x]) q[qhead++]=x;
	}
	assert(qhead==n);
	REP(i,n) sz[i]=1;
	for(int i=n-1;i>=0;--i) sz[par[q[i]]]+=sz[q[i]];
	for(int i=n-1;i>=0;--i) {
		int at=q[i];
		center[at]=at;
		for(int x=chead[at];x!=-1;x=cnxt[x]) if(2*sz[x]>sz[at]) {
			center[at]=center[x];
			while(2*sz[center[at]]<sz[at]) center[at]=par[center[at]];
		}
	}
	//REP(i,n) printf("%d: par=%d, sz=%d, center=%d\n",q[i]+1,par[q[i]]+1,sz[q[i]],center[q[i]]+1);
	REP(qi,nq) {
		int x; scanf("%d",&x); --x;
		printf("%d\n",center[x]+1);
	}
}

int main() {
	run();
	return 0;
}