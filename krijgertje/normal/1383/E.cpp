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

const int MAXLEN = 1000000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

char s[MAXLEN + 1]; int slen;

char t[MAXLEN + 1]; int tlen;

//int cntsame[MAXLEN];
//pair<int, int> zerostck[MAXLEN]; int nzerostck;
int dp[MAXLEN]; // if t[i]=='1' -> #ways for starting here, if t[i]=='0' -> #ways for starting here or on a later zero

int dpzero[MAXLEN + 1], dpzerosum;
int cntsame[MAXLEN + 1];

int calc() {
	assert(tlen >= 1 && t[0] == '1' && t[tlen - 1] == '1');
	dpzerosum = 0; REPE(i, tlen) dpzero[i] = 0;
	for (int i = tlen - 1; i >= 0; --i) cntsame[i] = 1 + (i + 1 < tlen && t[i + 1] == t[i] ? cntsame[i + 1] : 0);
	for (int i = tlen - 1; i >= 0; --i) {
		if (t[i] == '0') {
			int nzero = cntsame[i], j = i + nzero;
			assert(j < tlen && nzero >= 1);
			dec(dpzerosum, dpzero[nzero]);
			dpzero[nzero] = dp[j];
			inc(dpzerosum, dpzero[nzero]);
			dp[i] = dpzerosum;
		}
		if (t[i] == '1') {
			dp[i] = 0;
			if (i + 1 < tlen && t[i + 1] == '1') {
				dp[i] = dp[i + 1];
				int none = cntsame[i], j = i + none;
				if (j == tlen) inc(dp[i], 1); else inc(dp[i], dp[j] + 1);
			} else if (i + 1 < tlen) {
				int nzero = cntsame[i + 1], j = i + 1 + nzero;
				dp[i] = dp[j];
				inc(dp[i], dp[i + 1] + 1);
			} else {
				dp[i] = 1;
			}
		}
		//printf("dp[%d]=%d\n", i, dp[i]);
	}
	return dp[0];
}

int solve() {
	bool allzero = true; REP(i, slen) if (s[i] != '0') allzero = false; if (allzero) return slen;
	int prefzero = 0; while (s[prefzero] == '0') ++prefzero;
	int suffzero = 0; while (s[slen - suffzero - 1] == '0') ++suffzero;
	tlen = 0; FOR(i, prefzero, slen - suffzero) t[tlen++] = s[i];
	return (ll)(prefzero + 1) * (suffzero + 1) % MOD * calc() % MOD;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}