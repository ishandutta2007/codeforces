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

const int MAXN = 100;

int n;


void solve() {
	vector<vector<pair<int, int>>> rem(2);
	REP(i, n) REP(j, n) { int z = (i + j) % 2; rem[z].PB(MP(i, j)); }
	REP(i, n * n) {
		int forbidden; scanf("%d", &forbidden); --forbidden;
		int x = -1, y = -1, col = -1;
		REP(z, 2) {
			if (SZ(rem[1 - z]) == 0) {
				x = rem[z].back().first, y = rem[z].back().second; rem[z].pop_back();
				col = forbidden != z ? z : 2;
				break;
			} else if (z != forbidden && SZ(rem[z]) != 0) {
				x = rem[z].back().first, y = rem[z].back().second; rem[z].pop_back();
				col = z;
				break;
			}
		}
		assert(x != -1 && y != -1 && col != -1);
		printf("%d %d %d\n", col + 1, x + 1, y + 1); fflush(stdout);
	}
}

void run() {
	scanf("%d", &n);
	solve();
}

int main() {
	run();
	return 0;
}