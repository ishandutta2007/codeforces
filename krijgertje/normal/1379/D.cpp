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

const int MAXTRAIN = 100000;

int ntrain, nhour, nmin, boardmin;
int trainhour[MAXTRAIN], trainmin[MAXTRAIN];
vector<int> anscancel; int ansstartmin;

map<int, int> cnt;

void solve() {
	int period = nmin / 2;
	cnt.clear();
	cnt[0] = 0;
	cnt[period] = 0;
	REP(i, ntrain) {
		int l = trainmin[i] % period + 1, r = trainmin[i] % period + boardmin;
		//printf("\t%d..%d\n", l, r);
		if (l >= r) continue;
		if (l <= period) ++cnt[l];
		if (r <= period) --cnt[r]; else --cnt[period], ++cnt[0], --cnt[r - period];
	}
	{ int sum = 0; for (auto it = cnt.begin(); it != cnt.end(); ++it) { sum += it->second; it->second = sum; } }
	//printf("cnt:"); for (auto it = cnt.begin(); it != cnt.end(); ++it) printf(" %d=%d", it->first, it->second); puts("");

	int nanscancel = INT_MAX; ansstartmin = -1;
	for (auto it = cnt.begin(); it != cnt.end(); ++it) if (it->first < period && it->second < nanscancel) nanscancel = it->second, ansstartmin = it->first;
	anscancel.clear();
	REP(i, ntrain) {
		int l = trainmin[i] % period + 1, r = trainmin[i] % period + boardmin;
		if (l >= r) continue;
		if (l <= ansstartmin && ansstartmin < r || l <= ansstartmin + period && ansstartmin + period < r) anscancel.PB(i);
	}
	//printf("%d vs %d\n", SZ(anscancel), nanscancel);
	assert(SZ(anscancel) == nanscancel);
}

void run() {
	scanf("%d%d%d%d", &ntrain, &nhour, &nmin, &boardmin);
	REP(i, ntrain) scanf("%d%d", &trainhour[i], &trainmin[i]);
	solve();
	printf("%d %d\n", SZ(anscancel), ansstartmin);
	REPSZ(i, anscancel) { if (i != 0) printf(" "); printf("%d", anscancel[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}