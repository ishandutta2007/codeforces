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
const int MAXVAL = 2000;
const int MAXSUM = MAXN * MAXVAL;

int n;
int a[MAXN];
vector<int> ans;

void solve() {
	ans.clear();
	int sum = 0;
	REP(i, n) sum += a[i];
	if (sum % 2 != 0) return;
	vector<bool> can(sum / 2 + 1, false);
	can[0] = true;
	REP(i, n) for (int j = sum / 2; j >= a[i]; --j) if (can[j - a[i]]) can[j] = true;
	if (!can[sum / 2]) return;
	int g = a[0]; FOR(i, 1, n) g = gcd(g, a[i]);
	REP(i, n) if ((a[i] / g) % 2 != 0) { ans.PB(i); return; }
	assert(false);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}