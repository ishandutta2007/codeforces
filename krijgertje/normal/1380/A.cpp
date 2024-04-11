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

const int MAXN = 1000;

int n;
int a[MAXN];
int ans[3];

int pos[MAXN];

bool solve() {
	REP(i, n) pos[a[i]] = i;
	int l = 0, r = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (pos[i] == l) { ++l; continue; }
		if (pos[i] == r) { --r; continue; }
		ans[0] = pos[i] - 1;
		ans[1] = pos[i];
		ans[2] = pos[i] + 1;
		return true;
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d %d %d\n", ans[0] + 1, ans[1] + 1, ans[2] + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}