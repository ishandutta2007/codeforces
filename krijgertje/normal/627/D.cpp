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

int n,m,need;
int val[MAXN];
int deg[MAXN],head[MAXN],nxt[2*MAXM],to[2*MAXM];
int all[MAXN],nall;


int rem[MAXN],errcnt[MAXN],sum[MAXN],mxv[MAXN][2],mxi[MAXN];
bool done[2*MAXM],allok[2*MAXM]; int f[2*MAXM];
int q[2*MAXM],qhead,qtail;

int calc(int mn) {
	// we can process an edge if rem[to[x]]==0 || rem[to[x]]==1&&!done[x^1]
	REP(i,n) rem[i]=deg[i],errcnt[i]=0,sum[i]=0,mxv[i][0]=0,mxv[i][1]=0,mxi[i]=-1;
	REP(x,m) done[x]=false;
	qhead=qtail=0; REP(x,m) if(rem[to[x]]==0||rem[to[x]]==1&&!done[x^1]) q[qhead++]=x;
	while(qtail<qhead) {
		int x=q[qtail++],a=to[x^1],b=to[x]; //printf("processing %d->%d\n",a,b);
		allok[x]=val[b]<mn?false:rem[b]==0?errcnt[b]==(allok[x^1]?0:1):errcnt[b]==0;
		f[x]=val[b]<mn?0:rem[b]==0?1+sum[b]-(allok[x^1]?f[x^1]:0)+(mxi[b]!=(x^1)?mxv[b][0]:mxv[b][1]):1+sum[b]+mxv[b][0];
		done[x]=true;

		--rem[a];
		if(rem[a]==0) for(int y=head[a];y!=-1;y=nxt[y]) if(y!=x) q[qhead++]=y^1;
		if(rem[a]==1) for(int y=head[a];y!=-1;y=nxt[y]) if(!done[y]) q[qhead++]=y^1;
		if(allok[x]) sum[a]+=f[x]; else { ++errcnt[a]; if(f[x]>mxv[a][0]) mxv[a][1]=mxv[a][0],mxv[a][0]=f[x],mxi[a]=x; else if(f[x]>mxv[a][1]) mxv[a][1]=f[x]; }
	}
	REP(i,n) assert(rem[i]==0); REP(x,m) assert(done[x]);
	int ret=0;
	REP(i,n) if(val[i]>=mn) {
		int cur=1+sum[i]+mxv[i][0];
		if(cur>ret) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&need);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) head[i]=-1,deg[i]=0; m=0;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[m]=head[a]; head[a]=m; to[m]=b; ++deg[a]; ++m;
		nxt[m]=head[b]; head[b]=m; to[m]=a; ++deg[b]; ++m;
	}
	REP(i,n) all[i]=val[i]; sort(all,all+n); nall=unique(all,all+n)-all;
	int l=0,h=nall; // [l,h)
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(calc(all[m])>=need) l=m; else h=m;
	}
	printf("%d\n",all[l]);
}

int main() {
	run();
	return 0;
}