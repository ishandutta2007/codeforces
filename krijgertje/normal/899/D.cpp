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

int n;

bool cansum(ll x) { return x>=3&&x<=n+n-1; }
ll wayssum(ll x) { 
	if(x<3||x>n+n-1) return 0;
	// a+b=x 1<=a<=b<=n
	ll mna=max(1LL,x-n),mxa=min((x-1)/2,(ll)n);
	return mxa-mna+1;
}

void run() {
	scanf("%d",&n);
	ll suff=0;
	while(cansum(10*suff+9)) suff=10*suff+9;
	ll ret=0;
	ret+=wayssum(suff);
	FORE(i,1,8) ret+=wayssum(i*(suff+1)+suff);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}