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
const int MAXM=MAXN-1;
const int MAX2=50;
const int MAXP=7;
const int MAXPVAL=(MAXN+MAX2)*MAXP;
const int MAXX=2000000;

int dv[MAXX+1];
void precalc() {
	REPE(i,MAXX) dv[i]=-1;
	FORE(i,2,MAXX) if(dv[i]==-1) for(int j=i;j<=MAXX;j+=i) dv[j]=i;
}

int n,nq;
int fst[MAXN],nxt[2*MAXM],to[2*MAXM];

int val[MAXN];
int pstart[MAXN],pcnt[MAXN];
int pval[MAXPVAL],npval;
int pnode[MAXPVAL];

void calcp(int id) {
	pstart[id]=npval; pcnt[id]=0;
	int x=val[id];
	while(x!=1) {
		int cur=dv[x];
		pnode[npval]=id; pval[npval]=cur; ++npval,++pcnt[id];
		while(x%cur==0) x/=cur;
	}
}

int d[MAXN];
int ret[MAXN];
int pfst[MAXX+1],pnxt[MAXPVAL];
void dfs(int at,int par) {
	ret[at]=-1;
	REP(i,pcnt[at]) {
		int x=pval[pstart[at]+i];
		if(pfst[x]!=-1&&(ret[at]==-1||d[pnode[pfst[x]]]>d[ret[at]])) ret[at]=pnode[pfst[x]];
		pnxt[pstart[at]+i]=pfst[x]; pfst[x]=pstart[at]+i;
	}
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		d[to[x]]=d[at]+1;
		dfs(to[x],at);
	}
	REP(i,pcnt[at]) {
		int x=pval[pstart[at]+i];
		assert(pfst[x]==pstart[at]+i);
		pfst[x]=pnxt[pstart[at]+i]; pnxt[pstart[at]+i]=-1;
	}
}
void rundfs() {
	REPE(i,MAXX) pfst[i]=-1;
	REP(i,npval) pnxt[i]=-1;
	d[0]=0; dfs(0,-1);
}

void run() {
	precalc();
	scanf("%d%d",&n,&nq);
	npval=0; REP(i,n) { scanf("%d",&val[i]); calcp(i); }
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	
	rundfs();
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int a; scanf("%d",&a); --a;
			printf("%d\n",ret[a]==-1?-1:ret[a]+1);
		}
		if(type==2) {
			int a,nval; scanf("%d%d",&a,&nval); --a;
			val[a]=nval; calcp(a);
			rundfs();
		}
	}

}

int main() {
	run();
	return 0;
}