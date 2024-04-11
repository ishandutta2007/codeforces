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

const int MAXTYPE = 200000;
const int MAXCARD = 2 * MAXTYPE;

int ntype, ncard;
int a[MAXCARD], b[MAXCARD];
int ans[MAXCARD];

int apos[MAXCARD + 1], bpos[MAXCARD + 1];
int amatch[MAXCARD], bmatch[MAXCARD];

int nans;
bool done[MAXCARD];

int prv[MAXCARD], nxt[MAXCARD];

bool place(vector<int> cur) {
	//printf("cur:"); REPSZ(i, cur) printf(" %d", cur[i]); puts("");
	//printf("cur:"); REPSZ(i, cur) printf(" [%d %d]", a[cur[i]], b[cur[i]]); puts("");
	int ncur = SZ(cur);
	string s(ncur, '?');
	s[0] = 'A'; FOR(i, 1, ncur) if ((a[cur[i]] > 0) == (b[cur[i]] > 0)) s[i] = s[i - 1]; else s[i] = 'A' + 1 - (s[i - 1] - 'A');
	//printf("s=%s\n", s.c_str());
	vector<int> bal(ncur + 1);
	bal[0] = 0;
	REP(i, ncur) bal[i + 1] = bal[i] + (s[i] == 'A' ? +1 : -1);
	//printf("bal:"); REPE(i, ncur) printf(" %d", bal[i]); puts("");
	if (abs(bal[ncur]) != 2) return false;
	if (bal[ncur] == -2) {
		REP(i, ncur) if (a[cur[i]] > 0 && b[cur[i]] > 0 && s[i] == 'B') { rotate(cur.begin(), cur.begin() + i, cur.end()); return place(cur); }
		assert(false);
	}
	assert(s[ncur - 1] == 'A');

	struct Item { char kind; int dir; int head, tail; Item(char kind, int dir, int card) :kind(kind), dir(dir), head(card), tail(card) {} };

	auto prepend = [&](Item& it, int card) {
		nxt[card] = it.head;
		if (it.head == -1) it.tail = card; else prv[it.head] = card;
		it.head = card;
	};
	auto append = [&](Item& it, int card) {
		prv[card] = it.tail;
		if (it.tail == -1) it.head = card; else nxt[it.tail] = card;
		it.tail = card;
	};
	auto prependlst = [&](Item& it, Item& oth) {
		nxt[oth.tail] = it.head;
		prv[it.head] = oth.tail;
		it.head = oth.head;
	};
	auto appendlst = [&](Item& it, Item& oth) {
		nxt[it.tail] = oth.head;
		prv[oth.head] = it.tail;
		it.tail = oth.tail;
	};

	vector<Item> stck;
	stck.PB(Item('-', 0, cur[0]));
	REP(i, ncur) {
		int to = cur[(i + 1) % ncur];
		if (stck.back().kind == '-') {
			stck.PB(Item(s[i], s[i] == 'A' ? +1 : -1, to));
		} else if (stck.back().kind == s[i]) {
			stck.PB(Item(s[i], -stck.back().dir, to));
		} else {
			if (stck.back().dir == -1) {
				prependlst(stck[SZ(stck) - 2], stck.back());
				stck.pop_back();
				prepend(stck.back(), to);
			} else {
				appendlst(stck[SZ(stck) - 2], stck.back());
				stck.pop_back();
				append(stck.back(), to);
			}
		}
	}
	//REPSZ(i, stck) { printf("stck%d:", i); for (int x = stck[i].head; x != -1; x = nxt[x]) printf(" %d", x); puts(""); }
	assert(SZ(stck) == 3 && stck[0].kind == '-' && stck[1].kind == 'A' && stck[2].kind == 'A' && stck[2].head == stck[2].tail && stck[2].head == cur[0]);

	stck.pop_back();
	appendlst(stck[SZ(stck) - 2], stck.back());
	stck.pop_back();
	vector<int> ord; for (int x = stck[0].head; x != -1; x = nxt[x]) ord.PB(x);
	assert(SZ(ord) == ncur);
	//printf("ord:"); for (int x : ord) printf(" [%d,%d]", a[x], b[x]); puts("");

	REPSZ(i, ord) ans[nans++] = ord[i];


	return true;
}

bool solve() {
	REPE(i, ncard) apos[i] = bpos[i] = -1;
	REP(i, ncard) apos[a[i] + ncard] = i, bpos[b[i] + ncard] = i;
	REP(i, ncard) amatch[i] = apos[-a[i] + ncard], bmatch[i] = bpos[-b[i] + ncard];

	nans = 0;
	REP(i, ncard) done[i] = false, prv[i] = nxt[i] = -1;
	REP(i, ncard) if (!done[i] && a[i] > 0 && b[i] > 0) {
		vector<int> cur;
		int at = i;
		while (!done[at]) {
			cur.PB(at);
			done[at] = true;
			if (SZ(cur) % 2 == 1) at = amatch[at]; else at = bmatch[at];
		}
		if (!place(cur)) return false;
	}
	REP(i, ncard) if (!done[i]) return false;
	return true;
}

void run() {
	scanf("%d", &ntype); ncard = 2 * ntype;
	REP(i, ncard) scanf("%d%d", &a[i], &b[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, ncard) printf("%d %d\n", a[ans[i]], b[ans[i]]);
}

void stress() {
	int mxtype = 100;
	REP(rep, 100000) {
		ntype = rnd() % mxtype + 1; ncard = 2 * ntype;
		vector<int> asgn; while (true) { asgn = vector<int>(ncard); REP(i, ncard) asgn[i] = i < ntype ? +1 : -1; shuffle(asgn.begin(), asgn.end(), rnd); bool ok = true; int bal = 0; REP(i, ncard) { bal += asgn[i]; if (bal < 0) ok = false; } if (ok) break; }
		vector<int> bsgn; while (true) { bsgn = vector<int>(ncard); REP(i, ncard) bsgn[i] = i < ntype ? +1 : -1; shuffle(bsgn.begin(), bsgn.end(), rnd); bool ok = true; int bal = 0; REP(i, ncard) { bal += bsgn[i]; if (bal < 0) ok = false; } if (ok) break; }
		vector<int> aperm(ntype); REP(i, ntype) aperm[i] = i + 1; shuffle(aperm.begin(), aperm.end(), rnd);
		vector<int> bperm(ntype); REP(i, ntype) bperm[i] = i + 1; shuffle(bperm.begin(), bperm.end(), rnd);
		vector<pair<int, int>> cards(ncard);
		vector<int> astck; REP(i, ncard) if (asgn[i] == +1) { int id = aperm.back(); aperm.pop_back(); cards[i].first = +id; astck.PB(id); } else { int id = astck.back(); astck.pop_back(); cards[i].first = -id; }
		vector<int> bstck; REP(i, ncard) if (bsgn[i] == +1) { int id = bperm.back(); bperm.pop_back(); cards[i].second = +id; bstck.PB(id); } else { int id = bstck.back(); bstck.pop_back(); cards[i].second = -id; }
		shuffle(cards.begin(), cards.end(), rnd);
		REP(i, ncard) a[i] = cards[i].first, b[i] = cards[i].second;
		bool have = solve();
		if (!have) {
			printf("%d\n", ntype); REP(i, ncard) printf("%d %d\n", a[i], b[i]);
			break;
		}
		if (rep % 1000 == 999) printf(".");

	}
}

int main() {
	run();
	//stress();
	return 0;
}