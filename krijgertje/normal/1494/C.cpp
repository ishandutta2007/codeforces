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

int calc(vector<int> have, vector<int> want) {
	//printf("have:"); REPSZ(i, have) printf(" %d", have[i]); puts("");
	//printf("want:"); REPSZ(i, want) printf(" %d", want[i]); puts("");
	int nhave = SZ(have), nwant = SZ(want);
	vector<int> suff(nhave + 1, 0);
	for (int i = 0, j = 0; i < nhave; ++i) { while (j < nwant && want[j] < have[i]) ++j; if (j < nwant && want[j] == have[i]) suff[i] = 1; }
	for (int i = nhave - 1; i >= 0; --i) suff[i] += suff[i + 1];
	int ret = suff[0];
	int lidx = 0, ridx = 0;
	FORE(i, 1, nhave) {
		int r = have[i - 1] + 1, l = r - i;
		while (true) {
			while (lidx < nwant && want[lidx] < l) ++lidx;
			while (ridx < nwant && want[ridx] < r) ++ridx;
			int cur = ridx - lidx + suff[i];
			//printf("\t%d: [%d..%d] -> %d\n", i, l, r - 1, cur);
			ret = max(ret, cur);
			if (ridx >= nwant || i < nhave && want[ridx] >= have[i]) break;
			r = want[ridx] + 1, l = r - i;
		}
	}
	//printf("->%d\n", ret);
	return ret;
}

vector<int> have;
vector<int> want;

int solve() {
	vector<int> havepos, haveneg;
	vector<int> wantpos, wantneg;
	for (int x : have) if (x > 0) havepos.PB(x); else haveneg.PB(-x);
	for (int x : want) if (x > 0) wantpos.PB(x); else wantneg.PB(-x);
	reverse(haveneg.begin(), haveneg.end());
	reverse(wantneg.begin(), wantneg.end());
	return calc(havepos, wantpos) + calc(haveneg, wantneg);
}

void run() {
	int nhave, nwant;
	scanf("%d%d", &nhave, &nwant);
	have = vector<int>(nhave); REP(i, nhave) scanf("%d", &have[i]);
	want = vector<int>(nwant); REP(i, nwant) scanf("%d", &want[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}