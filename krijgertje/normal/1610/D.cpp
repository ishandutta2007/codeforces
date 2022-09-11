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
const int MOD = 1000000007;

int n;
int a[MAXN];

int p2[MAXN + 1];

int solve() {
	p2[0] = 1; FORE(i, 1, n) p2[i] = (ll)p2[i - 1] * 2 % MOD;
	int all = (p2[n] + MOD - 1) % MOD;
	int invalid = 0;
	for (int bit = 1;; ++bit) {
		int odd = 0, evn = 0;
		REP(i, n) if (a[i] % (1 << bit) == 0) {
			int x = a[i] / (1 << bit);
			if (x % 2 == 1) ++odd; else ++evn;
		}
		if (odd + evn == 0) break;
		if (odd == 0) continue;
		invalid = (invalid + p2[odd + evn - 1]) % MOD;
	}
	return (all + MOD - invalid) % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

void research() {
	int lim = 100;
	FORE(a, 1, lim) FORE(b, a, lim) FORE(c, b, lim) FORE(d, c, lim) {
		int sum = 0;
		if (a % 2 == 0) sum += a / 2;
		if (b % 2 == 0) sum += b / 2;
		if (c % 2 == 0) sum += c / 2;
		if (d % 2 == 0) sum += d / 2;
		int g = gcd(a, gcd(b, gcd(c, d)));
		int k = 0;
		while (a % (2 << k) == 0 && b % (2 << k) == 0 && c % (2 << k) == 0 && d % (2 << k) == 0) ++k;
		if (sum % (1 << k) != 0) assert(sum % g != 0);
		if (sum % g != 0 && sum % (1 << k) == 0) printf("%d %d %d %d [%d]\n", a, b, c, d, k);
	}
}

int main() {
	//research();
	run();
	return 0;
}