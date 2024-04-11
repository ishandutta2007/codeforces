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

const int MAXH = 100;
const int MAXW = 100;

int h, w;
int a[MAXH][MAXW];

bool solve() {
	REPE(d, h + w - 2) {
		int sum = 0;
		REP(x, h) {
			int y = d - x;
			if (y < 0 || y >= w) continue;
			sum ^= a[x][y];
		}
		if (sum != 0) return true;
	}
	return false;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	printf("%s\n", solve() ? "Ashish" : "Jeel");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}