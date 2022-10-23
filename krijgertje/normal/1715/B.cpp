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

const int MAXN = 100000;

int n, den, wantbeauty; ll wantsum;
ll ans[MAXN];

bool solve() {
	ll basesum = (ll)wantbeauty * den;
	ll remsum = wantsum - basesum;
	if (remsum<0 || remsum>(ll)(den - 1) * n) return false;
	REP(i, n) ans[i] = 0;
	ans[0] = basesum;
	REP(i, n) { ll delta = min((ll)(den - 1), remsum); ans[i] += delta; remsum -= delta; }
	assert(remsum == 0);
	return true;
}

void run() {
	scanf("%d%d%d%lld", &n, &den, &wantbeauty, &wantsum);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}