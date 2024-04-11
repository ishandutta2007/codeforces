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

const int MAXN = 500000;

int n;
int ans[MAXN + 1];

int pmn[MAXN + 1];
pair<int, int> o[MAXN];

void solve() {
	REPE(i, n) pmn[i] = -1;
	FORE(i, 2, n) if (pmn[i] == -1) for (int j = i; j <= n; j += i) if(pmn[j]==-1) pmn[j] = i;

	o[0] = MP(1, 1); FORE(i, 2, n) o[i - 1] = MP(i / pmn[i], i);
	sort(o, o + n);
	FORE(i, 2, n) ans[i] = o[i - 1].first;
}


void run() {
	scanf("%d", &n);
	solve();
	FORE(i, 2, n) { if (i != 2) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}