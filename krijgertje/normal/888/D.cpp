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

const int MAXN=1000;

int n,mxdiff;

void run() {
	scanf("%d%d",&n,&mxdiff);
	ll ret=0;
	REPE(ndiff,mxdiff) {
		if(ndiff==0) ret+=1;
		if(ndiff==2) ret+=(ll)n*(n-1)/2;
		if(ndiff==3) ret+=((ll)n*(n-1)*(n-2)/6)*2;
		if(ndiff==4) ret+=((ll)n*(n-1)*(n-2)*(n-3)/24)*(3+6);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}