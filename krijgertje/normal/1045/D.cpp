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

const int MAXN=100000;
const int MAXQ=100000;

int n;
double p[MAXN];
vector<int> adj[MAXN];
int nq;
int qidx[MAXQ]; double qp[MAXQ]; double qans[MAXQ];

int par[MAXN];
void dfsinit(int at) { REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; par[to]=at; dfsinit(to); } }

double cans;
double cp[MAXN];
double csum[MAXN];

void solve() {
	par[0]=-1; dfsinit(0);
	REP(i,n) cp[i]=p[i],csum[i]=0; REP(i,n) if(par[i]!=-1) csum[par[i]]+=1-cp[i];
	cans=0; REP(i,n) { double cur=1-cp[i]; if(par[i]!=-1) cur*=cp[par[i]]; cans+=cur; }
	REP(i,nq) {
		int at=qidx[i]; double np=qp[i];
		{ double prv=1-cp[at],cur=1-np; if(par[at]!=-1) prv*=cp[par[at]],cur*=cp[par[at]]; cans+=cur-prv; }
		{ double prv=cp[at],cur=np; prv*=csum[at],cur*=csum[at]; cans+=cur-prv; }
		if(par[at]!=-1) csum[par[at]]+=(1-np)-(1-cp[at]);
		cp[at]=np;
		qans[i]=cans;
		//double chk=0; REP(j,n) { double cur=1-cp[j]; if(par[j]!=-1) cur*=cp[par[j]]; chk+=cur; } printf("%lf vs %lf\n",cans,chk);
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lf",&p[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); adj[a].PB(b); adj[b].PB(a); }
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%lf",&qidx[i],&qp[i]);
	solve();
	REP(i,nq) printf("%.15lf\n",qans[i]);
}

int main() {
	run();
	return 0;
}