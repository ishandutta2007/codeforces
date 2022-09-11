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

const int MAXN = 200000;
const int MAXALPH = 26;


int n, alph;
char ans[MAXN + 1];

void solve() {
	int period = alph * alph;
	string pattern(period, '?');
	int at = 0;
	pattern[at++] = 'a';
	if (alph != 1) REP(i, alph) {
		pattern[at++] = 'a' + i;
		for (int j = alph - 1; j >= i + 1; --j) {
			pattern[at++] = 'a' + j;
			if (j != i + 1) pattern[at++] = 'a' + i;
		}
	}
	for (int i = alph - 2; i >= 1; --i) pattern[at++] = 'a' + i;
	//printf("%s\n", pattern.c_str());
	assert(at == period);
	REP(i, n) ans[i] = pattern[i % period];
	ans[n] = '\0';
}

void run() {
	scanf("%d%d", &n, &alph);
	solve();
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}