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

const int MAGIC=1000;

ll n,s;
int sod(ll x) { int ret=0; while(x>0) ret+=x%10,x/=10; return ret; }

void run() {
	scanf("%lld%lld",&n,&s);
	ll ret=0;
	REP(i,MAGIC) {
		ll x=s+i; if(x>n) break;
		if(x-sod(x)>=s) ++ret;
	}
	if(s+MAGIC<=n) ret+=n-(s+MAGIC)+1;
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}