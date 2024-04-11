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

const int MAXN = 1000, MAXLEN = 1000;
struct Seg { int l, r, id; Seg() {} Seg(int l, int r, int id) :l(l), r(r), id(id) {} };

int n, len;
char know[MAXN][MAXLEN + 1];
char s[MAXLEN + 1];
vector<Seg> ans;

bool can2[10][10];
bool can3[10][10][10];
Seg seg2[10][10];
Seg seg3[10][10][10];

int act[MAXLEN + 1];

bool solve() {
	REP(x, 10) REP(y, 10) can2[x][y] = false;
	REP(x, 10) REP(y, 10) REP(z, 10) can3[x][y][z] = false;
	REP(i, n) {
		REP(j, len - 1) { int x = know[i][j] - '0', y = know[i][j + 1] - '0'; if (!can2[x][y]) can2[x][y] = true, seg2[x][y] = Seg(j, j + 1, i); }
		REP(j, len - 2) { int x = know[i][j] - '0', y = know[i][j + 1] - '0', z = know[i][j + 2] - '0'; if (!can3[x][y][z]) can3[x][y][z] = true, seg3[x][y][z] = Seg(j, j + 2, i); }
	}

	REPE(i, len) act[i] = -2;
	act[0] = -1;
	REPE(i, len) if (act[i] != -2) {
		if (i + 1 < len) {
			int x = s[i] - '0', y = s[i + 1] - '0';
			if (can2[x][y]) act[i + 2] = 2;
		}
		if (i + 2 < len) {
			int x = s[i] - '0', y = s[i + 1] - '0', z = s[i + 2] - '0';
			if (can3[x][y][z]) act[i + 3] = 3;
		}
	}
	if (act[len] == -2) return false;
	//printf("act:"); REPE(i, len) printf(" %d", act[i]); puts("");

	ans.clear();
	int at = len;
	while (at != 0) {
		int step = act[at];
		at -= step;
		if (step == 2) {
			int x = s[at] - '0', y = s[at + 1] - '0';
			assert(can2[x][y]);
			ans.PB(seg2[x][y]);
		}
		if (step == 3) {
			int x = s[at] - '0', y = s[at + 1] - '0', z = s[at + 2] - '0';
			assert(can3[x][y][z]);
			ans.PB(seg3[x][y][z]);
		}
	}
	reverse(ans.begin(), ans.end());
	return true;
}


void run() {
	scanf("%d%d", &n, &len);
	REP(i, n) scanf("%s", know[i]);
	scanf("%s", s);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d\n", ans[i].l + 1, ans[i].r + 1, ans[i].id + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}