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

const int MAXN=500;
const int MAXM=100000;

int n,m;
int ghead[MAXN],gnxt[MAXM],gto[MAXM]; bool oncyc[MAXM];

bool onstack[MAXN],done[MAXN];
int path[MAXN],npath=0;
int cyc[MAXN],ncyc;
bool dfscyc(int at) {
	done[at]=true;
	onstack[at]=true;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x];
		if(onstack[to]) {
			ncyc=0; oncyc[x]=true;
			while(npath>0) { int y=path[npath-1],yto=gto[y]; if(yto==to) break; --npath; oncyc[y]=true; cyc[ncyc++]=yto; }
			cyc[ncyc++]=to; reverse(cyc,cyc+ncyc);
			return true;
		} else if(!done[to]) {
			path[npath++]=x;
			if(dfscyc(to)) return true;
			--npath;
		}
	}
	onstack[at]=false;
	return false;
}

int cycid[MAXN];

bool reach[MAXN][MAXN];
int q[MAXN+1],qhead,qtail;

int mark[MAXN+1];


bool solve() {
	bool found=false; npath=0; REP(i,n) done[i]=false,onstack[i]=false;
	REP(i,n) if(!done[i]) if(dfscyc(i)) { found=true; break; }
	if(!found) return true;
	//REP(i,n) for(int x=ghead[i];x!=-1;x=gnxt[x]) if(oncyc[x]) printf("%d->%d\n",i+1,gto[x]+1);
	//printf("cyc:"); REP(i,ncyc) printf(" %d",cyc[i]+1); puts("");

	REP(i,n) cycid[i]=-1; REP(i,ncyc) cycid[cyc[i]]=i;

	REP(s,n) {
		REP(t,n) reach[s][t]=false;
		qhead=qtail=0; q[qhead++]=s;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=ghead[at];x!=-1;x=gnxt[x]) {
				int to=gto[x]; if(reach[s][to]||oncyc[x]) continue;
				reach[s][to]=true; q[qhead++]=to;
			}
		}
		if(reach[s][s]) return false;
	}

	REPE(i,ncyc) mark[i]=0;
	REP(i,ncyc) REP(j,ncyc) if(i!=j&&reach[cyc[i]][cyc[j]]) {
		if(i<j) {
			++mark[i],--mark[j];
		} else {
			++mark[0],--mark[j],++mark[i],--mark[ncyc];
		}
	}
	REP(i,ncyc) mark[i+1]+=mark[i];
	//printf("mark:"); REPE(i,ncyc) printf(" %d",mark[i]); puts("");
	REP(i,ncyc) if(mark[i]==0) return true;
	return false;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,n) ghead[i]=-1; REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; gnxt[i]=ghead[a],ghead[a]=i,gto[i]=b,oncyc[i]=false; }
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}