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
#include <bitset>
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

const int MAXN=1000;
const int MAXANS=100000;

int n;
vector<pair<int,int>> adj[MAXN];
int nans;
int ansx[MAXANS],ansy[MAXANS],ansz[MAXANS];

int findleaf(int at,int par) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first; if(to==par) continue;
		return findleaf(to,at);
	}
	return at;
}

bool findleafs(int at,int par,vector<int> &lst) {
	ll lensum=0; int parlen=-1;
	REPSZ(i,adj[at]) if(SZ(lst)<2) {
		int to=adj[at][i].first,len=adj[at][i].second; if(to==par) { parlen=len; continue; } else lensum+=len;
		lst.PB(findleaf(to,at));
	}
	if(SZ(lst)==1) { /*printf("at=%d par=%d parlen=%d lensum=%lld\n",at+1,par+1,parlen,lensum);*/ assert(parlen!=lensum); return false; }
	if(SZ(lst)==0) lst.PB(at);
	return true;
}

bool solve() {
	nans=0;
	REP(at,n) REPSZ(i,adj[at]) {
		int to=adj[at][i].first,cur=adj[at][i].second; if(at>to) continue; assert(cur%2==0); if(cur==0) continue;
		vector<int> atleafs,toleafs;
		if(!findleafs(at,to,atleafs)) return false;
		if(!findleafs(to,at,toleafs)) return false;
		REP(_,2) { int j=_<SZ(atleafs)?_:0; int k=_<SZ(toleafs)?_:0; ansx[nans]=atleafs[j],ansy[nans]=toleafs[k],ansz[nans]=cur/2,++nans; }
		if(SZ(atleafs)==2) ansx[nans]=atleafs[0],ansy[nans]=atleafs[1],ansz[nans]=-cur/2,++nans;
		if(SZ(toleafs)==2) ansx[nans]=toleafs[0],ansy[nans]=toleafs[1],ansz[nans]=-cur/2,++nans;
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); }
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",nans);
	REP(i,nans) printf("%d %d %d\n",ansx[i]+1,ansy[i]+1,ansz[i]);
}

int main() {
	run();
	return 0;
}