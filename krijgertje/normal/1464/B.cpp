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
char s[MAXN + 1];
int x, y;

int before[MAXN][3];
int after[MAXN][3];

ll solve() {
	REP(i, n) before[i][0] = i == 0 ? 0 : before[i - 1][0] + (s[i - 1] == '0' ? 1 : 0);
	REP(i, n) before[i][1] = i == 0 ? 0 : before[i - 1][1] + (s[i - 1] == '1' ? 1 : 0);
	REP(i, n) before[i][2] = i == 0 ? 0 : before[i - 1][2] + (s[i - 1] == '?' ? 1 : 0);
	for (int i = n - 1; i >= 0; --i) after[i][0] = i == n - 1 ? 0 : after[i + 1][0] + (s[i + 1] == '0' ? 1 : 0);
	for (int i = n - 1; i >= 0; --i) after[i][1] = i == n - 1 ? 0 : after[i + 1][1] + (s[i + 1] == '1' ? 1 : 0);
	for (int i = n - 1; i >= 0; --i) after[i][2] = i == n - 1 ? 0 : after[i + 1][2] + (s[i + 1] == '?' ? 1 : 0);

	ll ret = LLONG_MAX;
	{ // 01
		ll cur = 0;
		REP(i, n) if (s[i] == '1') cur += (ll)x * (before[i][0] + before[i][2]) + (ll)y * (after[i][0] + after[i][2]);
		ret = min(ret, cur);
		for (int i = n - 1; i >= 0; --i) if (s[i] == '?') {
			cur -= (ll)y * (before[i][1]) + (ll)x * (after[i][1] + after[i][2]);
			cur += (ll)x * (before[i][0] + before[i][2]) + (ll)y * (after[i][0]);
			ret = min(ret, cur);
		}
	}
	{ // 10
		ll cur = 0;
		REP(i, n) if (s[i] == '1') cur += (ll)x * (before[i][0] + before[i][2]) + (ll)y * (after[i][0] + after[i][2]);
		ret = min(ret, cur);
		REP(i, n) if (s[i] == '?') {
			cur -= (ll)y * (before[i][1] + before[i][2]) + (ll)x * (after[i][1]);
			cur += (ll)x * (before[i][0]) + (ll)y * (after[i][0] + after[i][2]);
			ret = min(ret, cur);
		}
	}
	return ret;
}

void run() {
	scanf("%s", s); n = strlen(s);
	scanf("%d%d", &x, &y);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}