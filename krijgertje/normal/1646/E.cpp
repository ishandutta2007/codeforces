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

int nrow, ncol;

ll solve() {
	vector<ll> mem;
	auto calc = [&](int k) {
		while (k >= SZ(mem)) mem.PB(-1);
		ll &ret = mem[k];
		if (ret == -1) {
			ret = 0;
			FOR(mask, 1, 1 << k) {
				ll lcm = 1; int cnt = 0; int small = -1;
				REP(i, k) if (mask & (1 << i)) {
					if (small == -1) small = i + 1;
					lcm = lcm / gcd(lcm, i + 1) * (i + 1);
					++cnt;
				}
				assert(small != -1);
				ll lim = (ll)small * ncol / lcm;
				if (cnt % 2 == 1) ret += lim; else ret -= lim;
			}
		}
		return ret;
	};

	ll ret = 0;
	vector<bool> used(nrow + 1, false);
	++ret, used[1] = true;
	for (int x = 2; x <= nrow; ++x) {
		if (used[x]) continue;
		ll y = 1; int k = 0;
		while (y * x <= nrow) {
			y *= x, ++k;
			assert(!used[y]);
			used[y] = true;
		}
		//printf("x=%d -> k=%d\n", x, k);
		ret += calc(k);
	}
	return ret;
}

void run() {
	scanf("%d%d", &nrow, &ncol);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}