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

int n,need;
int a[300000],b[300000];

int deg[300000];
int fst[300000];
int nxt[300000];
int to[600000];
int cnt[600000];


int sorted[300000];
int rev[300000];
bool degcmp(int a,int b) { return deg[a]<deg[b]; }


void run() {
	scanf("%d%d",&n,&need);
	REP(i,n) { scanf("%d%d",&a[i],&b[i]); --a[i]; --b[i]; }
	memset(deg,0,sizeof(deg)); REP(i,n) { ++deg[a[i]]; ++deg[b[i]]; }
	fst[0]=nxt[0]=0; FOR(i,1,n) fst[i]=nxt[i]=fst[i-1]+deg[i-1];
	REP(i,n) {
		int idx1=nxt[a[i]]++; to[idx1]=b[i];
		int idx2=nxt[b[i]]++; to[idx2]=a[i];
	}
	REP(i,n) sort(to+fst[i],to+nxt[i]);
//	REP(i,n) { printf("%d:",i); FOR(j,fst[i],nxt[i]) printf(" %d",to[j]); puts(""); }
	REP(i,n) {
		int nnxt=fst[i];
		FOR(j,fst[i],nxt[i]) if(nnxt!=fst[i]&&to[j]==to[nnxt-1]) ++cnt[nnxt-1]; else { to[nnxt]=to[j]; cnt[nnxt]=1; ++nnxt; }
		nxt[i]=nnxt;
	}
//	REP(i,n) { printf("%d:",i); FOR(j,fst[i],nxt[i]) printf(" %d*%d",cnt[j],to[j]); puts(""); }
	REP(i,n) sorted[i]=i; sort(sorted,sorted+n,degcmp);
	REP(i,n) rev[sorted[i]]=i;
//	REP(i,n) printf("%d ",sorted[i]); puts("");
	int ai=0,bi=n-1; ll ret=0;
	while(ai<bi) {
		int a=sorted[ai],b=sorted[bi];
		if(deg[a]+deg[b]<need) { ++ai; continue; }
		int now=bi-ai;
		FOR(j,fst[b],nxt[b]) {
//			printf("\t\t%d [%d] -> %d (%d+%d-%d)\n",to[j],rev[to[j]],deg[to[j]]+deg[b]-cnt[j],deg[to[j]],deg[b],cnt[j]);
			if(ai<=rev[to[j]]&&rev[to[j]]<bi&&deg[to[j]]+deg[b]-cnt[j]<need) --now;
		}
//		printf("\t%d..%d -> %d [%d..%d]\n",a,b,now,ai,bi);
		ret+=now; --bi;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}