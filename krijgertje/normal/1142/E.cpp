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

const int MAXN=100000;
const int MAXPINK=100000;
const int MAXCOMP=MAXN;

int n,npink;
vector<int> pink[MAXN];

int id[MAXN],mnid[MAXN],nid;
int comp[MAXN],ncomp;
int stck[MAXN],nstck;

vector<int> compnodes[MAXCOMP];
vector<int> comppink[MAXCOMP];
int compindeg[MAXCOMP];
queue<int> heads;

void tarjan(int at) {
	id[at]=mnid[at]=nid++; stck[nstck++]=at;
	REPSZ(i,pink[at]) {
		int to=pink[at][i];
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

bool query(int a,int b) {
	printf("? %d %d\n",a+1,b+1); fflush(stdout);
	int ret; scanf("%d",&ret); return ret==1;
}

int solve() {
	nid=ncomp=nstck=0; REP(i,n) id[i]=comp[i]=-1;
	REP(i,n) if(comp[i]==-1) tarjan(i);
	//printf("comp:"); REP(i,n) printf(" %d",comp[i]); puts("");
	
	REP(i,ncomp) compnodes[i].clear(),comppink[i].clear();
	REP(i,n) { compnodes[comp[i]].PB(i); REPSZ(j,pink[i]) { int a=comp[i],b=comp[pink[i][j]]; if(a!=b) comppink[a].PB(b); } }
	REP(i,ncomp) { sort(comppink[i].begin(),comppink[i].end()); comppink[i].erase(unique(comppink[i].begin(),comppink[i].end()),comppink[i].end()); }
	REP(i,ncomp) compindeg[i]=0; REP(i,ncomp) REPSZ(j,comppink[i]) ++compindeg[comppink[i][j]];
	//printf("compindeg:"); REP(i,ncomp) printf(" %d",compindeg[i]); puts("");
	
	heads=queue<int>(); REP(i,ncomp) if(compindeg[i]==0) heads.push(i);
	while(SZ(heads)>=2) {
		int a=heads.front(); heads.pop(); int b=heads.front(); heads.pop();
		if(!query(compnodes[a].back(),compnodes[b].back())) swap(a,b);
		compnodes[b].pop_back();
		if(SZ(compnodes[b])==0) {
			REPSZ(i,comppink[b]) { int c=comppink[b][i]; if(--compindeg[c]==0) heads.push(c); }
		} else {
			heads.push(b);
		}
		heads.push(a);
	}
	return compnodes[heads.front()].back();	
}

void run() {
	scanf("%d%d",&n,&npink); assert(n<=MAXN);
	REP(i,npink) { int a,b; scanf("%d%d",&a,&b); --a,--b; pink[a].PB(b); }
	int ans=solve();
	printf("! %d\n",ans+1); fflush(stdout);
	
}

int main() {
	run();
	return 0;
}