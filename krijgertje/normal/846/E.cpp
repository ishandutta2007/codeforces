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
const ll MAXHAVE=1000000000000LL;
const ll MAXCANHAVE=MAXN*MAXHAVE;

int n;
ll have[MAXN],want[MAXN];

int par[MAXN],cost[MAXN];

bool solve() {
	for(int i=n-1;i>=1;--i) {
		//printf("%d: have=%lld want=%lld par=%d cost=%d\n",i+1,have[i],want[i],par[i]+1,cost[i]);
		if(have[i]>=want[i]) { ll diff=have[i]-want[i]; have[par[i]]+=diff; continue; }
		ll need=want[i]-have[i];
		if(need>MAXCANHAVE/cost[i]) return false;
		want[par[i]]+=need*cost[i]; if(want[par[i]]>MAXCANHAVE) return false;
	}
	return have[0]>=want[0];
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&have[i]); REP(i,n) scanf("%lld",&want[i]);
	par[0]=-1,cost[0]=0; FOR(i,1,n) scanf("%d%d",&par[i],&cost[i]),--par[i];
	printf("%s\n",solve()?"YES":"NO");	
}

int main() {
	run();
	return 0;
}