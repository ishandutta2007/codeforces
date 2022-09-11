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

ll nstud, nlect, sza, szb, need;

ll solve() {
	if (need > nlect) return 0;
	ll na = (nlect + 1) / 2, nb = nlect - na;
	if (sza < szb) swap(sza, szb), swap(na, nb);
	//printf("nstud=%lld na=%lld sza=%lld nb=%lld szb=%lld need=%lld\n", nstud, na, sza, nb, szb, need);
	ll ret = (na*sza + nb*szb) / need;
	if (na < need) {
		ll useb = need - na;
		ret = min(ret, nb * szb / useb);
	}
	return min(nstud, ret);
}

void run() {
	scanf("%lld%lld%lld%lld%lld", &nstud, &nlect, &sza, &szb, &need);
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}