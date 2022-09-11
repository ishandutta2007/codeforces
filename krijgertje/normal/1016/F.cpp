#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=300000;

int n,nq;
vector<pair<int,int> > e[MAXN];

int q[MAXN],qhead,qtail;
ll d[MAXN]; int prv[MAXN];

int path[MAXN],npath;
bool onpath[MAXN];

ll x[MAXN];
ll y[MAXN];

ll solve() {
	REP(i,n) d[i]=LLONG_MAX,prv[i]=-2; qhead=qtail=0;
	d[0]=0,prv[0]=-1,q[qhead++]=0;
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,e[at]) { int to=e[at][i].first; if(d[to]==LLONG_MAX) d[to]=d[at]+e[at][i].second,prv[to]=at,q[qhead++]=to; } }
	assert(d[n-1]!=LLONG_MAX);
	npath=0; for(int at=n-1;at!=-1;at=prv[at]) path[npath++]=at; reverse(path,path+npath);
	REP(i,n) onpath[i]=false; REP(i,npath) onpath[path[i]]=true;

	REP(i,npath) {
		int at=path[i];
		x[i]=d[at],y[i]=0;
		REPSZ(j,e[at]) {
			int to=e[at][j].first; if(onpath[to]) continue; 
			if(SZ(e[to])!=1||y[i]!=0) return 0; else y[i]=e[at][j].second;
		}
	}
	//REP(i,npath) printf("%d: %lld %lld\n",i,x[i],y[i]);

	ll ret=LLONG_MIN,mx=LLONG_MIN;
	FOR(i,1,npath) { // max x[j]-x[i]+y[i]+y[j] unless y[i]==0 and y[j]==0 and j==i-1
		if(i>=2) mx=max(mx,x[i-2]+y[i-2]);
		if(y[i-1]!=0||y[i]!=0) ret=max(ret,x[i-1]-x[i]+y[i]+y[i-1]); //,printf("%d-%d -> %lld\n",i-1,i,x[i-1]-x[i]+y[i]+y[i-1]);
		if(i>=2) ret=max(ret,-x[i]+y[i]+mx); //,printf("?-%d -> %lld\n",i,-x[i]+y[i]+mx);
	}
	return -ret;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }

	ll res=solve();
	//printf("res=%lld\n",res);
	REP(i,nq) {
		int want; scanf("%d",&want);
		ll cost=max(0LL,res-want);
		ll ans=d[n-1]-cost;
		printf("%lld\n",ans);
	}




}

int main() {
	run();
	return 0;
}