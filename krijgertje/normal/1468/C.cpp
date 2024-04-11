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

const int MAXQ = 500000;

int nq;
int qkind[MAXQ], qspend[MAXQ];
int qans[MAXQ];

bool served[MAXQ];
int id[MAXQ], nid;
set<pair<int, int>> byspending;

void solve() {
	nid = 0;
	byspending.clear();
	int at = 0;
	REP(i, nq) {
		if (qkind[i] == 1) {
			served[i] = false;
			id[i] = nid++;
			byspending.insert(MP(-qspend[i], i));
		} else if (qkind[i] == 2) {
			while (at < i && (qkind[at] != 1 || served[at])) ++at;
			assert(at < i && qkind[at] == 1 && !served[at]);
			qans[i] = id[at];
			served[at] = true;
			byspending.erase(MP(-qspend[at], at));
		} else if (qkind[i] == 3) {
			assert(SZ(byspending) >= 1);
			int who = byspending.begin()->second;
			assert(who < i&& qkind[who] == 1 && !served[who]);
			qans[i] = id[who];
			served[who] = true;
			byspending.erase(MP(-qspend[who], who));
		}
	}
}

void run() {
	scanf("%d", &nq);
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1) scanf("%d", &qspend[i]); }
	solve();
	bool first = true;
	REP(i, nq) if (qkind[i] != 1) { if (first) first = false; else printf(" "); printf("%d", qans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}