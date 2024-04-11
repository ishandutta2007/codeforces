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


ll calc(int n,ll mx) {
	if(n<=mx) return (ll)n*(mx+mx-n+1)/2;
	return mx*(mx+1)/2+n-mx;
}

int n,have,me;

bool can(ll x) {
	int nlft=me,nrgt=n-me-1;
	ll need=calc(nlft+1,x)+calc(nrgt+1,x)-x;
	//printf("%lld -> %lld\n",x,need);
	return need<=have;
}

void run() {
	scanf("%d%d%d",&n,&have,&me); --me;
	ll l=1,h=2; while(can(h)) l=h,h+=h;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) l=m; else h=m;
	}
	printf("%lld\n",l);
}

int main() {
	run();
	return 0;
}