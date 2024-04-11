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


ll solve(ll n,ll want) {
	// a+b=want, 1<=a<b<=n
	ll ret=0;
	ret+=(want-1)/2;
	//printf("%lld\n",ret);
	if(n<want) ret-=(want-1)-max(n+1,want-n)+1;
	//printf("%lld\n",ret);
	if(2*n<want) ret-=(want-2*n-1)/2;
	//printf("%lld\n",ret);
	return ret;
}

void run() {
	ll n,want;
	scanf("%lld%lld",&n,&want);
	printf("%lld\n",solve(n,want));
}

ll bfsolve(ll n,ll want) {
	ll ret=0; for(ll a=1;a<=n;++a) { ll b=want-a; if(a<b&&1<=b&&b<=n) ++ret; } return ret;
}

void stress() {
	REP(rep,100000) {
		ll n=rand()%1000+1,tgt=rand()%1000+1;
		ll have=solve(n,tgt);
		ll want=bfsolve(n,tgt);
		if(have==want) { printf("."); continue; }
		printf("err: %lld %lld -> have=%lld want=%lld\n",n,tgt,have,want);
	}
}

int main() {
	run();
	//stress();
	return 0;
}