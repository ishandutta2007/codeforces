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

int n;

bool solve() {
	if (n == 1) return false;
	if (n % 2 == 1) return true;
	int a = 1, b = n; while (b % 2 == 0) a *= 2, b /= 2; // a is a power of 2, b is odd
	if (b == 1) return a == 2;
	if (a >= 4) return true;
	vector<int> p; int x = b; for (int i = 2; (ll)i * i <= x; ++i) while (x % i == 0) p.PB(i), x /= i; if (x != 1) p.PB(x);
	if (SZ(p) == 1) return false;
	return true;
}

void run() {
	scanf("%d", &n);
	printf("%s\n", solve() ? "Ashishgup" : "FastestFinger");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}