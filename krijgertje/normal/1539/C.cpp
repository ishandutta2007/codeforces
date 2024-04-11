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

const int MAXN = 200000;

int n; ll mxextra, mxdiff;
ll a[MAXN];

int solve() {
	vector<ll> need;
	sort(a, a + n);
	FOR(i, 1, n) if (a[i] - a[i - 1] > mxdiff) need.PB((a[i] - a[i - 1] - 1) / mxdiff);
	sort(need.begin(), need.end());
	int ret = SZ(need) + 1;
	ll rem = mxextra;
	REPSZ(i, need) if (rem >= need[i]) rem -= need[i], --ret;
	return ret;
}

void run() {
	scanf("%d%lld%lld", &n, &mxextra, &mxdiff);
	REP(i, n) scanf("%lld", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}