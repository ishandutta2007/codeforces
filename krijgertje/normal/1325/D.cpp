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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

ll sumxor, sumreg;
ll ans[3]; int nans;

bool solve() {
	if (sumxor > sumreg) return false;
	if ((sumxor & 1) != (sumreg & 1)) return false;
	nans = 0;
	if (sumxor == 0 && sumreg == 0) { return true; }
	if (sumxor == sumreg) { ans[nans++] = sumxor; return true; }
	ll diff = sumreg - sumxor; assert(diff % 2 == 0);
	ll half = diff / 2;
	if ((half & sumxor) == 0) { ans[nans++] = half, ans[nans++] = half ^ sumxor; return true; }
	ans[nans++] = sumxor; ans[nans++] = half; ans[nans++] = half; return true;
}

void run() {
	scanf("%lld%lld", &sumxor, &sumreg);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", nans);
	REP(i, nans) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}