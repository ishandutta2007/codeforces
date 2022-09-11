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

const int MAXN = 300000;
const int MAXSUMLEN = 500000;

int n;
string s[MAXN];
string ans;

int a[MAXN], b[MAXN];
int amx, bmx;


int calc(int x, int y) {
	int ret = 0;
	REP(i, n) {
		int dx = x - a[i], dy = y - b[i];
		if (dx < 0) dx = -dx, dy = -dy;
		int cur = dx >= 0 && dy >= 0 ? max(dx, dy) : abs(dx) + abs(dy);
		ret = max(ret, cur);
	}
	return ret;
}

pair<int,int> calc(int x) {
	int ylo = x == 0 ? 1 : 0, yhi = max(ylo, bmx);
	while (yhi - ylo >= 1) {
		int ymi1 = ylo + (yhi - ylo) / 2, ymi2 = ymi1 + 1;
		int v1 = calc(x, ymi1), v2 = calc(x, ymi2);
		if (v1 <= v2) yhi = ymi2 - 1; else ylo = ymi1 + 1;
	}
	assert(ylo == yhi);
	return MP(calc(x, ylo), ylo);
}

int solve() {
	REP(i, n) { a[i] = b[i] = 0; REPSZ(j, s[i]) if (s[i][j] == 'N') ++a[i]; else if (s[i][j] == 'B') ++b[i]; }
	amx = 0; REP(i, n) amx = max(amx, a[i]);
	bmx = 0; REP(i, n) bmx = max(bmx, b[i]);
	int xlo = 0, xhi = amx;
	while (xhi - xlo >= 1) {
		int xmi1 = xlo + (xhi - xlo) / 2, xmi2 = xmi1 + 1;
		int v1 = calc(xmi1).first, v2 = calc(xmi2).first;
		if (v1 <= v2) xhi = xmi2 - 1; else xlo = xmi1 + 1;
	}
	assert(xlo == xhi);
	int x = xlo, y, ret; tie(ret, y) = calc(x);
	//int x = 1, y = 1, ret = calc(x, y);
	int nochangecnt = 0;
	while (true) {
		bool change = false;
		FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx != 0 || dy != 0) {
			while (true) {
				int nx = x + dx, ny = y + dy; if (nx < 0 || ny < 0 || nx == 0 && ny == 0) break;
				int cur = calc(nx, ny);
				if (cur < ret) ret = cur, x = nx, y = ny, change = true;
				else if (cur == ret && rnd() % 2 == 0) x = nx, y = ny;
				else break;
			}
		}
		if (change) nochangecnt = 0; else ++nochangecnt;
		if (nochangecnt >= 10) break;
	}
	ans = string(x, 'N') + string(y, 'B');
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) cin >> s[i];
	printf("%d\n", solve());
	printf("%s\n", ans.c_str());
}

int main() {
	run();
	return 0;
}