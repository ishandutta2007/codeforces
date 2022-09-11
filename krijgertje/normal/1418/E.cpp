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

const int MAXMONSTER = 200000;
const int MAXSHIELD = 200000;
const int MOD = 998244353;

int nmonster, nshield;
int str[MAXMONSTER];
int dur[MAXSHIELD], def[MAXSHIELD], ans[MAXSHIELD];

int sumstr[MAXMONSTER + 1];
int inv[MAXMONSTER + 2];

void solve() {
	inv[1] = 1; FORE(i, 2, nmonster + 1) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	sort(str, str + nmonster);
	sumstr[0] = 0; REP(i, nmonster) sumstr[i + 1] = (sumstr[i] + str[i]) % MOD;
	REP(i, nshield) {
		int idx = lower_bound(str, str + nmonster, def[i]) - str;
		int nbig = nmonster - idx, nsmall = idx;
		int cur = 0;
		if (nbig >= dur[i]) {
			// probability that a big monster hits us: (nbig-dur[i])/nbig
			int bigsum = sumstr[nmonster] - sumstr[idx]; if (bigsum < 0) bigsum += MOD;
			cur = (cur + (ll)bigsum * (nbig - dur[i]) % MOD * inv[nbig]) % MOD;
			// probability that a small monster hits us: (nbig+1-dur[i])/(nbig+1)
			int smallsum = sumstr[idx];
			cur = (cur + (ll)smallsum * (nbig + 1 - dur[i]) % MOD * inv[nbig + 1]) % MOD;
		}
		ans[i] = cur;
	}
}

void run() {
	scanf("%d%d", &nmonster, &nshield);
	REP(i, nmonster) scanf("%d", &str[i]);
	REP(i, nshield) scanf("%d%d", &dur[i], &def[i]);
	solve();
	REP(i, nshield) printf("%d\n", ans[i]);
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}