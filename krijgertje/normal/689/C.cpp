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

ll ways;
ll calc(ll n) {
	ll ret=0;
	for(ll k=2;;++k) {
		ll cur=n/(k*k*k); if(cur==0) break; else ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%lld",&ways);
	ll l=0,h=8*ways; // (l,h] 
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(calc(m)>=ways) h=m; else l=m;
	}
	printf("%lld\n",calc(h)==ways?h:(ll)-1);
}

int main() {
	run();
	return 0;
}