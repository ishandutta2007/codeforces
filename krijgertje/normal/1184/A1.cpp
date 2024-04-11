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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

ll r;
ll ansx,ansy;

bool solve() {
	for(ll x=1;x*x+x+1<=r;++x) {
		ll rem=r-x*x-x-1;
		if(rem%(2*x)!=0) continue;
		ll y=rem/(2*x);
		if(y<=0) continue;
		ansx=x,ansy=y; return true;
	}
	return false;
}

void run() {
	scanf("%lld",&r);
	if(!solve()) { printf("NO\n"); return; }
	printf("%lld %lld\n",ansx,ansy);
}

int main() {
	run();
	return 0;
}