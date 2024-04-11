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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXM=MAXN-1;

int n;
int fst[MAXN],nxt[2*MAXM],to[2*MAXM];

bool been[MAXN];
int par[MAXN];
int q[MAXN],qhead,qtail;

int mnme[MAXN],mnop[MAXM],mxme[MAXN],mxop[MAXN],cnt[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	REP(i,n) been[i]=false;
	qhead=qtail=0; q[qhead++]=0; been[0]=true; par[0]=-1;
	while(qtail<qhead) { int at=q[qtail++]; for(int x=fst[at];x!=-1;x=nxt[x]) if(!been[to[x]]) { q[qhead++]=to[x]; been[to[x]]=true; par[to[x]]=at; } }

	for(int i=n-1;i>=0;--i) {
		int at=q[i];
		cnt[at]=0; for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]) cnt[at]+=cnt[to[x]];
		if(cnt[at]==0) { mnme[at]=mnop[at]=mxme[at]=mxop[at]=cnt[at]=1; continue; }
		mxme[at]=INT_MIN,mnop[at]=INT_MAX;
		int cntnotmnme=0,cntnotmxop=0;
		for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]) {
			cntnotmnme+=cnt[to[x]]-mnop[to[x]];
			int cmxme=cnt[at]-cnt[to[x]]+mxop[to[x]]; if(cmxme>mxme[at]) mxme[at]=cmxme;
			int cmnop=mnme[to[x]]; if(cmnop<mnop[at]) mnop[at]=cmnop;
			cntnotmxop+=mxme[to[x]]-1;
		}
		mnme[at]=cnt[at]-cntnotmnme,mxop[at]=cntnotmxop+1;
	}
	printf("%d %d\n",mxme[0],mnme[0]);
}

int main() {
	run();
	return 0;
}