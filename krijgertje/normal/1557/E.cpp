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

const int DIM = 8;

bool can[DIM][DIM];
int xme, yme;

bool ncan[DIM][DIM];
bool attack[DIM][DIM];

bool move(int xmove, int ymove) {
	xme = xmove, yme = ymove;
	printf("%d %d\n", xmove + 1, ymove + 1); fflush(stdout);
	string ans;
	cin >> ans;
	if (ans == "Done") return true;
	int dx, dy;
	if (ans == "Left") dx = 0, dy = -1;
	else if (ans == "Up-Left") dx = -1, dy = -1;
	else if (ans == "Up") dx = -1, dy = 0;
	else if (ans == "Up-Right") dx = -1, dy = +1;
	else if (ans == "Right") dx = 0, dy = +1;
	else if (ans == "Down-Right") dx = +1, dy = +1;
	else if (ans == "Down") dx = +1, dy = 0;
	else if (ans == "Down-Left") dx = +1, dy = -1;
	else assert(false);

	REP(x, DIM) REP(y, DIM) ncan[x][y] = false, attack[x][y] = x == xme || y == yme || x - y == xme - yme || x + y == xme + yme;
	REP(x, DIM) REP(y, DIM) if (can[x][y]) {
		int nx = x + dx, ny = y + dy;
		if (nx < 0 || nx >= DIM || ny < 0 || ny >= DIM || attack[nx][ny]) continue;
		ncan[nx][ny] = true;
	}
	REP(x, DIM) REP(y, DIM) can[x][y] = ncan[x][y];
	return false;
}

void solve() {
	REP(x, DIM) REP(y, DIM) can[x][y] = true;
	if (move(0, 0)) return;
	while (true) {
		//REP(x, DIM) { printf("%d: ", x); REP(y, DIM) printf("%c", can[x][y] ? 'V' : x == xme && y == yme ? '*' : '.'); puts(""); }
		int xto = -1, yto = -1;
		REP(x, DIM) REP(y, DIM) if (xto == -1 && yto==-1 && can[x][y]) xto = x, yto = y;
		assert(xto != -1 && yto != -1);
		assert(yme != yto);
		if (yme > yto) {
			if (move(xme, max(0, yto - 1))) return;
			continue;
		}
		assert(yme < yto && xme != xto);
		if (abs(xme - xto) > 1) {
			if (move(xto, yme)) return;
		} else {
			if (move(xto, yme + 1)) return;
		}
	}
}

void run() {
	solve();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}