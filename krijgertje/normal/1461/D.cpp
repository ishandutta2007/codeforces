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

const int MAXQ = 100000;

int n, nq;
vector<int> a;
ll qwant[MAXQ]; bool qcan[MAXQ];

set<ll> opt;

void rec(const vector<int>& a) {
	assert(SZ(a) >= 1);
	int lo = a[0], hi = a[0]; ll sum = a[0]; FORSZ(i, 1, a) lo = min(lo, a[i]), hi = max(hi, a[i]), sum += a[i];
	opt.insert(sum);
	if (lo == hi) return;
	int mi = (lo + hi) / 2;
	vector<int> al, ar;
	REPSZ(i, a) if (a[i] <= mi) al.PB(a[i]); else ar.PB(a[i]);
	rec(al);
	rec(ar);
}

void solve() {
	opt.clear();
	rec(a);
	REP(i, nq) qcan[i] = opt.count(qwant[i]) != 0;
}

void run() {
	scanf("%d%d", &n, &nq);
	a = vector<int>(n); REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%lld", &qwant[i]);
	solve();
	REP(i, nq) printf("%s\n", qcan[i] ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}