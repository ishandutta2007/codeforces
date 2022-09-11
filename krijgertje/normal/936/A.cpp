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

ll ton,tneed,tcheck;

void run() {
	scanf("%lld%lld%lld",&ton,&tcheck,&tneed);

	ll tper=(ton+tcheck-1)/tcheck*tcheck;
	//printf("tper=%lld\n",tper);
	double ret=0;
	ll rem=2*tneed;
	{ ll cur=rem/(ton+tper); rem%=ton+tper; ret+=1.0*cur*tper; }
	{ ll cur=min(2*ton,rem); rem-=cur; ret+=0.5*cur; }
	{ ll cur=min(tper-ton,rem); rem-=cur; ret+=1.0*cur; }
	assert(rem==0);
	printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}