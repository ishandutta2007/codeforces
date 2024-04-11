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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXCONS=400000;
const int MAXSTAT=400000;
const int MAXPOW=400000;
const int MAXFORBID=400000;
const int MAXTERM=MAXSTAT+2*MAXPOW;
const int MAXNODE=2*MAXTERM;
const int MAXCOMP=MAXNODE;


int ncons,nstat,npow,nforbid;
int cons[MAXCONS][2];
int lpow[MAXSTAT],rpow[MAXSTAT];
int forbid[MAXFORBID][2];
int use[MAXSTAT],nuse,usepow;

int nterm,nnode;
int zid[MAXSTAT],aid[MAXPOW],bid[MAXPOW];
vector<int> adj[MAXNODE];

void addimpl(int a,int b) {
	//printf("%d->%d and %d->%d\n",a,b,b^1,a^1);
	adj[a].PB(b); adj[b^1].PB(a^1); 
}

vector<int> id,mnid; int nid;
vector<int> comp; int ncomp;
vector<int> stck; int nstck;

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

vector<int> rcompadj[MAXCOMP];
int company[MAXCOMP];
int outdeg[MAXCOMP];
char compres[MAXCOMP];
int q[MAXCOMP],qhead,qtail;

bool solve() {
	nterm=nnode=0;
	REP(i,nstat) zid[i]=nnode,++nterm,nnode+=2;
	REP(i,npow) aid[i]=nnode,++nterm,nnode+=2,bid[i]=nnode,++nterm,nnode+=2;
	REP(i,npow-1) addimpl(aid[i+1],aid[i]);
	REP(i,npow-1) addimpl(bid[i],bid[i+1]);
	REP(i,npow-1) addimpl(aid[i+1],bid[i]^1);
	REP(i,nstat) addimpl(zid[i],aid[lpow[i]]);
	REP(i,nstat) addimpl(zid[i],bid[rpow[i]]);
	REP(i,ncons) addimpl(zid[cons[i][0]]^1,zid[cons[i][1]]);
	REP(i,nforbid) addimpl(zid[forbid[i][0]],zid[forbid[i][1]]^1);

	ncomp=nid=nstck=0; id=comp=mnid=stck=vector<int>(nnode,-1);
	REP(i,nnode) if(comp[i]==-1) tarjan(i);
	id=mnid=stck=vector<int>();
	//printf("comp:"); REP(i,nnode) printf(" %d",comp[i]); puts("");
	REP(i,nterm) if(comp[2*i+0]==comp[2*i+1]) return false;

	REP(i,ncomp) outdeg[i]=0,rcompadj[i].clear(),company[i]=-1,compres[i]=-1;
	REP(at,nnode) if(company[comp[at]]==-1) company[comp[at]]=at;
	REP(at,nnode) REPSZ(i,adj[at]) { int to=adj[at][i]; if(comp[to]==comp[at]) continue; ++outdeg[comp[at]]; rcompadj[comp[to]].PB(comp[at]); }
	//REP(i,ncomp) { printf("%d:",i); REPSZ(j,compadj[i]) printf(" %d",compadj[i][j]); puts(""); }
	qhead=qtail=0; REP(i,ncomp) if(outdeg[i]==0) q[qhead++]=i;
	//printf("outdeg:"); REP(i,ncomp) printf(" %d",outdeg[i]); puts("");
	while(qtail<qhead) {
		int c=q[qtail++]; if(compres[c]!=-1) continue;
		int cc=comp[company[c]^1];
		//printf("processing %d (%d)\n",c,cc);
		compres[c]=1,compres[cc]=0;
		REPSZ(i,rcompadj[c]) { int to=rcompadj[c][i]; /*printf("to me %d\n",to);*/ if(--outdeg[to]==0) q[qhead++]=to; }
		REPSZ(i,rcompadj[cc]) { int to=rcompadj[cc][i]; /*printf("to oth %d\n",to);*/ assert(compres[to]==0); }
	}
	REP(i,ncomp) assert(compres[i]!=-1);

	nuse=0;
	REP(i,nstat) if(compres[comp[zid[i]]]==1) use[nuse++]=i;
	usepow=0; while(usepow+1<npow&&compres[comp[aid[usepow+1]]]==1) ++usepow;

	return true;
}

void run() {
	scanf("%d%d%d%d",&ncons,&nstat,&npow,&nforbid);
	REP(i,ncons) REP(j,2) scanf("%d",&cons[i][j]),--cons[i][j];
	REP(i,nstat) scanf("%d%d",&lpow[i],&rpow[i]),--lpow[i],--rpow[i];
	REP(i,nforbid) REP(j,2) scanf("%d",&forbid[i][j]),--forbid[i][j];
	if(!solve()) { printf("-1\n"); return; }
	printf("%d %d\n",nuse,usepow+1);
	REP(i,nuse) { if(i!=0) printf(" "); printf("%d",use[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}