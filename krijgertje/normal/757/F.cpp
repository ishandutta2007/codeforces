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
const int MAXM=300000;

int n,m,s;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],glen[MAXM];
ll d[MAXN]; priority_queue<pair<ll,int> > q;
int dhead[MAXN],dnxt[2*MAXM];
int ddhead[MAXN],ddnxt[2*MAXM];
int rhead[MAXN],rnxt[MAXN];
int chead[MAXN],cnxt[MAXN];
int p[MAXN],idx[MAXN],np,tpar[MAXN];
int upar[MAXN],umin[MAXN];
int sdom[MAXN],rdom[MAXN],idom[MAXN];
int sz[MAXN];

void dijkstra() {
	REP(i,n) d[i]=LLONG_MAX; q=priority_queue<pair<ll,int> >();
	d[s]=0; q.push(MP(-d[s],s));
	while(!q.empty()) {
		int at=q.top().second; ll cost=-q.top().first; q.pop();
		if(cost!=d[at]) continue;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; ll ncost=cost+glen[x>>1]; if(ncost>=d[to]) continue;
			d[to]=ncost; q.push(MP(-d[to],to));
		}
	}
}

void dfs(int at) {
	idx[at]=np,p[np++]=at;
	for(int x=dhead[at];x!=-1;x=dnxt[x]) if(tpar[gto[x]]==-1) tpar[gto[x]]=at,dfs(gto[x]);
}

int ufindmin(int at) {
	if(upar[at]==at) return at;
	if(upar[upar[at]]!=upar[at]) { int cur=ufindmin(upar[at]); if(idx[sdom[cur]]<idx[sdom[umin[at]]]) umin[at]=cur; upar[at]=upar[upar[at]]; }
	return umin[at];
}

void ujoin(int at,int to) {
	assert(upar[at]==at); upar[at]=to; umin[at]=at;
}

int solve() {
	dijkstra();
	REP(i,n) dhead[i]=ddhead[i]=rhead[i]=chead[i]=-1,sz[i]=0,tpar[i]=-1;
	REP(at,n) if(d[at]!=LLONG_MAX) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(d[at]+glen[x>>1]==d[gto[x]]&&(glen[x>>1]!=0||(x&1)==0)) dnxt[x]=dhead[at],dhead[at]=x,ddnxt[x^1]=ddhead[gto[x]],ddhead[gto[x]]=x^1;
	//REP(at,n) for(int x=dhead[at];x!=-1;x=dnxt[x]) printf("%d->%d\n",at+1,gto[x]+1);
	np=0; tpar[s]=-2,dfs(s);
	REP(i,np) { int at=p[i]; upar[at]=at,umin[at]=-1,sdom[at]=-1; }
	for(int i=np-1;i>=0;--i) {
		int at=p[i];
		//printf("processing %d\n",at+1);
		for(int to=rhead[at];to!=-1;to=rnxt[to]) {
			rdom[to]=ufindmin(to);
			//printf("\t\trdom[%d]=%d\n",to+1,rdom[to]+1);
		}
		if(at==s) continue;
		for(int x=ddhead[at];x!=-1;x=ddnxt[x]) {
			int cur=ufindmin(gto[x]),now=upar[gto[x]]==gto[x]?cur:sdom[cur];
			//printf("\t\t\tufindmin(%d)=%d->%d\n",gto[x]+1,cur+1,now+1);
			if(sdom[at]==-1||idx[now]<idx[sdom[at]]) sdom[at]=now;
		}
		//printf("\tsdom[%d]=%d\n",at+1,sdom[at]+1);
		ujoin(at,tpar[at]); rnxt[at]=rhead[sdom[at]]; rhead[sdom[at]]=at;
	}
	idom[s]=-1; FOR(i,1,np) { int at=p[i]; idom[at]=sdom[at]==sdom[rdom[at]]?sdom[at]:idom[rdom[at]]; cnxt[at]=chead[idom[at]],chead[idom[at]]=at; sz[at]=1; }
	//REP(i,np) { int at=p[i]; printf("%d: sdom=%d rdom=%d idom=%d tpar=%d\n",at+1,sdom[at]+1,rdom[at]+1,idom[at]+1,tpar[at]+1); }
	for(int i=np-1;i>=0;--i) { int at=p[i]; sz[idom[at]]+=sz[at]; }
	int ret=0; FOR(i,1,np) { int at=p[i]; if(sz[at]>ret) ret=sz[at]; } return ret;
}

void run() {
	scanf("%d%d%d",&n,&m,&s); --s;
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&glen[i]); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}