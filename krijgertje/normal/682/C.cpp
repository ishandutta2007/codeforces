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

int n;
int val[MAXN];
int thead[MAXN],tnxt[MAXN],upval[MAXN],par[MAXN],nchild[MAXN];
int q[MAXN],qhead,qtail;
bool rem[MAXN]; int mx[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) thead[i]=-1,nchild[i]=0;
	tnxt[0]=par[0]=-1; upval[0]=0;
	FOR(i,1,n) {
		scanf("%d%d",&par[i],&upval[i]); --par[i];
		tnxt[i]=thead[par[i]]; thead[par[i]]=i; ++nchild[par[i]];
	}
	REP(i,n) rem[i]=false,mx[i]=0;
	qhead=qtail=0; q[qhead++]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		if(val[at]<mx[at]) rem[at]=true;
		//printf("%d = %d (%d) %c\n",at,mx[at],val[at],rem[at]?'!':'.');
		for(int to=thead[at];to!=-1;to=tnxt[to]) {
			if(upval[to]+mx[at]>mx[to]) mx[to]=upval[to]+mx[at];
			if(rem[at]) rem[to]=true;
			q[qhead++]=to;
		}
	}
	int ret=0; REP(i,n) if(rem[i]) ++ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}