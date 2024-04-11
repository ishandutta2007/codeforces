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
#include <functional>
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

const int MAXN = 40000;

int n;
int b[MAXN];
int a[MAXN];

bool solve() {
	ll tsum = 0;
	REP(i, n) tsum += b[i];
	ll tden = (ll)n * (n + 1) / 2;
	//printf("%lld/%lld\n", tsum, tden);
	if (tsum % tden != 0) return false;
	int sum = tsum / tden;
	//printf("->%d\n", sum);
	REP(i, n) {
		int num = sum - b[i] + b[(i + n - 1) % n];
		//printf("\t%d: %d/%d\n", i, num, n);
		if (num % n != 0) return false;
		a[i] = num / n;
	}
	REP(i, n) if (a[i] <= 0) return false;
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}