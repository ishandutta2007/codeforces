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
int ans3, ans5, ans7;

bool solve() {
	ans3 = ans5 = ans7 = 0;
	if (n == 1 || n == 2 || n == 4) return false;
	ans3 = n / 3;
	int rem = n % 3;
	if (rem == 1) { assert(ans3 >= 2); ans3 -= 2, ++ans7; } else if (rem == 2) { assert(ans3 >= 1); --ans3, ++ans5; }
	return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d %d %d\n", ans3, ans5, ans7);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}