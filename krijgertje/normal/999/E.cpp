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

const int MAXN=5000;

int n,m,s;
vector<int> adj[MAXN];

int id[MAXN],mnid[MAXN],nid;
int comp[MAXN],ncomp;
int stck[MAXN],nstck;

bool leafcomp[MAXN];

void tarjan(int at) {
	id[at]=mnid[at]=nid++; stck[nstck++]=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
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

void run() {
	scanf("%d%d%d",&n,&m,&s); --s;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); }

	nid=ncomp=nstck=0; REP(i,n) id[i]=comp[i]=-1;
	REP(i,n) if(id[i]==-1) tarjan(i);

	REP(i,ncomp) leafcomp[i]=true;
	REP(i,n) REPSZ(j,adj[i]) { int a=comp[i],b=comp[adj[i][j]]; if(a!=b) leafcomp[b]=false; }
	
	int ret=0;
	REP(i,ncomp) if(leafcomp[i]&&i!=comp[s]) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}