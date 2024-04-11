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


int nhour, nmin;
int h, m;

// 0 1 2-5 8
int flip[10] = { 0,1,5,-1,-1,2,-1,-1,8,-1 };

bool correct() {
	int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
	if (flip[a] == -1) return false;
	if (flip[b] == -1) return false;
	if (flip[c] == -1) return false;
	if (flip[d] == -1) return false;
	int x = 10 * flip[d] + flip[c], y = 10 * flip[b] + flip[a];
	if (x >= nhour || y >= nmin) return false;
	return true;
}

void solve() {
	while (!correct()) {
		if (++m >= nmin) {
			m = 0;
			if (++h >= nhour) {
				h = 0;
			}
		}
	}
}

void run() {
	scanf("%d%d", &nhour, &nmin);
	scanf("%d:%d", &h, &m);
	solve();
	printf("%02d:%02d\n", h, m);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}