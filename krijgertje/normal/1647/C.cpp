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

const int MAXDIM = 100;
struct Op { int lx, ly, hx, hy; Op() {} Op(int lx, int ly, int hx, int hy) :lx(lx), ly(ly), hx(hx), hy(hy) {} };

int h, w;
char g[MAXDIM][MAXDIM + 1];
vector<Op> ans;

bool solve() {
	ans.clear();
	if (g[0][0] == '1') return false;
	for (int x = h - 1; x >= 1; --x) REP(y, w) if (g[x][y] == '1') ans.PB(Op(x - 1, y, x, y));
	for (int y = w - 1; y >= 1; --y) if (g[0][y] == '1') ans.PB(Op(0, y - 1, 0, y));
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	for (auto op : ans) printf("%d %d %d %d\n", op.lx + 1, op.ly + 1, op.hx + 1, op.hy + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}