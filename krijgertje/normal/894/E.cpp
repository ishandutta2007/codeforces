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

const int MAXN=1000000;

int n,m;
vector<pair<int,int> > adj[MAXN];
int s;

int comp[MAXN],ncomp;
int id[MAXN],mnid[MAXN],nid;
int stck[MAXN],nstck;

ll cloc[MAXN],cglob[MAXN];
vector<pair<int,int> > cadj[MAXN];

void tarjan(int at) {
	id[at]=mnid[at]=nid++; stck[nstck++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first;
		if(id[to]==-1) {
			tarjan(to);
			mnid[at]=min(mnid[at],mnid[to]);
		} else if(comp[to]==-1) {
			mnid[at]=min(mnid[at],id[to]);
		}
	}
	if(mnid[at]>=id[at]) {
		while(comp[at]==-1) comp[stck[--nstck]]=ncomp; ++ncomp;
	}
}

int top[MAXN],ntop; bool beentop[MAXN];
void dfstop(int at) {
	if(beentop[at]) return; else beentop[at]=true;
	REPSZ(i,cadj[at]) { int to=cadj[at][i].first; dfstop(to); }
	top[ntop++]=at;
}

ll calcall(int cnt) {
	ll l=0,h=1;
	while(h*(h+1)/2<=cnt) l=h,h+=h;
	while(l+1<h) { ll m=l+(h-l)/2; if(m*(m+1)/2<=cnt) l=m; else h=m; }
	ll x=l; ll ret=(x+1)*cnt-x*(x+1)*(x+2)/6;
	//printf("%d->%lld (%lld)\n",cnt,ret,x);
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); }
	scanf("%d",&s); --s;
	
	REP(i,n) comp[i]=id[i]=-1; nid=nstck=ncomp=0;
	REP(i,n) if(comp[i]==-1) tarjan(i);
	//printf("comp:"); REP(i,n) printf(" %d",comp[i]); puts("");

	REP(i,ncomp) cloc[i]=0,cadj[i].clear();
	REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i].first,cnt=adj[at][i].second; if(comp[at]==comp[to]) cloc[comp[at]]+=calcall(cnt); else cadj[comp[at]].PB(MP(comp[to],cnt)); }
	ntop=0; REP(i,ncomp) beentop[i]=false; dfstop(comp[s]);
	//printf("top:"); REP(i,ntop) printf(" %d",top[i]); puts("");
	REP(i,ntop) { int at=top[i]; cglob[at]=cloc[at]; REPSZ(j,cadj[at]) { int to=cadj[at][j].first,cnt=cadj[at][j].second; cglob[at]=max(cglob[at],cloc[at]+cnt+cglob[to]); } }
	printf("%lld\n",cglob[comp[s]]);
}

int main() {
	run();
	return 0;
}