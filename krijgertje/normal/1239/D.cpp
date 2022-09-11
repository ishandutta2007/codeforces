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
#include <chrono>
#include <chrono>
#include <random>
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
const int MAXCOMP=MAXN;

int n,m;
vector<int> adj[MAXN];
vector<int> ansjury,anscat;

int id[MAXN],mnid[MAXN],nid;
int comp[MAXN],ncomp;
int stck[MAXN],nstck;
bool compok[MAXN]; int compsz[MAXN];

void tarjan(int at) {
	id[at]=mnid[at]=nid++; stck[nstck++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(comp[to]!=-1) continue;
		if(id[to]==-1) {
			tarjan(to);
			mnid[at]=min(mnid[at],mnid[to]);
		} else {
			mnid[at]=min(mnid[at],id[to]);
		}
	}
	if(mnid[at]>=id[at]) {
		while(comp[at]==-1) comp[stck[--nstck]]=ncomp;
		++ncomp;
	}
}

bool solve() {
	nid=ncomp=nstck=0; REP(i,n) id[i]=comp[i]=-1;
	REP(i,n) if(comp[i]==-1) tarjan(i);
	REP(i,ncomp) compok[i]=true,compsz[i]=0;
	REP(at,n) ++compsz[comp[at]];
	REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; if(comp[to]!=comp[at]) compok[comp[at]]=false; }
	int jurycompidx=-1; REP(i,ncomp) if(compok[i]&&compsz[i]!=n) { jurycompidx=i; break; } if(jurycompidx==-1) return false;
	ansjury.clear(),anscat.clear(); REP(at,n) if(comp[at]==jurycompidx) ansjury.PB(at); else anscat.PB(at);
	return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; if(a!=b) adj[a].PB(b); }
	bool ans=solve();
	REP(i,n) adj[i].clear();
	printf("%s\n",ans?"Yes":"No");
	if(ans) { printf("%d %d\n",SZ(ansjury),SZ(anscat)); REPSZ(i,ansjury) { if(i!=0) printf(" "); printf("%d",ansjury[i]+1); } puts(""); REPSZ(i,anscat) { if(i!=0) printf(" "); printf("%d",anscat[i]+1); } puts(""); }
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}