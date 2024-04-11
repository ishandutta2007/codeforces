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
int ans[4];

bool solve() {
	ans[0] = 6, ans[1] = 10, ans[2] = 14, ans[3] = n - ans[0] - ans[1] - ans[2];
	if (ans[3] < 1) return false;
	if (ans[3] == ans[0] || ans[3] == ans[1] || ans[3] == ans[2]) ++ans[2], --ans[3];
	return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, 4) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}