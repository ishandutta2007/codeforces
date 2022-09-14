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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;
int d[1<<16],s[1<<16];

int q[1<<16],qhead,qtail;

int ret[1<<16][2],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d %d",&d[i],&s[i]);

	nret=0;
	qhead=qtail=0; REP(i,n) if(d[i]==1) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++]; if(d[at]!=1) continue;
		int to=s[at];
		ret[nret][0]=at; ret[nret][1]=to; ++nret;
		s[at]^=to; if(--d[at]==1) q[qhead++]=at;
		s[to]^=at; if(--d[to]==1) q[qhead++]=to;
	}

	printf("%d\n",nret); REP(i,nret) printf("%d %d\n",ret[i][0],ret[i][1]);
}

int main() {
	run();
	return 0;
}