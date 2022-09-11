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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXVAR=100000;
const int MAXCLAUSE=100000;
const int MAXN=2*MAXCLAUSE;

int nvar,nclause;
char s[MAXVAR+1];
int n;
vector<int> adj[MAXN];

int id[MAXN],lid[MAXN],nid;
int comp[MAXN],ncomp;
int stck[MAXN],nstck;

vector<int> compadj[MAXN];
int top[MAXN],topidx[MAXN],ntop;

int lastall[MAXN],cntall[MAXN];
bool impliesall[MAXN];

void tarjan(int at) {
	id[at]=lid[at]=nid++;
	stck[nstck++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(comp[to]!=-1) continue;
		if(id[to]==-1) { tarjan(to); lid[at]=min(lid[at],lid[to]); } else { lid[at]=min(lid[at],id[to]); }
	}
	if(lid[at]==id[at]) { while(comp[at]==-1) comp[stck[--nstck]]=ncomp; ++ncomp; }
}
void dfstop(int at) {
	topidx[at]=-2;
	REPSZ(i,compadj[at]) { int to=compadj[at][i]; assert(topidx[to]!=-2); if(topidx[to]==-1) dfstop(to); }
	top[ntop]=at,topidx[at]=ntop,++ntop;
}

bool solve() {
	REP(i,n) id[i]=comp[i]=-1; nid=ncomp=nstck=0;
	REP(i,n) if(id[i]==-1) tarjan(i);
	REP(i,nvar) if(comp[2*i+0]==comp[2*i+1]) return false;
	
	REP(i,n) REPSZ(j,adj[i]) { int a=comp[i],b=comp[adj[i][j]]; if(a!=b) compadj[a].PB(b); }
	REP(i,ncomp) { sort(compadj[i].begin(),compadj[i].end()); compadj[i].erase(unique(compadj[i].begin(),compadj[i].end()),compadj[i].end()); }
	REP(i,n) topidx[i]=-1; ntop=0;
	REP(i,n) if(topidx[i]==-1) dfstop(i);
	
	REP(i,ncomp) lastall[i]=-1,cntall[i]=0; REP(i,nvar) if(s[i]=='A') REP(j,2) lastall[comp[2*i+j]]=max(lastall[comp[2*i+j]],i),++cntall[comp[2*i+j]];
	REP(i,nvar) if(s[i]=='E') REP(j,2) if(lastall[comp[2*i+j]]>i) return false;
	REP(i,ncomp) { if(cntall[i]>=2) return false; impliesall[i]=cntall[i]>0; }
	REP(i,ntop) { int at=top[i]; REPSZ(j,compadj[at]) { int to=compadj[at][j]; assert(topidx[to]<topidx[at]); if(!impliesall[to]) continue; if(cntall[at]>0) return false; impliesall[at]=true; } }
	
	return true;
}

void run() {
	scanf("%d%d",&nvar,&nclause); n=2*nvar;
	scanf("%s",s);
	REP(i,nclause) { int a,b; scanf("%d%d",&a,&b); a=a<0?2*(-a-1)+0:2*(a-1)+1,b=b<0?2*(-b-1)+0:2*(b-1)+1; adj[a^1].PB(b),adj[b^1].PB(a); }
	printf("%s\n",solve()?"TRUE":"FALSE");
	REP(i,n) adj[i].clear();
	REP(i,ncomp) compadj[i].clear();
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}