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
const int MAXQ = 200000;

int n, nq;
char qkind[MAXQ]; int qa[MAXQ], qb[MAXQ]; char qc[MAXQ]; int qk[MAXQ];
bool qans[MAXQ];

void solve() {
	int nsame = 0, nany = 0; // same=(x,y,c)+(y,x,c)  any=(x,y,c)+(y,x,d)
	map<pair<int, int>, char> have;
	REP(i, nq) {
		if (qkind[i] == '+') {
			int a = qa[i], b = qb[i]; char c = qc[i];
			if (have.count(MP(b, a)) && have[MP(b, a)] == c) ++nsame;
			if (have.count(MP(b, a))) ++nany;
			have[MP(a, b)] = c;
		}
		if (qkind[i] == '-') {
			int a = qa[i], b = qb[i]; char c = have[MP(a, b)];
			have.erase(MP(a, b));
			if (have.count(MP(b, a)) && have[MP(b, a)] == c) --nsame;
			if (have.count(MP(b, a))) --nany;
		}
		if (qkind[i] == '?') {
			qans[i] = qk[i] % 2 == 0 ? nsame > 0: nany > 0;
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) {
		scanf(" %c", &qkind[i]);
		if (qkind[i] == '+') scanf("%d%d %c", &qa[i], &qb[i], &qc[i]), --qa[i], --qb[i];
		if (qkind[i] == '-') scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
		if (qkind[i] == '?') scanf("%d", &qk[i]);
	}
	solve();
	REP(i, nq) if (qkind[i] == '?') printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}