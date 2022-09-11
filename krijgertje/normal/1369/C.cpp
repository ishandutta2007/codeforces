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

const int MAXVAL = 200000;
const int MAXFRIEND = MAXVAL;

int nval, nfriend;
int val[MAXVAL];
int want[MAXFRIEND];

ll solve() {
	sort(val, val + nval);
	sort(want, want + nfriend);
	ll ret = 0;
	int l = 0, r = nval - 1;
	REP(i, nfriend) if (want[i] == 1) ret += 2 * val[r--];
	for (int i = nfriend - 1; i >= 0; --i) if (want[i] != 1) {
		ret += val[l++];
		ret += val[r--];
		l += want[i] - 2;
	}
	return ret;
}

void run() {
	scanf("%d%d", &nval, &nfriend);
	REP(i, nval) scanf("%d", &val[i]);
	REP(i, nfriend) scanf("%d", &want[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}