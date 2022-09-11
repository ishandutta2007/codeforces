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

const int MAXN=40;

int n,have;
ll adj[MAXN];
int deg[MAXN];
pair<int,int> o[MAXN];

int best;
void dfs(ll yes,ll opt,int idx,int cnt) {
	int mx=cnt; REP(i,n) if((opt>>i)&1) ++mx; if(mx<=best) return;
	while(idx<n&&((opt>>o[idx].second)&1)==0) ++idx; if(idx>=n) { if(cnt>best) best=cnt; return; }
	int at=o[idx].second;
	ll all=(yes|opt)-(1LL<<at); if((all&adj[at])==all) { dfs(yes|(1LL<<at),opt&adj[at],idx+1,cnt+1); return; }
	//printf("dfs("); REP(i,n) printf("%c",((yes>>i)&1)?'x':'.'); printf(","); REP(i,n) printf("%c",((no>>i)&1)?'x':'.'); printf(",%d) => at=%d -> %c\n",cnt,at,(yes&adj[at])==yes?'V':'-');
	dfs(yes,opt-(1LL<<at),idx+1,cnt);
	if((yes&adj[at])==yes) dfs(yes|(1LL<<at),opt&adj[at],idx+1,cnt+1);
}

void run() {
	scanf("%d%d",&n,&have);
	REP(i,n) adj[i]=0,deg[i]=0;
	REP(i,n) REP(j,n) { int x; scanf("%d",&x); adj[i]|=(ll)x<<j; deg[i]+=x; }
	REP(i,n) o[i]=MP(deg[i],i); sort(o,o+n);
	best=0; dfs(0,(1LL<<n)-1,0,0); int sz=best;
	//printf("sz=%d\n",sz);
	double ret=sz<=1?0:sz*(sz-1)/2*(1.0*have/sz)*(1.0*have/sz);
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}