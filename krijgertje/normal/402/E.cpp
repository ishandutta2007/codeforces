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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n;
int a[2000][2000];

int state[2000],idx[2000],low[2000],nidx;
int stack[2000],nstack;
int comp[2000],ncomp;

void tarjan(int at) {
	state[at]=1; idx[at]=low[at]=nidx++;
	stack[nstack++]=at;
	REP(to,n) if(a[at][to]>0) {
		if(state[to]==2) continue;
		if(state[to]==0) tarjan(to);
		low[at]=min(low[at],low[to]);
	}
	if(idx[at]==low[at]) {
		while(state[at]==1) {
			int cur=stack[--nstack];
			state[cur]=2; comp[cur]=ncomp;
		}
		++ncomp;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]);

	nidx=nstack=ncomp=0; memset(state,0,sizeof(state));
	REP(i,n) if(state[i]==0) tarjan(i);
//	REP(i,n) printf("%d ",comp[i]); puts(""); printf("->%d\n",ncomp);

	printf("%s\n",ncomp==1?"YES":"NO");
}


int main() {
	run();
	return 0;
}