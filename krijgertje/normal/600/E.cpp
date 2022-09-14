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

int n;
int col[MAXN];
int head[MAXN],nxt[2*MAXM],to[2*MAXM];

int par[MAXN],sz[MAXN];
int q[MAXN],qhead,qtail;

int id[MAXN];
map<int,int> cnt[MAXN]; int mxcnt[MAXN]; ll mxsum[MAXN];
ll ret[MAXN];

void addcol(int cid,int ccol,int by) {
	int ncnt=cnt[cid][ccol]+=by;
	if(ncnt>mxcnt[cid]) mxcnt[cid]=ncnt,mxsum[cid]=0;
	if(ncnt==mxcnt[cid]) mxsum[cid]+=ccol;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&col[i]);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	memset(par,-1,sizeof(par)); qhead=qtail=0; q[qhead++]=0; par[0]=-2;
	while(qtail<qhead) { int at=q[qtail++]; for(int x=head[at];x!=-1;x=nxt[x]) if(par[to[x]]==-1) { par[to[x]]=at; q[qhead++]=to[x]; } }
	REP(i,n) sz[i]=1; for(int i=n-1;i>=1;--i) sz[par[q[i]]]+=sz[q[i]];
	//REP(i,n) printf("%d: %d (sz=%d,par=%d)\n",i,q[i],sz[q[i]],par[q[i]]);

	memset(id,-1,sizeof(id));
	for(int i=n-1;i>=0;--i) {
		int at=q[i],bsz=0;
		for(int x=head[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]&&sz[to[x]]>bsz) bsz=sz[to[x]],id[at]=id[to[x]];
		if(bsz==0) { id[at]=at; cnt[at].clear(); mxcnt[at]=0; mxsum[at]=0; }
		addcol(id[at],col[at],1);
		for(int x=head[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]&&id[to[x]]!=id[at]) for(map<int,int>::iterator it=cnt[id[to[x]]].begin();it!=cnt[id[to[x]]].end();++it) addcol(id[at],it->first,it->second);
		ret[at]=mxsum[id[at]];
	}

	REP(i,n) { if(i!=0) printf(" "); printf("%I64d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}