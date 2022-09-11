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

const int MAXVAL = 1000000;
const int MAXN = 200000;

bool isprime[MAXVAL + 1];

int n, step;
int a[MAXN];



ll solve() {
	ll ret = 0;
	REP(offset, step) {
		for (int i = offset; i < n; i += step) {
			if (isprime[a[i]]) {
				int l = 0, r = 0;
				while (i - (l + 1) * step >= 0 && a[i - (l + 1) * step] == 1) ++l;
				while (i + (r + 1) * step < n && a[i + (r + 1) * step] == 1) ++r;
				ret += (ll)(l + 1) * (r + 1) - 1;
				//printf("%d: %d / %d\n", i, l, r);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &step);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	REPE(i, MAXVAL) isprime[i] = i >= 2;
	REPE(i, MAXVAL) if (isprime[i]) for (int j = i + i; j <= MAXVAL; j += i) isprime[j] = false;
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}