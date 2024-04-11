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

ll n;

ll calc(ll k) {
	ll ret=0,rem=n;
	while(rem>0) {
		ll a=min(rem,k); ret+=a; rem-=a;
		ll b=rem/10; rem-=b;
	}
	return ret;
}

void run() {
	scanf("%lld",&n);
	ll l=0,h=n;
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(2*calc(m)>=n) h=m; else l=m;
	}
	printf("%lld\n",h);
}

int main() {
	run();
	return 0;
}