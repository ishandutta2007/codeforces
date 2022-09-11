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

const int MAXN = 100000;

int n;
int a[MAXN];
int nb; ll b[3];

void solve() {
	ll asum = 0; ll axor = 0; REP(i, n) asum += a[i], axor ^= a[i];
	nb = 0;
	if (axor != 0) { ll x = axor; b[nb++] = x; axor ^= x; asum += x; }
	assert(axor == 0 && asum % 2 == 0);
	if (asum != axor) { ll x = asum; b[nb++] = x; axor ^= x; asum += x; }
	assert(asum == 2 * axor);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", nb);
	REP(i, nb) { if (i != 0) printf(" "); printf("%lld", b[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}