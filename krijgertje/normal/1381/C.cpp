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

int n, nallcorrect, ncolcorrect;
int guess[MAXN];
int ans[MAXN];

vector<int> who[MAXN + 1];
int cnt[MAXN + 1];
int allcorrect[MAXN + 1];
int allwrong[MAXN + 1];
bool iswrong[MAXN];

bool solve() {
	int nsomewrong = n - nallcorrect;
	int nallwrong = n - ncolcorrect;

	REPE(i, n) who[i].clear();
	REP(i, n) who[guess[i]].PB(i);
	REP(i, n) ans[i] = -1;
	int missing = -1; REPE(i, n) if (SZ(who[i]) == 0) { missing = i; break; } assert(missing != -1);
	// (cnt[i]-allcorrect[i])+(cnt[i]-allcorrect[i]-allwrong[i])<=nsomewrong -> 2*cnt[i]-2*allcorrect[i]-allwrong[i]<=nsomewrong, with sum(allcorrect)=nallcorrect ans sum(allwrong)=nallwrong

	REPE(i, n) allcorrect[i] = allwrong[i] = 0, cnt[i] = SZ(who[i]);
	int rem = nallcorrect;
	REPE(i, n) while (rem > 0 && 2 * cnt[i] - 2 * allcorrect[i] >= nsomewrong + 2) { --rem; ++allcorrect[i]; }
	REPE(i, n) while (rem > 0 && 2 * cnt[i] - 2 * allcorrect[i] >= nsomewrong + 1) { --rem; ++allcorrect[i]; }
	REPE(i, n) while (rem > 0 && allcorrect[i] < cnt[i]) { --rem; ++allcorrect[i]; }
	assert(rem == 0);
	rem = nallwrong;
	REPE(i, n) while (rem > 0 && 2 * cnt[i] - 2 * allcorrect[i] - allwrong[i] >= nsomewrong + 1) { --rem; ++allwrong[i]; }
	REPE(i, n) while (rem > 0 && allcorrect[i] + allwrong[i] < cnt[i]) { --rem; ++allwrong[i]; }
	assert(rem == 0);
	REPE(i, n) if (2 * cnt[i] - 2 * allcorrect[i] - allwrong[i] > nsomewrong) return false;
	//REPE(i, n) printf("%d: cnt=%d allcorrect=%d allwrong=%d\n", i, cnt[i], allcorrect[i], allwrong[i]);

	REPE(i, n) REP(j, allcorrect[i]) {
		assert(SZ(who[i]) > 0);
		int idx = who[i].back(); who[i].pop_back();
		ans[idx] = i;
	}
	REP(i, n) iswrong[i] = false;
	REPE(i, n) REP(j, allwrong[i]) {
		assert(j < SZ(who[i]));
		int idx = who[i][SZ(who[i]) - j - 1];
		iswrong[idx] = true;
	}
	vector<int> seq; int shift = 0;
	REPE(i, n) shift = max(shift, SZ(who[i]));
	REPE(i, n) REPSZ(j, who[i]) seq.PB(who[i][j]);
	//printf("seq:"); REPSZ(i, seq) printf(" %d", seq[i]); printf(" (shift=%d)\n", shift);
	REPSZ(i, seq) {
		int j = (i + shift) % SZ(seq);
		int a = seq[i], b = seq[j];
		ans[b] = !iswrong[a] ? guess[a] : missing;
	}
	return true;




	/*

	REPE(i, n) {

		// 2*SZ(who[i])-2*x-y<=nwrong

		int idx = who[i].back(); who[i].pop_back();
		if (ndone < nallcorrect) {
			ans[idx] = i; ++ndone;
		} else {
			iswrong[idx] = true; wrong.PB(idx); ++ndone;
		}
	}
	REPE(i, n) while (SZ(who[i]) > 0 && ndone < n - nwrongpos) {
		int idx = who[i].back(); who[i].pop_back();
		if (ndone < nallcorrect) {
			ans[idx] = i; ++ndone;
		} else {
			iswrong[idx] = true; wrong.PB(idx); ++ndone;
		}
	}
	if (ndone > n - nwrongpos) return false;
	seq.clear();
	REPE(i, n) REPSZ(j, who[i]) seq.PB(who[i][j]);
	REPSZ(j, wrong) seq.PB(wrong[j]);
	int shift = 0; REPE(i, n) shift = max(shift, SZ(who[i]));
	assert(SZ(seq) == nwrong);
	//printf("seq:"); REPSZ(i, seq) printf(" %d", seq[i]); printf(" (shift=%d)\n", shift);
	assert(2 * shift <= nwrong);
	return true;*/
}

void run() {
	scanf("%d%d%d", &n, &nallcorrect, &ncolcorrect);
	REP(i, n) scanf("%d", &guess[i]), --guess[i];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

void verify() {
	int haveallcorrect = 0, havecolcorrect = 0;
	map<int, int> have, want;
	REP(i, n) if (guess[i] == ans[i]) ++haveallcorrect;
	REP(i, n) have[guess[i]]++;
	REP(i, n) want[ans[i]]++;
	for (auto it = have.begin(); it != have.end(); ++it) havecolcorrect += min(it->second, want[it->first]);
	if (haveallcorrect != nallcorrect || havecolcorrect != ncolcorrect) {
		printf("ERR[%d,%d,%d]:", n, nallcorrect, ncolcorrect); REP(i, n) printf(" %d", guess[i] + 1); puts("");
		printf("ans:"); REP(i, n) printf(" %d", ans[i] + 1); printf(" = %d,%d\n", haveallcorrect, havecolcorrect);
	}
}

void stress() {
	REP(rep, 10000) {
		n = rnd() % 50 + 1; ncolcorrect = rnd() % (n + 1); nallcorrect = rnd() % (ncolcorrect + 1);
		REP(i, n) guess[i] = rnd() % (n + 1);
		if (!solve()) {
			if (ncolcorrect != n || nallcorrect != n - 1) { printf("NO[%d,%d,%d]:", n, nallcorrect, ncolcorrect); REP(i, n) printf(" %d", guess[i] + 1); puts(""); }
		} else {
			verify();
		}
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}