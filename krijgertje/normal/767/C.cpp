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


int n;
int par[MAXN],val[MAXN];
int root,chead[MAXN],cnxt[MAXN],deg[MAXN];

int q[MAXN],qhead,qtail;
int rem[MAXN];

int sum[MAXN];
int a[MAXN][2],na[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&par[i],&val[i]),--par[i];
	REP(i,n) chead[i]=-1,deg[i]=0; REP(i,n) if(par[i]==-1) root=i; else cnxt[i]=chead[par[i]],chead[par[i]]=i,++deg[par[i]];

	REP(i,n) rem[i]=deg[i]; qhead=qtail=0; REP(i,n) if(rem[i]==0) q[qhead++]=i;
	REP(i,n) sum[i]=val[i];
	while(qtail<qhead) {
		int at=q[qtail++]; if(par[at]==-1) continue;
		sum[par[at]]+=sum[at];
		if(--rem[par[at]]==0) q[qhead++]=par[at];
	}
	//REP(i,n) printf("%d: %d\n",i+1,sum[i]);
	if(sum[root]%3!=0) { printf("-1\n"); return; }
	int want=sum[root]/3;

	REP(i,n) na[i]=0;
	REP(i,n) {
		int at=q[i];
		if(par[at]!=-1&&sum[at]==2*want&&na[at]>=1) { printf("%d %d\n",at+1,a[at][0]+1); return; }
		if(na[at]>=2) { printf("%d %d\n",a[at][0]+1,a[at][1]+1); return; }
		if(par[at]!=-1&&na[par[at]]<2&&(sum[at]==want||na[at]>=1)) a[par[at]][na[par[at]]++]=sum[at]==want?at:a[at][0];
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}