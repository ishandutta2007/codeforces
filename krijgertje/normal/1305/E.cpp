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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 5000;

int n, want;
int ans[MAXN];

bool solve() {
	int k = 1;
	int mx = 0;
	while (mx < want) mx += k / 2, ++k;
	if (k > n) return false;
	REP(i, k) ans[i] = i + 1;
	int excess = mx - want;
	ans[k - 1] += 2 * excess;
	int L = 2 * ans[k - 1];
	REP(i, n - k) ans[k + i] = (2 * i + 1) * L;
	return true;
}

void verify() {
	REP(i, n) assert(ans[i] >= 1 && ans[i] <= 1000000000);
	REP(i, n - 1) assert(ans[i] < ans[i + 1]);
	set<int> seen; REP(i, n) seen.insert(ans[i]);
	int have = 0; REP(i, n) FOR(j, i + 1, n) if (seen.count(ans[i] + ans[j])) ++have; assert(have == want);
}

void run() {
	scanf("%d%d", &n, &want);
	if (!solve()) { printf("-1\n"); return; }
	//verify();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}