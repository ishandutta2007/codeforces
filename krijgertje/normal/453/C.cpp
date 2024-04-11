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

int n,m;
int lst[100000];
int prv[200000];
int to[200000];

int want[100000];
int have[100000];
bool been[100000];

int ret[400000],nret;

void go(int at,int par) {
	assert(!been[at]); been[at]=true;
	have[at]=1-have[at]; ret[nret++]=at;
	for(int x=lst[at];x!=-1;x=prv[x]) if(!been[to[x]]) go(to[x],at);
	if(have[at]!=want[at]) {
		if(par!=-1) {
			have[par]=1-have[par]; ret[nret++]=par;
			have[at]=1-have[at]; ret[nret++]=at;
		} else if(lst[at]!=-1) {
			int child=to[lst[at]];
			have[child]=1-have[child]; ret[nret++]=child;
			have[at]=1-have[at]; ret[nret++]=at;
			have[child]=1-have[child]; ret[nret++]=child;
		}
	}
	if(par!=-1) {
		have[par]=1-have[par]; ret[nret++]=par;
	}
}

void run() {
	scanf("%d%d",&n,&m);
	memset(lst,-1,sizeof(lst));
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		prv[2*i+0]=lst[a]; to[2*i+0]=b; lst[a]=2*i+0;
		prv[2*i+1]=lst[b]; to[2*i+1]=a; lst[b]=2*i+1;
	}
	memset(have,0,sizeof(have));
	REP(i,n) scanf("%d",&want[i]);

	REP(i,n) if(want[i]==1) {
		memset(been,false,sizeof(been)); nret=0;
		go(i,-1);
		REP(j,n) if(have[j]!=want[j]) { printf("%d\n",-1); return; }
		printf("%d\n",nret); REP(j,nret) { if(j!=0) printf(" "); printf("%d",ret[j]+1); } puts("");
		return;
	}
	printf("%d\n\n",0);
}


int main() {
	run();
	return 0;
}