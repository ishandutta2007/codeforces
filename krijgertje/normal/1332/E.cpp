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

const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
int pw(int x, ll n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

int h, w, mnval, mxval;

int solve() {
	int nval = mxval - mnval + 1;
	if (h % 2 == 1 && w % 2 == 1) return pw(nval, (ll)h * w);
	if (nval % 2 == 0) return (ll)pw(nval, (ll)h * w) * INV2 % MOD;
	else return (ll)(pw(nval, (ll)h * w) + 1) * INV2 % MOD;
}

void run() {
	scanf("%d%d%d%d", &h, &w, &mnval, &mxval);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}