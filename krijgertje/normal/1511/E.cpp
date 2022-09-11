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

const int MOD = 998244353;
const int INV2 = (1 + MOD) / 2;
const int INV4 = (1 + (ll)3 * MOD) / 4;
const int INV8 = (1 + (ll)7 * MOD) / 8;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int h, w;
vector<string> g;

vector<string> flip(const vector<string>& g) {
	int h = SZ(g), w = SZ(g[0]);
	vector<string> ret(w, string(h, '?'));
	REP(x, h) REP(y, w) ret[y][x] = g[x][y];
	return ret;
}



int calc(const string& s) {
	int n = SZ(s);
	vector<int> dp(n, 0);
	int ret = 0;
	REP(i, n) {
		if (i + 1 < n && s[i] == 'o' && s[i + 1] == 'o') {
			if (i == 0 || s[i - 1] != 'o') {
				inc(dp[i], INV4);
			} else {
				inc(dp[i], INV8);
			}
			if (i - 2 >= 0) inc(dp[i], (ll)dp[i - 2] * INV4 % MOD);
		}
		inc(ret, dp[i]);
		//printf("\t%d = %lld\n", i, (ll)dp[i] * 128 % MOD);
	}
	//printf("%s = %lld\n", s.c_str(), (ll)ret * 128 % MOD);
	return ret;
}

int solve() {
	int ret = 0;
	REP(rep, 2) {
		REP(x, h) inc(ret, calc(g[x]));
		swap(h, w);
		g = flip(g);
	}
	int cnt = 0; REP(x, h) REP(y, w) if (g[x][y] == 'o') ++cnt;
	REP(i, cnt) ret = (ll)ret * 2 % MOD;
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	g = vector<string>(h); REP(x, h) cin >> g[x];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}