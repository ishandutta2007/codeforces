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

const int MAXN = 100000;

int n;
int commandt[MAXN];
int commandx[MAXN];

int solve() {
	int t = 0, x = 0, dx = 0, tmove = 0, ret = 0;
	REP(i, n) {
		int dt = commandt[i] - t;
		int steps = min(tmove, dt);
		x += dx * steps;
		tmove -= steps;
		t += dt;
		if (tmove == 0) {
			tmove = abs(commandx[i] - x);
			dx = tmove == 0 ? 0 : (commandx[i] - x) / tmove;
		}
		int limsteps = i + 1 < n ? min(tmove, commandt[i + 1] - t) : tmove;
		int a = x, b = x + limsteps * dx;
		if (a > b) swap(a, b);
		if (a <= commandx[i] && commandx[i] <= b) ++ret;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &commandt[i], &commandx[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i,1,ncase) run();
	return 0;
}