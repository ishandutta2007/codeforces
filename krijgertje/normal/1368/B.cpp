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

const int SLEN = 10;
char S[SLEN + 1] = "codeforces";

ll want;
string ans;

int cnt[SLEN];

void solve() {
	int sum = SLEN;
	REP(i, SLEN) cnt[i] = 1;
	ll prod = 1;
	while (prod < want) {
		REP(i, SLEN) if (prod < want) {
			prod /= cnt[i];
			++cnt[i], ++sum;
			prod *= cnt[i];
		}
	}
	ans = string(sum, '?');
	int at = 0; REP(i, SLEN) REP(j, cnt[i]) ans[at++] = S[i];
}

void run() {
	scanf("%lld", &want);
	solve();
	printf("%s\n", ans.c_str());
}

int main() {
	run();
	return 0;
}