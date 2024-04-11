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

const int MAXCLS=200000;
const int MAXVAR=200000;
const int MAXN=MAXCLS;
const int MAXM=MAXVAR;

int ncls,nvar;
int vcnt[MAXVAR];
int vcls[MAXVAR][2];
int vsgn[MAXVAR][2];

int ret[MAXVAR];
bool cok[MAXCLS];

int n,m;
int head[MAXN];
int nxt[2*MAXM],to[2*MAXM],idx[MAXM];

int qhead,qtail,q[MAXN];

int cback[MAXN];
int dfs(int at,int back) {
	cback[at]=back;
	for(int x=head[at];x!=-1;x=nxt[x]) if(x!=back&&!cok[to[x]]) {
		if(cback[to[x]]!=-2) { cback[to[x]]=x^1; return to[x]; }
		int ret=dfs(to[x],x^1); if(ret!=-1) return ret;
	}
	cback[at]=-2;
	return -1;
}

void processqueue() {
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=head[at];x!=-1;x=nxt[x]) if(!cok[to[x]]) {
			ret[idx[x>>1]]=x&1,cok[to[x]]=true,q[qhead++]=to[x];
		}
	}
}


void run() {
	scanf("%d%d",&ncls,&nvar);
	REP(i,ncls) {
		int ccnt; scanf("%d",&ccnt); cok[i]=false; cback[i]=-2;
		REP(j,ccnt) { int x; scanf("%d",&x); int val=abs(x)-1,sgn=x<0?0:+1; assert(vcnt[val]<=2); vcls[val][vcnt[val]]=i; vsgn[val][vcnt[val]]=sgn; ++vcnt[val]; }
	}

	n=ncls,m=0;
	REP(i,n) head[i]=-1;
	REP(i,nvar) {
		if(vcnt[i]==0) { ret[i]=0; continue; }
		if(vcnt[i]==1) { cok[vcls[i][0]]=true; ret[i]=vsgn[i][0]; continue; }
		if(vsgn[i][0]==vsgn[i][1]) { cok[vcls[i][0]]=cok[vcls[i][1]]=true; ret[i]=vsgn[i][0]; continue; }
		if(vsgn[i][0]==0) swap(vsgn[i][0],vsgn[i][1]),swap(vcls[i][0],vcls[i][1]);
		int a=vcls[i][0],b=vcls[i][1];
		ret[i]=-1; idx[m>>1]=i;
		nxt[m]=head[a]; head[a]=m; to[m]=b; ++m;
		nxt[m]=head[b]; head[b]=m; to[m]=a; ++m;
	}

	//REP(i,nvar) printf("%d ",ret[i]); puts("");
	//REP(i,ncls) printf("%c",cok[i]?'V':'-'); puts("");
	//REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d->%d",x&1,to[x]); puts(""); }

	qhead=qtail=0;
	REP(i,n) if(cok[i]) q[qhead++]=i;
	processqueue();

	REP(i,n) if(!cok[i]) {
		int cyc=dfs(i,-1);
		if(cyc==-1) { printf("NO\n"); return; }
		for(int x=cback[cyc];!cok[to[x]];x=cback[to[x]]) {
			ret[idx[x>>1]]=x&1,cok[to[x]]=true,q[qhead++]=to[x];
		}
		processqueue();
		assert(cok[i]);
	}
	REP(i,nvar) if(ret[i]==-1) ret[i]=0;

	//REP(i,nvar) printf("%d ",ret[i]); puts("");
	//REP(i,ncls) printf("%c",cok[i]?'V':'-'); puts("");
	//REP(i,n) if(!cok[i]) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d->%d",x&1,to[x]); puts(""); }

	printf("YES\n");
	REP(i,nvar) printf("%d",ret[i]); puts("");
}

int main() {
	run();
	return 0;
}