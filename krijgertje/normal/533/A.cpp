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

const int MAXN=500000;
const int MAXM=MAXN-1;

int n;
int lim[MAXN],have[MAXN];
int fst[MAXN],nxt[2*MAXM],to[2*MAXM];
int par[MAXN];

int nwant;
int want[MAXN];
int shave[MAXN];

int nlft;
int lft[MAXN];

int ncand;
int cand[MAXN];

int ngain;
int gain[MAXN];

void dfs(int at) {
	have[at]=lim[at]; if(par[at]!=-1&&have[par[at]]<have[at]) have[at]=have[par[at]];
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		par[to[x]]=at; dfs(to[x]);
	}
}
void getcand(int at,int maxolim,int nlim) {
	if(lim[at]<=maxolim) { cand[ncand++]=at; return; }
	if(lim[at]<nlim) return;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]) getcand(to[x],maxolim,nlim);
}
void getgain(int at,int nlim) {
	if(nlim<=have[at]) return;
	gain[ngain++]=nlim;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		getgain(to[x],min(nlim,lim[to[x]]));
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&lim[i]);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	scanf("%d",&nwant);
	REP(i,nwant) scanf("%d",&want[i]);
	while(nwant<n) want[nwant++]=0;
	sort(want,want+n);
	//REP(i,n) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	par[0]=-1; dfs(0);
	REP(i,n) shave[i]=have[i]; sort(shave,shave+n);

	int nlim=-1;
	REP(i,n) if(want[i]>shave[i]) nlim=want[i];
	if(nlim==-1) { printf("0\n"); return; }
	//if(n==460000) printf("nlim=%d\n",nlim);

	int maxolim=-1;
	REP(i,n) if(shave[i]<want[i]) { maxolim=shave[i]; break; }
	ncand=0; getcand(0,maxolim,nlim);
	//if(n==460000) printf("maxolim=%d\n",maxolim);
	//if(n==460000) { printf("cand:"); REP(i,ncand) printf(" %d",cand[i]); puts(""); }

	nlft=0;
	for(int i=n-1,j=n-1;i>=0;--i) if(want[i]<=shave[j]) --j; else lft[nlft++]=want[i];
	sort(lft,lft+nlft);
	//if(n==460000) { printf("left:"); REP(i,nlft) printf(" %d",lft[i]); puts(""); }

	int ret=-1;
	REP(i,ncand) {
		int cur=nlim-lim[cand[i]];
		if(ret!=-1&&cur>ret) continue;
		ngain=0; getgain(cand[i],nlim);
		//if(n==460000&&cur<=360400426) { printf("cand %d (%d) ->",cand[i],cur); REP(j,ngain) printf(" %d",gain[j]); puts(""); }
		if(ngain<nlft) continue;
		sort(gain,gain+ngain);
		bool ok=true; REP(j,nlft) if(lft[j]>gain[ngain-nlft+j]) { ok=false; break; } if(!ok) continue;
		ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}