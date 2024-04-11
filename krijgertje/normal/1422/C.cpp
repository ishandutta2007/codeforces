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

const int MAXLEN = 100000;
const int MOD = 1000000007;

char s[MAXLEN + 1]; int slen;

int p10[MAXLEN + 1];
int mlt[MAXLEN + 1];

int solve() {
	p10[0] = 1; FORE(i, 1, slen) p10[i] = (ll)p10[i - 1] * 10 % MOD;
	mlt[0] = 0; FORE(i, 1, slen) mlt[i] = (mlt[i - 1] + (ll)p10[i - 1] * i) % MOD;
	int ret = 0;
	REP(i, slen) {
		int x = s[i] - '0';
		{
			int before = i, ways = (ll)before * (before + 1) / 2 % MOD;
			ret = (ret + (ll)p10[slen - i - 1] * x % MOD * ways) % MOD;
		}
		{
			int after = slen - i - 1;
			ret = (ret + (ll)mlt[after] * x) % MOD;
		}
	}
	return ret;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}