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

int a, b, k;

bool solve() {
	vector<int> primes;
	{ int x = a; for (int i = 2; i * i <= x; ++i) if (x % i == 0) { primes.PB(i); while (x % i == 0) x /= i; } if (x != 1) primes.PB(x); }
	{ int x = b; for (int i = 2; i * i <= x; ++i) if (x % i == 0) { primes.PB(i); while (x % i == 0) x /= i; } if (x != 1) primes.PB(x); }
	sort(primes.begin(), primes.end());
	primes.erase(unique(primes.begin(), primes.end()), primes.end());
	bool needa = false;
	bool needb = false;
	int lim = 0;
	for (int p : primes) {
		int aa = 0, bb = 0;
		{ int x = a; while (x % p == 0) x /= p, ++aa; }
		{ int x = b; while (x % p == 0) x /= p, ++bb; }
		if (aa > bb) needa = true;
		if (bb > aa) needb = true;
		lim += aa + bb;
	}
	int need = (needa ? 1 : 0) + (needb ? 1 : 0);
	if (k < need) return false;
	if (k > lim) return false;
	if (k == 1 && a == b) return false;
	return true;
}

void run() {
	scanf("%d%d%d", &a, &b, &k);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}