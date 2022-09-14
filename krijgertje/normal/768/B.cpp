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
ll l,r;

ll calc(ll n,ll r) {
	int bit=1; while(n>=(1LL<<bit)) ++bit;
	ll cntlft=(1LL<<(bit-1))-1;
	ll ret=0;
	if(r<cntlft) return calc(n/2,r); else ret+=n/2;
	if(r>=cntlft) ret+=n%2;
	if(r>cntlft) ret+=calc(n/2,r-cntlft-1);
	return ret;	
}

void run() {
	scanf("%lld%lld%lld",&n,&l,&r); --l,--r;
	ll ret=calc(n,r); if(n,l!=0) ret-=calc(n,l-1);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}