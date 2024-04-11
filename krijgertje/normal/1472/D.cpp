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

const int MAXN = 200000;

int n;
int a[MAXN];

ll solve() {
	sort(a, a + n);
	reverse(a, a + n);
	ll start = 0;
	REP(i, n) if (a[i] % 2 == 0) start += a[i]; else start -= a[i];
	ll ret = start;
	REP(i, n) if (i % 2 == 0) ret += a[i]; else ret -= a[i];
	assert(ret % 2 == 0);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	ll res = solve();
	printf("%s\n", res > 0 ? "Alice" : res < 0 ? "Bob" : "Tie");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)  run();
	return 0;
}