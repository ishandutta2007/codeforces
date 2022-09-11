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

int n;
string s;

ll solve() {
	string z = s;
	if (z[0] == 'D') REPSZ(i, z) if (z[i] == 'D') z[i] = 'R'; else if (z[i] == 'R') z[i] = 'D'; else assert(false);
	int h = 1, w = 1;
	REPSZ(i, z) if (z[i] == 'D') ++h; else if (z[i] == 'R') ++w; else assert(false);
	assert(h <= n && w <= n);
	ll ret = 0;
	int pref = 0;
	while (pref < SZ(z) && z[pref] == 'R') ++pref;
	int rmx = n - w, dmx = n - h;
	ret += pref + 1 + rmx;
	//printf("pref=%d rmx=%d w=%d n=%d\n", pref, rmx, w, n);
	if (pref < SZ(z)) {
		ret += (ll)(rmx + 1) * (dmx + 1);
		FORSZ(i, pref + 1, z) if (z[i] == 'R') ret += dmx + 1; else if (z[i] == 'D') ret += rmx + 1; else assert(false);
	}
	return ret;
}

void run() {
	cin >> n >> s;
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}