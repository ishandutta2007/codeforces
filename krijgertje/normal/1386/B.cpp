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

const int MAXQ = 100000;
struct Mix { int a, b, c; };

struct P { int x, y, den; P() {} P(int _x, int _y, int _den) :x(_x), y(_y), den(_den) { int g = gcd(gcd(x, y), den); x /= g, y /= g, den /= g; } };
bool operator==(const P &a, const P &b) { return a.x == b.x&&a.y == b.y&&a.den == b.den; }


Mix want;
int nq;
char qtype[MAXQ]; int qadd[MAXQ]; int qrem[MAXQ]; int qans[MAXQ];
Mix have[MAXQ]; int nhave;

P pwant;
P phave[MAXQ];
int o[2 * MAXQ], no;
int dir[MAXQ];
int pos[MAXQ], posinv[MAXQ], npos;

int side(const P &a, const P &b, const P &c) {
	ll lhs = (ll)b.x*c.y*a.den - (ll)a.y*b.x*c.den - (ll)a.x*c.y*b.den;
	ll rhs = (ll)b.y*c.x*a.den - (ll)a.x*b.y*c.den - (ll)a.y*c.x*b.den;
	return lhs != rhs ? lhs > rhs ? +1 : -1 : 0;
}

int cmpang(const P &orig, const P &a, bool inva, const P &b,bool invb) {
	bool apos = (ll)a.y *orig.den > (ll)orig.y * a.den || (ll)a.y *  orig.den == (ll)orig.y * a.den && (ll)a.x *orig.den > (ll)orig.x * a.den; if (inva) apos = !apos;
	bool bpos = (ll)b.y *orig.den > (ll)orig.y * b.den || (ll)b.y *  orig.den == (ll)orig.y * b.den && (ll)b.x *orig.den > (ll)orig.x * b.den; if (invb) bpos = !bpos;
	if (apos != bpos) return apos ? -1 : +1;
	int ret = side(orig, a, b); if (inva) ret *= -1; if (invb) ret *= -1; return ret;
}

map<int, int> alive; int cntwant, cntoppo, cntlarge;

void add(int idx) {
	if (pos[idx] == -1) { ++cntwant; return; }
	if (alive.count(pos[idx]) == 0 && alive.count(posinv[idx]) > 0) ++cntoppo;
	if(alive.count(pos[idx])==0) {
		alive[pos[idx]] = 1;
		if (SZ(alive) >= 2) {
			auto it = alive.find(pos[idx]);
			int ppos = it == alive.begin() ? prev(alive.end())->first : prev(it)->first;
			int cpos = pos[idx];
			int npos = next(it) == alive.end() ? alive.begin()->first : next(it)->first;
			assert(dir[ppos] != -1 && dir[cpos] != -1 && dir[npos] != -1);
			P pp = phave[dir[ppos]], cp = phave[dir[cpos]], np = phave[dir[npos]];
			//printf("%c%c%c (%d,%d,%d)\n", SZ(alive) >= 3 && side(pwant, pp, np) < 0 ? '-' : '.', side(pwant, pp, cp) < 0 ? '+' : '.', side(pwant, cp, np) < 0 ? '+' : '.', dir[ppos], dir[cpos], dir[npos]);
			if (SZ(alive) >= 3 && side(pwant, pp, np) < 0) --cntlarge;
			if (side(pwant, pp, cp) < 0) ++cntlarge;
			if (side(pwant, cp, np) < 0) ++cntlarge;
			//if (cntlarge >= 4) exit(0);
		}
	} else {
		++alive[pos[idx]];
	}
}
void rem(int idx) {
	if (pos[idx] == -1) { --cntwant; return; }
	assert(alive.count(pos[idx]));
	if (alive[pos[idx]] >= 2) { --alive[pos[idx]]; return; }
	if (alive.count(posinv[idx]) > 0) --cntoppo;
	auto it = alive.find(pos[idx]);
	if (SZ(alive) >= 2) {
		int ppos = it == alive.begin() ? prev(alive.end())->first : prev(it)->first;
		int cpos = pos[idx];
		int npos = next(it) == alive.end() ? alive.begin()->first : next(it)->first;
		assert(dir[ppos] != -1 && dir[cpos] != -1 && dir[npos] != -1);
		P pp = phave[dir[ppos]], cp = phave[dir[cpos]], np = phave[dir[npos]];
		if (SZ(alive) >= 3 && side(pwant, pp, np) < 0) ++cntlarge;
		if (side(pwant, pp, cp) < 0) --cntlarge;
		if (side(pwant, cp, np) < 0) --cntlarge;
	}
	alive.erase(it);
}
int calc() {
	if (cntwant > 0) return 1;
	if (cntoppo > 0) return 2;
	if (SZ(alive) >= 2 && cntlarge == 0) return 3;
	return 0;
}

void solve() {
	pwant = P(want.a, want.b, want.a + want.b + want.c);
	REP(i, nhave) phave[i] = P(have[i].a, have[i].b, have[i].a + have[i].b + have[i].c);

	no = 0; REP(i, nhave) if (!(phave[i] == pwant)) o[no++] = 2 * i + 0, o[no++] = 2 * i + 1;
	sort(o, o + no, [&](const int &a, const int &b) { return cmpang(pwant, phave[a / 2], a % 2 == 1, phave[b / 2], b % 2 == 1) > 0; });
	//printf("o:"); REP(i, no) printf(" %d%c", o[i], i == 0 || cmpang(pwant, phave[o[i - 1] / 2], o[i - 1] % 2 == 1, phave[o[i] / 2], o[i] % 2 == 1) != 0 ? '!' : '.'); puts("");
	//REP(i, 3) REP(j, 3) if (i != j) printf("(%d,%d): %d\n", i, j, cmpang(pwant, phave[i], false, phave[j], false));
	npos = 0; REP(i, nhave) pos[i] = -1, posinv[i] = -1;
	REP(i, no) { 
		if (i == 0 || cmpang(pwant, phave[o[i - 1] / 2], o[i - 1] % 2 == 1, phave[o[i] / 2], o[i] % 2 == 1) != 0) dir[npos++] = -1;
		if (o[i] % 2 == 0 && dir[npos - 1] == -1) dir[npos - 1] = o[i] / 2;
		if (o[i] % 2 == 0) pos[o[i] / 2] = npos - 1; else posinv[o[i] / 2] = npos - 1;
	}

	alive.clear(), cntwant = 0, cntoppo = 0, cntlarge = 0;
	REP(i, nq) {
		if (qtype[i] == 'A') add(qadd[i]);
		if (qtype[i] == 'R') rem(qrem[i]);
		//printf("%d: cntlarge=%d\n", i, cntlarge);
		qans[i] = calc();
	}
}

void run() {
	scanf("%d%d%d", &want.a, &want.b, &want.c);
	scanf("%d", &nq);
	nhave = 0;
	REP(i, nq) {
		scanf(" %c", &qtype[i]);
		if (qtype[i] == 'A') scanf("%d%d%d", &have[nhave].a, &have[nhave].b, &have[nhave].c), qadd[i] = nhave++;
		if (qtype[i] == 'R') scanf("%d", &qrem[i]), --qrem[i];
	}
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}