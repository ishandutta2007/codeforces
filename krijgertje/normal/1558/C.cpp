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

const int MAXN = 2021;

int n;
int a[MAXN];
vector<int> ans;

int cur[MAXN];

void move(int len) {
	assert(len % 2 == 1);
	ans.PB(len);
	reverse(cur, cur + len);
	//printf("cur:"); REP(i, n) printf(" %d", cur[i]); puts("");
}

bool solve() {
	assert(n % 2 == 1);
	REP(i, n) if ((a[i] % 2) != (i % 2)) return false;
	ans.clear();
	REP(i, n) cur[i] = a[i];
	for (int x = n - 1; x >= 2; x -= 2) {
		int xpos = -1;
		REP(i, n) if (cur[i] == x) xpos = i;
		assert(xpos != -1 && xpos % 2 == 0);
		if (xpos != 0) move(xpos + 1), xpos = 0;
		int y = x - 1;
		int ypos = -1;
		REP(i, n) if (cur[i] == y) ypos = i;
		assert(ypos != -1 && ypos % 2 == 1);
		if (ypos != 1) move(ypos), xpos = ypos - 1;
		if (xpos != 0) {
			move(ypos + 2), ypos = 1, xpos = 2;
			move(3), xpos = 0, ypos = 1;
		}
		move(x + 1);
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	if (!solve()) { printf("%d\n", -1); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}