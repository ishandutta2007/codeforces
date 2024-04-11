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

int n,k;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gcost[MAXM];

ll bestup[MAXN],bestdown[MAXN];

pair<ll,int> cur[MAXN]; int ncur;

void dfs(int at,int par) {
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs(to,at);
		bestup[to]+=gcost[x>>1]; bestdown[to]+=gcost[x>>1];
	}
	ncur=0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		cur[ncur++]=MP(bestup[to],to);
	}
	sort(cur,cur+ncur); reverse(cur,cur+ncur);
	bestup[at]=0; REP(i,min(ncur,k-1)) bestup[at]+=cur[i].first;
	ll extra=0; REP(i,ncur) { ll now=i<k-1?bestdown[cur[i].second]-bestup[cur[i].second]+(k-1<ncur?cur[k-1].first:0):bestdown[cur[i].second]; if(now>extra) extra=now; }
	bestdown[at]=bestup[at]+extra;
}

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); gcost[i]=c;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	dfs(0,-1); printf("%lld\n",bestdown[0]);
}

int main() {
	run();
	return 0;
}