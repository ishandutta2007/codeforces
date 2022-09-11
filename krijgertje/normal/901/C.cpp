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

int n,m;
vector<int> adj[MAXN];

vector<int> cycle[MAXN];
int limit[MAXN];
ll limitsum[MAXN+1];

int state[MAXN];
int stck[MAXN],nstck;
void dfs(int at,int par) {
	state[at]=1; stck[nstck++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		if(state[to]==0) {
			dfs(to,at);
		} else if(state[to]==1) {
			int mn=to,mx=to;
			for(int i=nstck-1;stck[i]!=to;--i) mn=min(mn,stck[i]),mx=max(mx,stck[i]);
			cycle[mn].PB(mx);
		}
	}
	state[at]=2; assert(stck[--nstck]==at);
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	memset(state,0,sizeof(state)); REP(i,n) cycle[i].clear();
	REP(i,n) if(state[i]==0) dfs(i,-1);
	//REP(i,n) REPSZ(j,cycle[i]) printf("%d-%d\n",i+1,cycle[i][j]+1);

	for(int i=n-1;i>=0;--i) {
		limit[i]=i==n-1?n-1:limit[i+1];
		REPSZ(j,cycle[i]) limit[i]=min(limit[i],cycle[i][j]-1);
	}
	limitsum[0]=0; REP(i,n) limitsum[i+1]=limitsum[i]+(limit[i]-i+1);
	//printf("limit:"); REP(i,n) printf(" %d",limit[i]+1); puts("");

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int ql,qr; scanf("%d%d",&ql,&qr); --ql,--qr;
		int l=ql-1,r=qr+1; while(l+1<r) { int m=l+(r-l)/2; if(limit[m]>qr) r=m; else l=m; } int qm=r;
		ll ans=0; int nsmall=qm-ql,nlarge=qr-qm+1;
		//printf("%d..%d: %d (nlarge=%d,nsmall=%d)\n",ql+1,qr+1,qm+1,nlarge,nsmall);
		ans+=(ll)(limitsum[qm]-limitsum[ql]);
		ans+=(ll)nlarge*(nlarge+1)/2;
		printf("%lld\n",ans);
	}
}

int main() {
	run();
	return 0;
}