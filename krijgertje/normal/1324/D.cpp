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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;

int n;
int a[MAXN];
int b[MAXN];

int c[MAXN];

ll solve() {
	REP(i, n) c[i] = a[i] - b[i];
	sort(c, c + n);
	int at = 0; ll ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (at < i && c[at] + c[i] <= 0) ++at;
		//printf("%d: c=%d at=%d\n", i, c[i], at);
		ret += max(0, i - at);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}