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

const int MAXN = 100000;

int n, zerogain, onegain, remcost;
char s[MAXN + 1];

ll solve() {
	int freezero = 0, freeone = 0, uselesszero = 0;
	vector<int> gap;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && s[r] == s[l]) ++r;
		int cnt = r - l;
		if (s[l] == '0') {
			freezero += cnt - 1;
			if (l == 0 || r == n) ++uselesszero; else gap.PB(cnt);
		} else {
			freeone += cnt - 1;
		}
	}
	sort(gap.begin(), gap.end());
	vector<int> gapsum(SZ(gap) + 1); gapsum[0] = 0; REPSZ(i, gap) gapsum[i + 1] = gapsum[i] + gap[i];

	ll ret = 0;
	if (freezero > 0) ret = max(ret, (ll)zerogain);
	REP(first, 2) {
		FORE(one, 1, freeone + SZ(gap)) {
			int usegap = max(0, one - freeone);
			int needzero = gapsum[usegap];
			if (needzero > one - first) continue;
			if (freezero + SZ(gap) + uselesszero < one - first) continue;
			ll cur = (ll)onegain * one;
			int rem = one - first;
			int remfreezero = freezero;
			cur += (ll)zerogain * (needzero - usegap) - (ll)remcost * usegap;
			rem -= needzero;
			remfreezero -= needzero - usegap;
			int take = min(rem, remfreezero);
			cur += (ll)zerogain * take;
			rem -= take;
			remfreezero -= take;
			cur -= (ll)remcost * rem;
			if (remfreezero > 0) cur += zerogain;
			ret = max(ret, cur);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d", &n, &zerogain, &onegain, &remcost);
	scanf("%s", s);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}