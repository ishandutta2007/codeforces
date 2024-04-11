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

const int MAXN = 1000000;

int n;
ll a[MAXN];
ll ans[MAXN];

void solve() {
	ll sum = 0; REP(i, n) sum += a[i];
	ll tri = 0; REP(i, n) tri += i;
	assert(sum >= tri);
	ll shift = (sum - tri) / n;
	int offset = (sum - tri) % n;
	REP(i, n) ans[i] = shift + i + (i < offset ? 1 : 0);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}