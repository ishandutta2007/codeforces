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

struct E { int a, b, c; E() {} E(int a, int b, int c) :a(a), b(b), c(c) {} };

int l, r;

int n;
vector<E> e;

void solve() {
	vector<int> a;
	vector<int> b;
	int len = r - l + 1;
	int rem = len;
	int k = 0;
	--rem;
	while ((1 << k) <= rem) rem -= 1 << k, a.PB(k), ++k;
	while (k >= 0) { if ((1 << k) <= rem) rem -= 1 << k, b.PB(k); --k; }
	int nseg = SZ(a) == 0 ? 0 : a.back() + 1;

	n = 0;
	int s = n++;
	vector<int> seg(nseg); REP(i, nseg) seg[i] = n++;
	int p = n++;
	int q = n++;

	e.clear();
	REP(i, nseg) { e.PB(E(s, seg[i], 1 << i));  REP(j, i) e.PB(E(seg[j], seg[i], 1 << i)); }
	e.PB(E(p, q, 1));
	int nxt = l;
	e.PB(E(s, q, nxt - 0)), ++nxt;
	for (int i : a) e.PB(E(seg[i], q, nxt - (1 << i))), nxt += 1 << i;
	for (int i : b) e.PB(E(seg[i], p, nxt - (1 << i) - 1)), nxt += 1 << i;
}

void run() {
	scanf("%d%d", &l, &r);
	solve();
	printf("YES\n");
	printf("%d %d\n", n, SZ(e));
	REPSZ(i, e) printf("%d %d %d\n", e[i].a + 1, e[i].b + 1, e[i].c);
}

int main() {
	run();
	return 0;
}