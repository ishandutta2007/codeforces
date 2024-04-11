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
const int MAXM=100000;

int n,m;
int want[MAXN];
int ret[MAXN],nret;
int chead[MAXN],cnxt[MAXN],par[MAXN];
int whead[MAXN],wnxt[MAXN];
bool dead[MAXN];

int q[MAXN],qhead,qtail;

bool kill(int at,int root) {
	for(int prv=-1;at!=-1&&!dead[at];prv=at,at=par[at]) {
		dead[at]=true; //printf("killing %d (by %d)\n",at,root);
		if(whead[at]!=-1&&at!=root) return false;
		for(int to=chead[at];to!=-1;to=cnxt[to]) if(to!=prv) q[qhead++]=to;
	}
	return true;
}
bool solve() {
	nret=0;
	qhead=qtail=0; REP(i,n) if(par[i]==-1) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++]; if(dead[at]) continue; //printf("at %d\n",at);
		ret[nret++]=at;
		kill(at,at);
		for(int to=whead[at];to!=-1;to=wnxt[to]) if(!kill(to,at)) return false;
	}
	reverse(ret,ret+nret); return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) chead[i]=-1,par[i]=-1,cnxt[i]=-1,whead[i]=-1,wnxt[i]=-1,dead[i]=false;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		par[b]=a,cnxt[b]=chead[a],chead[a]=b;
	}
	REP(i,n) scanf("%d",&want[i]),--want[i];
	REP(i,n) wnxt[i]=whead[want[i]],whead[want[i]]=i;
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",nret); REP(i,nret) printf("%d\n",ret[i]+1);
}

int main() {
	run();
	return 0;
}