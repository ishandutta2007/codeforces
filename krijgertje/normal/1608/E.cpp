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

const int MAXN = 100000;
struct P { int x, y, col; P() {} void flip() { swap(x, y); } void rotate() { swap(x, y); x = -x; } };

int n;
P p[MAXN];

int perm[3];
vector<P> A, B, C;

int calcthreestripes() {
	sort(A.begin(), A.end(), [&](const P &a, const P &b) { return a.x < b.x; });
	sort(B.begin(), B.end(), [&](const P &a, const P &b) { return a.x < b.x; });
	sort(C.begin(), C.end(), [&](const P &a, const P &b) { return a.x < b.x; });
	int ret = 0;
	int l = 0, r = SZ(B) - 1;
	while (ret < SZ(A) && ret < SZ(C)) {
		int lx = A[ret].x;
		while (l < SZ(B) && B[l].x <= lx) ++l;
		int rx = C[SZ(C) - ret - 1].x;
		while (r >= 0 && B[r].x >= rx) --r;
		if (r - l + 1 >= ret + 1) ++ret; else break;
	}
	return 3 * ret;
}

int calctshape() {
	sort(A.begin(), A.end(), [&](const P &a, const P &b) { return a.x < b.x; });
	sort(B.begin(), B.end(), [&](const P &a, const P &b) { return a.x < b.x; });
	sort(C.begin(), C.end(), [&](const P &a, const P &b) { return a.x < b.x; });

	set<pair<int,int>> buse, bavail, cuse, cavail;
	REPSZ(i, B) bavail.insert(MP(B[i].y, i));
	REPSZ(i, C) cavail.insert(MP(C[i].y, i));
	int ret = 0;
	int bpos = 0, cpos = 0;
	while (ret < SZ(A)) {
		int x = A[ret].x;
		while (bpos < SZ(B) && B[bpos].x <= x) { pair<int, int> cur = MP(B[bpos].y, bpos); buse.erase(cur); bavail.erase(cur); ++bpos; }
		while (cpos < SZ(C) && C[cpos].x <= x) { pair<int, int> cur = MP(C[cpos].y, cpos); cuse.erase(cur); cavail.erase(cur); ++cpos; }
		while (SZ(buse) < ret + 1 && SZ(bavail) > 0) { pair<int, int> cur = *bavail.begin(); bavail.erase(cur); buse.insert(cur); }
		while (SZ(cuse) < ret + 1 && SZ(cavail) > 0) { pair<int, int> cur = *cavail.rbegin(); cavail.erase(cur); cuse.insert(cur); }
		if (SZ(buse) == ret + 1 && SZ(cuse) == ret + 1 && buse.rbegin()->first < cuse.begin()->first) ++ret; else break;
	}
	return 3 * ret;
}


int solve() {
	int ret = 0;
	REP(i, 3) perm[i] = i;
	do {
		A.clear(); B.clear(); C.clear();
		REP(i, n) if (p[i].col == perm[0]) A.PB(p[i]);
		REP(i, n) if (p[i].col == perm[1]) B.PB(p[i]);
		REP(i, n) if (p[i].col == perm[2]) C.PB(p[i]);
		REP(rep, 2) {
			ret = max(ret, calcthreestripes());
			REPSZ(i, A) A[i].flip();
			REPSZ(i, B) B[i].flip();
			REPSZ(i, C) C[i].flip();
		}
		REP(rep, 4) {
			ret = max(ret, calctshape());
			REPSZ(i, A) A[i].rotate();
			REPSZ(i, B) B[i].rotate();
			REPSZ(i, C) C[i].rotate();
		}
	} while (next_permutation(perm, perm + 3));
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].col), --p[i].col;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}