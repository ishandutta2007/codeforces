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

int n; ll have;
int x[MAXN];
ll y[MAXN];

bool can(int k,ll &cost) {
	REP(i,n) y[i]=x[i]+(ll)(i+1)*k;
	sort(y,y+n);
	//printf("%d:",k); REP(i,n) printf(" %lld",y[i]); puts("");
	ll need=0; REP(i,k) { need+=y[i]; if(have<need) return false; } cost=need; return true;
}

void run() {
	scanf("%d%lld",&n,&have);
	REP(i,n) scanf("%d",&x[i]);
	int l=0,h=n+1; ll cost;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m,cost)) l=m; else h=m;
	}
	assert(can(l,cost));
	printf("%d %lld\n",l,cost);

}

int main() {
	run();
	return 0;
}