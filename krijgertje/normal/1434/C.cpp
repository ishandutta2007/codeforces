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

int damage, healpoints, healcnt, cooldown;


ll solve() {
	if (damage > (ll)healpoints* healcnt) return -1;
	if (cooldown > healcnt) return damage;
	ll ret = 0;

	//int mxheal = damage / healpoints;

	//ret = max(ret, damage + (ll)i * (damage - (ll)cooldown * healpoints) - (ll)i * (i - 1) / 2 * cooldown * healpoints);

	int iopt = min((ll)healcnt / cooldown, damage / ((ll)cooldown * healpoints));
	return damage + (ll)iopt * (damage - (ll)cooldown * healpoints) - (ll)iopt * (iopt - 1) / 2 * cooldown * healpoints;


	
	for (int i = 0; i < (healcnt + 1) / cooldown; ++i) {
		ret = max(ret, damage + (ll)i * (damage - (ll)cooldown * healpoints) - (ll)i * (i - 1) / 2 * cooldown * healpoints);
		ll expect = (damage - (ll)cooldown * healpoints) - (i * cooldown * healpoints);
		ll actual = (damage + (ll)(i+1) * (damage - (ll)cooldown * healpoints) - (ll)i * (i + 1) / 2 * cooldown * healpoints) - (damage + (ll)i * (damage - (ll)cooldown * healpoints) - (ll)i * (i - 1) / 2 * cooldown * healpoints);
		assert(actual == expect);

		//ret = max(ret, (ll)(i + 1) * damage - (ll)i * (cooldown - 1) * healpoints - (ll)i * healpoints - (ll)i * (i - 1) / 2 * cooldown * healpoints);
		//if ((ll)(i + 1) * damage - (ll)(i + 1) * (cooldown - 1) * healpoints - (ll)i * (i + 1) / 2 * cooldown * healpoints < 0) break;
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d", &damage, &healpoints, &healcnt, &cooldown);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}