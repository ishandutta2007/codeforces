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

const int MAXN=45;
const int MAXSUB=45;

int n,nsub,budget;
int cost[MAXSUB],sumcost=0;

void run() {
	scanf("%d%d%d",&n,&nsub,&budget); REP(i,nsub) scanf("%d",&cost[i]); sort(cost,cost+nsub); sumcost=0; REP(i,nsub) sumcost+=cost[i];
	int ret=0;
	REPE(i,n) {
		if(i*sumcost>budget) continue;
		int left=budget-i*sumcost;
		int cur=(nsub+1)*i;
		REP(j,nsub) { int now=min(left/cost[j],n-i); cur+=now; left-=now*cost[j]; }
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}