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
#include <functional>
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

const int MAXN = 50000;

int na, x;
int a[MAXN];
int nb;
int b[MAXN];

bool solve() {
	int ai = 0, bi = 0;
	deque<pair<int, int>> qa, qb;
	while (ai < na || bi < nb || !qa.empty() || !qb.empty()) {
		if (qa.empty()) {
			if (ai >= na) return false;
			int v = a[ai++], k = 1;
			while (v % x == 0) v /= x, k *= x;
			qa.push_back(MP(v, k));
		}
		if (qb.empty()) {
			if (bi >= nb) return false;
			int v = b[bi++], k = 1;
			while (v % x == 0) v /= x, k *= x;
			qb.push_back(MP(v, k));
		}
		if (!qa.empty() && !qb.empty()) {
			if (qa.front().first != qb.front().first) return false;
			int cnt = min(qa.front().second, qb.front().second);
			qa.front().second -= cnt, qb.front().second -= cnt;
			if (qa.front().second == 0) qa.pop_front();
			if (qb.front().second == 0) qb.pop_front();
		}
	}
	return true;
}

void run() {
	scanf("%d%d", &na, &x);
	REP(i, na) scanf("%d", &a[i]);
	scanf("%d", &nb);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}