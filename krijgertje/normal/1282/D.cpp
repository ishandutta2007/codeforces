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

const int MAXLEN = 300;

int query(const string& t) {
	printf("%s\n", t.c_str()); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
}

void solve() {
	int v = query(string(MAXLEN, 'a'));
	if (v == 0) return;
	int x = MAXLEN - v;
	int w = query(string(MAXLEN, 'b'));
	if (w == 0) return;
	int y = MAXLEN - w;
	assert(x >= 0 && y >= 0 && x + y >= 1 && x + y <= MAXLEN);
	int len = x + y;
	int remy = y;
	string ans(len, 'a');
	REP(i, len - 1) {
		string t(len, 'a'); t[i] = 'b';
		int q = query(t);
		if (q == 0) return;
		if (q == y - 1) ans[i] = 'b', --remy;
	}
	assert(remy == 0 || remy == 1);
	if (remy == 1) ans[len - 1] = 'b', --remy;
	assert(query(ans) == 0);
}

void run() {
	solve();
}

int main() {
	run();
	return 0;
}