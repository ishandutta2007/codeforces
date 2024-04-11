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

const int MAXCELL = 1000;
const int MAXOP = 1000;
const int MAXBIT = 2 * MAXCELL + 1;
const int OPMIX = 0;
const int OPRY = 1;
const int OPRB = 2;
const int OPYB = 3;
typedef bitset<MAXBIT> bs;

int ncell, nop;
int opkind[MAXOP]; vector<int> opcell[MAXOP]; char opcol[MAXOP];
char ans[MAXCELL + 1];

bs rbmask[MAXCELL];
bs ybmask[MAXCELL];

bs eq[2 * MAXOP]; int neq;
int pivot[MAXBIT];

void gaussjord(int R, int C) {
	REP(c,C) pivot[c] = -1;
	int r = 0, c = 0;
	while (r < R && c < C) {
		{ int rr = r; while (rr < R && !eq[rr][c]) ++rr; if (rr >= R) { ++c; continue; } if (rr != r) swap(eq[r], eq[rr]); }
		pivot[c] = r;
		REP(rr, R) if (rr != r&&eq[rr][c]) eq[rr] ^= eq[r];
		++r, ++c;
	}
}

bool solve() {
	REP(i, ncell) {
		rbmask[i].reset(); rbmask[i].set(2 * i + 0);
		ybmask[i].reset(); ybmask[i].set(2 * i + 1);
	}
	neq = 0;
	REP(i, nop) {
		if (opkind[i] == OPMIX) {
			int rbidx = neq++;
			int ybidx = neq++;
			eq[rbidx].reset();
			eq[ybidx].reset();
			REPSZ(j, opcell[i]) {
				int at = opcell[i][j];
				eq[rbidx] ^= rbmask[at];
				eq[ybidx] ^= ybmask[at];
			}
			if (opcol[i] == 'R' || opcol[i] == 'B') eq[rbidx].set(2 * ncell);
			if (opcol[i] == 'Y' || opcol[i] == 'B') eq[ybidx].set(2 * ncell);
		} else {
			REPSZ(j, opcell[i]) {
				int at = opcell[i][j];
				if (opkind[i] == OPRY) swap(rbmask[at], ybmask[at]);
				if (opkind[i] == OPRB) ybmask[at] ^= rbmask[at];
				if (opkind[i] == OPYB) rbmask[at] ^= ybmask[at];
			}
		}
	}
	gaussjord(neq, 2 * ncell + 1);
	if (pivot[2 * ncell] != -1) return false;
	REP(i, ncell) {
		bool isrb = pivot[2 * i + 0] != -1 && eq[pivot[2 * i + 0]][2 * ncell];
		bool isyb = pivot[2 * i + 1] != -1 && eq[pivot[2 * i + 1]][2 * ncell];
		ans[i] = isrb ? isyb ? 'B' : 'R' : isyb ? 'Y' : '.';
	}
	ans[ncell] = '\0';
	return true;
}

void run() {
	scanf("%d%d", &ncell, &nop);
	REP(i, nop) {
		char s[10]; int cnt; scanf("%s%d", s, &cnt);
		if (strcmp(s, "mix") == 0) opkind[i] = OPMIX; else if (strcmp(s, "RY") == 0) opkind[i] = OPRY; else if (strcmp(s, "RB") == 0) opkind[i] = OPRB; else if (strcmp(s, "YB") == 0) opkind[i] = OPYB; else assert(false);
		opcell[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &opcell[i][j]), --opcell[i][j];
		if (opkind[i] == OPMIX) scanf(" %c", &opcol[i]);
	}
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}