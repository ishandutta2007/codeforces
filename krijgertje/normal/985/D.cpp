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

ll have,lim0;

void run() {
	scanf("%lld%lld",&have,&lim0);

	ll l=1,h=1500000000,ret=LLONG_MAX;
	while(l<=h) {
		ll m=l+(h-l)/2;
		ll a=m*(m+1)/2;
		ll b=m<=lim0?0:(lim0+m-1)*(m-1-lim0+1)/2;
		ll need=a+b;
		//printf("%lld -> %lld\n",m,need);
		if(have>=need) {
			ll extra=have-need;
			ll cur=m+(m<=lim0?0:m-1-lim0+1)+(extra+m-1)/m;
			ret=min(ret,cur);
		}
		if(need>have) h=m-1; else l=m+1;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}