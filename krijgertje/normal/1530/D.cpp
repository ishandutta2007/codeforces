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

int n;
int a[MAXN];
int b[MAXN];

vector<int> in[MAXN];

int solve() {
	REP(i, n) in[i] = vector<int>();
	REP(i, n) in[a[i]].PB(i);
	int ret = 0;
	REP(i, n) b[i] = -1;
	REP(at, n) {
		int who = -1;
		for (int prv : in[at]) {
			assert(b[prv] == -1);
			if (who == -1 || SZ(in[prv]) == 0) who = prv;
		}
		if (who == -1) { assert(SZ(in[at]) == 0); continue; }
		++ret;
		b[who] = at;
	}
	vector<pair<int, int>> chains;
	REP(i, n) if (SZ(in[i]) == 0) {
		int at = i;
		while (b[at] != -1) at = b[at];
		chains.PB(MP(i, at));
	}
	if (SZ(chains) == 1) assert(chains[0].first != chains[0].second);
	REPSZ(i, chains) {
		int j = (i + 1) % SZ(chains);
		int x = chains[i].second;
		assert(b[x] == -1);
		int y = chains[j].first;
		assert(y != x);
		b[x] = y;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i] + 1); } puts("");

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}