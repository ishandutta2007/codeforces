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

ll cap;
ll gain;

ll calc(ll x) {
	ll ret=0;
	if(x>=LLONG_MAX/x) return LLONG_MAX; else ret+=x*x;
	if(ret>=LLONG_MAX-x) return LLONG_MAX; else ret+=x;
	return ret;
}

ll solve() {
	if(gain>=cap) return cap;
	ll cur=cap-gain;
	// 1+2+...+x=(1+x)*x/2>=cur ->x*x+x-2*cur>=0
	ll l=0,h=1; while(calc(h)<2*cur) l=h,h+=h; while(l+1<h) { ll m=l+(h-l)/2; if(calc(m)<2*cur) l=m; else h=m; }
	return gain+h;
}

void run() {
	scanf("%lld%lld",&cap,&gain);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}