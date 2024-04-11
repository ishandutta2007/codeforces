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
#include <functional>
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

int n, lim;
int x[MAXN];

ll solve() {
	vector<int> a, b;
	REP(i, n) if (x[i] > 0) a.PB(x[i]); else b.PB(-x[i]);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ret = 0;
	for (int i = SZ(a) - 1; i >= 0; i -= lim) ret += (ll)2 * a[i];
	for (int i = SZ(b) - 1; i >= 0; i -= lim) ret += (ll)2 * b[i];
	int sub = 0;
	if (SZ(a) != 0) sub = max(sub, a[SZ(a) - 1]);
	if (SZ(b) != 0) sub = max(sub, b[SZ(b) - 1]);
	ret -= sub;
	return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &x[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}