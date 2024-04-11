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

bool solve(ll p,ll q,ll b) {
	ll g=gcd(p,q); p/=g; q/=g;
	while(true) {
		g=gcd(q,b);
		//printf("q=%lld b=%lld g=%lld\n",q,b,g);
		if(g==1) break;
		while(q%g==0) q/=g;
	}
	return q==1;
}

void run() {
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		ll p,q,b; scanf("%lld%lld%lld",&p,&q,&b);
		printf("%s\n",solve(p,q,b)?"Finite":"Infinite");
	}
}

int main() {
	run();
	return 0;
}