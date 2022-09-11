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

int x, d;

bool iscomposite(int a) {
	if (a <= 1) return false;
	for (int i = 2; (ll)i * i <= a; ++i) if (a % i == 0) return true;
	return false;
}

bool solve() {
	int cnt = 0;
	int rem = x;
	while (rem % d == 0) rem /= d, ++cnt;
	assert(cnt >= 1);
	if (cnt == 1) return false;
	if (iscomposite(rem)) return true;
	if (cnt == 2) return false;
	if (!iscomposite(d)) return false;
	if (cnt >= 4) return true;
	if (rem == 1) return true;
	return (ll)rem * rem != d;
}

void run() {
	scanf("%d%d", &x, &d);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}