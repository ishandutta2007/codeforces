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
const int MAXCLIENT=100000;
const int MAXHOUR=100000;

int n,nclient,nhour;
int updatehour[MAXN];
int dataloc[MAXCLIENT][2];

vector<int> adj[MAXN];
int id[MAXN],mnid[MAXN],nid;
int comp[MAXN],ncomp;
int stck[MAXN],nstck;
int compsz[MAXN],compoutdeg[MAXN];
int ret[MAXN],nret;

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
	if(mnid[at]==id[at]) {
		while(comp[at]==-1) comp[stck[--nstck]]=ncomp; ++ncomp;
	}
}

void run() {
	scanf("%d%d%d",&n,&nclient,&nhour);
	REP(i,n) scanf("%d",&updatehour[i]);
	REP(i,nclient) REP(j,2) scanf("%d",&dataloc[i][j]),--dataloc[i][j];

	REP(i,n) adj[i].clear();
	REP(i,nclient) {
		int a=dataloc[i][0],b=dataloc[i][1];
		//printf("(%d,%d)->(%d,%d) [%d]\n",a+1,b+1,updatehour[a],updatehour[b],nhour);
		if((updatehour[a]+1)%nhour==updatehour[b]) adj[a].PB(b);
		if((updatehour[b]+1)%nhour==updatehour[a]) adj[b].PB(a);
	}
	//REP(i,n) { printf("%d:",i+1); REPSZ(j,adj[i]) printf(" %d",adj[i][j]+1); puts(""); }

	REP(i,n) comp[i]=id[i]=-1; nid=ncomp=nstck=0;
	REP(i,n) if(comp[i]==-1) tarjan(i);

	REP(i,ncomp) compsz[i]=compoutdeg[i]=0;
	REP(at,n) { ++compsz[comp[at]]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(comp[to]!=comp[at]) ++compoutdeg[comp[at]]; } }

	int bcomp=-1;
	REP(i,ncomp) if(compoutdeg[i]==0&&(bcomp==-1||compsz[i]<compsz[bcomp])) bcomp=i;

	nret=0; REP(i,n) if(comp[i]==bcomp) ret[nret++]=i;
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}