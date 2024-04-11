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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int n; double pknow;

ll choose(int a,int b) { ll ret=1; REP(i,b) ret*=a-i,ret/=i+1; return ret; }

int solve() {
	// know 3 -> ok, know 2 -> ok, know 1 -> 50%, know 0 -> bad
	REPE(i,n) {
		int j=n-i;
		ll num=2*choose(i,3)+2*choose(i,2)*choose(j,1)+1*choose(i,1)*choose(j,2);
		ll den=2*choose(n,3);
		//printf("%d: %lld/%lld\n",i,num,den);
		if(num>=pknow*den-(1e-12)) return i;
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%lf",&n,&pknow);
	printf("%d\n",solve());
}


int main() {
	run();
	return 0;
}