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

int n;

bool solve() {
	if (n % 2 == 1) return false;
	int cnt = 0;
	int x = n;
	while (x % 2 == 0) x /= 2, ++cnt;
	if(x == 1 && cnt % 2 == 1) return false;
	return true;
}

void run() {
	scanf("%d", &n);
	printf("%s\n", solve() ? "Alice" : "Bob");
}

void research() {
	int lim = 10000;
	vector<bool> win(lim + 1);
	FORE(i, 1, lim) {
		win[i] = false;
		for (int j = 2; j < i; ++j) if (i % j == 0 && !win[i - j]) { win[i] = true; break; }
	}
	FORE(i, 1, lim) if (win[i] != (i % 2 == 0)) printf("%d: %s\n", i, win[i] ? "WIN" : "LOSE");
}

int main() {
	//research();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}