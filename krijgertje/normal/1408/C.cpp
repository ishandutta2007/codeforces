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
const double eps = 1e-9;

int n, len;
int a[MAXN];

double solve() {
	double t = 0;
	double x = 0, y = len; int xnxt = 0, ynxt = n - 1; int vx = 1, vy = 1;
	while (true) {
		//printf("t=%lf x=%lf y=%lf xnxt=%d ynxt=%d\n", t, x, y, xnxt, ynxt);
		if (xnxt > ynxt) {
			t += (y - x) / (vx + vy);
			return t;
		}
		double dt = min((a[xnxt] - x) / vx, (y - a[ynxt]) / vy);
		x += dt * vx;
		y -= dt * vy;
		t += dt;
		if (x >= a[xnxt] - eps) ++xnxt, ++vx;
		if (y <= a[ynxt] + eps) --ynxt, ++vy;
	}
}

void run() {
	scanf("%d%d", &n, &len);
	REP(i, n) scanf("%d", &a[i]);
	printf("%.15lf\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}