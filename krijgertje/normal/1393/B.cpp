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

const int MAXSTART = 100000;
const int MAXQ = 100000;
const int MAXVAL = 100000;

int nstart;
int startval[MAXSTART];
int nq;
char qkind[MAXQ]; int qval[MAXQ]; bool qans[MAXQ];


int cnt[MAXVAL + 1];

void solve() {
	REPE(i, MAXVAL) cnt[i] = 0;
	REP(i, nstart) ++cnt[startval[i]];
	int sum2 = 0, sum4 = 0; REPE(i, MAXVAL) sum2 += cnt[i] / 2, sum4 += cnt[i] / 4;
	REP(i, nq) {
		int x = qval[i];
		if (qkind[i] == '-') { assert(cnt[x] > 0); sum2 -= cnt[x] / 2, sum4 -= cnt[x] / 4; --cnt[x]; sum2 += cnt[x] / 2, sum4 += cnt[x] / 4; }
		if (qkind[i] == '+') { sum2 -= cnt[x] / 2, sum4 -= cnt[x] / 4; ++cnt[x]; sum2 += cnt[x] / 2, sum4 += cnt[x] / 4; }
		qans[i] = sum4 >= 1 && sum2 >= 4;
	}
}

void run() {
	scanf("%d", &nstart);
	REP(i, nstart) scanf("%d", &startval[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf(" %c%d", &qkind[i], &qval[i]);
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}