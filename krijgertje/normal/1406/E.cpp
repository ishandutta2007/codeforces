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

const int MAXN = 100000;

int n;

vector<bool> isprime;
vector<int> psmall, plarge;

vector<bool> expectalive; int nexpectalive;


int query(int x) {
	if (x > n) return 0;
	printf("A %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

int kill(int x) {
	for (int i = x; i <= n; i += x) if (expectalive[i]) expectalive[i] = false, --nexpectalive;
	if (x > n) return 0;
	printf("B %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

int solve() {
	isprime = vector<bool>(n + 1, true); isprime[0] = isprime[1] = false;
	FORE(i, 2, n) if (isprime[i]) for (int j = i + i; j <= n; j += i) isprime[j] = false;
	psmall.clear(), plarge.clear(); REPE(i, n) if (isprime[i]) if ((ll)i * i <= n) psmall.PB(i); else plarge.PB(i);

	expectalive = vector<bool>(n + 1, true); expectalive[0] = false; nexpectalive = n;
	int ans = 1;
	for (int l = 0, r = l; l < SZ(plarge); l = r) {
		r = min(l + 100, SZ(plarge));
		FOR(i, l, r) kill(plarge[i]);
		int nactualalive = query(1);
		if (nactualalive != nexpectalive) {
			assert(nactualalive == nexpectalive + 1);
			assert(ans == 1);
			++nexpectalive;
			FOR(i, l, r) {
				int x = plarge[i];
				int cur = query(x);
				if (cur == 0) continue;
				assert(cur == 1);
				assert(ans == 1);
				ans *= x;
			}
			assert(ans != 1);
		}
	}
	REPSZ(i, psmall) {
		int x = psmall[i];
		kill(x);
		int y = 1;
		while (true) {
			int cur = query(y * x);
			if (cur == 0) break;
			assert(cur == 1);
			y *= x;
		}
		ans *= y;
	}
	return ans;
}

void run() {
	scanf("%d", &n);
	int ans = solve();
	printf("C %d\n", ans); fflush(stdout);
}

int main() {
	run();
	return 0;
}