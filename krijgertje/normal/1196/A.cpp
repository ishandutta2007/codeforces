#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

ll a[3];

ll solve() {
	ll ret=0;
	REP(i,3) REP(j,3) if(j!=i) {
		ll x=a[i],y=a[j],mn=min(x,y),d=abs(x-y),rem=a[0]+a[1]+a[2]-x-y;
		ll cur=rem<=d?mn+rem:mn+d+(rem-d)/2;
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	REP(i,3) scanf("%lld",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}