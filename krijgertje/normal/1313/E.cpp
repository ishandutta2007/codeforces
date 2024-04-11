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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXPLEN = 500000;
const int MAXSLEN = 2 * MAXPLEN;
const int MAXTLEN = MAXSLEN + 1 + MAXPLEN;
const int MAXS = 4 * MAXPLEN;

int plen, slen;
char a[MAXPLEN + 1];
char b[MAXPLEN + 1];
char s[MAXSLEN + 1];

char t[MAXTLEN + 1]; int tlen;
int z[MAXTLEN];
int aprefmx[MAXPLEN];
int bsuffmx[MAXPLEN];

vector<int> awho[MAXPLEN + 1];
vector<int> bwho[MAXPLEN + 1];

void calcz() {
	int l = 0, r = 0;
	FOR(i, 1, tlen) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < tlen && t[i + z[i]] == t[z[i]]) ++z[i];
		if (i + z[i] > r) l = i, r = i + z[i];
	}
	//printf("t=%s\n", t);
	//printf("z:"); FOR(i, 1, tlen) printf(" %d", z[i]); puts("");
}

ll sval[MAXS];
int slazy[MAXS];
int scnt[MAXS];

void sapply(int x, int by) { sval[x] += (ll)by * scnt[x]; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = sval[2 * x + 1] + sval[2 * x + 2]; scnt[x] = scnt[2 * x + 1] + scnt[2 * x + 2]; }
void sinit(int x, int l, int r) {
	slazy[x] = scnt[x] = sval[x] = 0;
	if (l != r) {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void saddinterval(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(x, 1);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) saddinterval(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) saddinterval(2 * x + 2, m + 1, r, L, R);
		spull(x);
	}
}
void smod(int x, int l, int r, int IDX, int BY) {
	//if (x == 0) printf("\tmodding %d by %d\n", IDX, BY);
	if (l == r) {
		scnt[x] += BY;
		sval[x] = (ll)slazy[x] * scnt[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, BY);
		else smod(2 * x + 2, m + 1, r, IDX, BY);
		spull(x);
	}
}

void addinterval(int idx) {
	int l = idx, r = min(plen - 1, idx + slen - 2);
	//printf("\tadding interval [%d..%d]\n", l, r);
	saddinterval(0, 0, plen - 1, l, r);
}

ll solve() {
	tlen = 0; REP(i, slen) t[tlen++] = s[i]; t[tlen++] = '#'; REP(i, plen) t[tlen++] = a[i]; t[tlen] = '\0';
	calcz();
	REP(i, plen) aprefmx[i] = z[slen + 1 + i];
	//printf("aprefmx:"); REP(i, plen) printf(" %d", aprefmx[i]); puts("");

	tlen = 0; REP(i, slen) t[tlen++] = s[slen - i - 1]; t[tlen++] = '#'; REP(i, plen) t[tlen++] = b[plen - i - 1]; t[tlen] = '\0';
	calcz();
	REP(i, plen) bsuffmx[i] = z[slen + 1 + plen - i - 1];
	//printf("bsuffmx:"); REP(i, plen) printf(" %d", bsuffmx[i]); puts("");

	REPE(i, plen) awho[i].clear(); REP(i, plen) awho[aprefmx[i]].PB(i);
	REPE(i, plen) bwho[i].clear(); REP(i, plen) bwho[bsuffmx[i]].PB(i);

	sinit(0, 0, plen - 1);
	FORE(i, 1, plen) REPSZ(j, bwho[i]) smod(0, 0, plen - 1, bwho[i][j], +1);
	int ata = plen;
	int atb = 1;
	ll ret = 0;
	for (int alen = slen - 1; alen >= 1; --alen) {
		int blen = slen - alen; if (blen < 1 || alen>plen || blen > plen) continue;
		//printf("processing alen=%d blen=%d\n", alen, blen);
		while (ata >= alen) { REPSZ(j, awho[ata]) addinterval(awho[ata][j]); --ata; }
		while (atb < blen) { REPSZ(j, bwho[atb]) smod(0, 0, plen - 1, bwho[atb][j], -1); ++atb; }
		//printf(" -> %lld\n", sval[0]);
		ret += sval[0];
		
	}
	return ret;
}

void run() {
	scanf("%d%d", &plen, &slen);
	scanf("%s", a); assert(strlen(a) == plen);
	scanf("%s", b); assert(strlen(b) == plen);
	scanf("%s", s); assert(strlen(s) == slen);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}