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

const int MAXN=30;

int n,want;
int c[MAXN];


void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&c[i]);
	FOR(i,1,n) c[i]=min(c[i],2*c[i-1]);
	ll ret=LLONG_MAX;
	REP(i,n) {
		int a=1<<i;
		int cwant=(want+a-1)/a*a;
		ll cur=0;
		REP(j,n-1) if(cwant&(1<<j)) cur+=c[j],cwant-=(1<<j);
		int left=cwant/(1<<(n-1)); cur+=(ll)left*c[n-1];
		ret=min(ret,cur);
		//printf("%d -> %d: %lld\n",i,cwant,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}