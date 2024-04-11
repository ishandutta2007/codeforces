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

const int MAXN=200000;

int n;
int x[MAXN];

int state[MAXN];

int ret[MAXN],nret,root;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]),--x[i];
	REP(i,n) state[i]=0;
	nret=0,root=-1;
	REP(i,n) if(state[i]==0) {
		int at=i; while(state[at]==0) { state[at]=1; at=x[at]; }
		//printf("%d->%d (%d)\n",i+1,at+1,state[at]);
		if(state[at]!=2) { ret[nret++]=at; if(x[at]==at&&root==-1) root=at; }
		at=i; while(state[at]==1) { state[at]=2; at=x[at]; }
	}
	printf("%d\n",nret-1+(root==-1?1:0));
	if(root==-1) root=ret[nret-1],x[root]=root;
	REP(i,nret) if(ret[i]!=root) x[ret[i]]=root;
	REP(i,n) { if(i!=0) printf(" "); printf("%d",x[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}