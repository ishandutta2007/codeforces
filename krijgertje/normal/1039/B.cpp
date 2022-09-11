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

ll n; int sz;

bool query(ll l,ll r) {
	printf("%lld %lld\n",l,r); fflush(stdout);
	char buff[10]; scanf("%s",buff); if(strcmp(buff,"Bad")==0) exit(0); if(strcmp(buff,"Yes")==0) return true; else return false;
}

void run() {
	srand(12373);
	scanf("%lld%d",&n,&sz);
	ll l=1,h=n;
	while(true) {
		ll len=h-l+1;
		if(len>6*sz) {
			ll m=l+(h-l)/2;
			if(query(l,m)) {
				if(l==m) break;
				h=m;
			} else {
				l=m+1;
			}
		} else {
			ll x=l+rand()%len;
			if(query(x,x)) break;
		}
		l=max(1LL,l-sz),h=min((ll)n,h+sz);
	}
}

int main() {
	run();
	return 0;
}