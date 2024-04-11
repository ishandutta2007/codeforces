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


// r[i+1]-l[i+1]+c[j]-1+2*(j-i)+sum(k=i+1..j-1,(l[i+1]-1)+abs(c[i]-r[i+1])) assuming l[k]!=r[k] for k=i+1..j-1
// let f[x]=sum(k=0..x,abs(l[i+1]-1),abs(c[i]-r[i+1])) -> r[i+1]-l[i+1]+c[j]+2*(j-i)+f[j-1]-f[i] = c[j]-1+2*j+f[j-1] + r[i+1]-l[i+1]-2*i-f[i]

const int MAXN = 100000;

int n;
int c[MAXN];
int a[MAXN];
int b[MAXN];

int l[MAXN];
int r[MAXN];
ll f[MAXN];

ll solve() {
	REP(i, n) l[i] = min(a[i], b[i]), r[i] = max(a[i], b[i]);
	REP(i, n - 1) { f[i] = (ll)abs(l[i + 1] - 1) + abs(c[i] - r[i + 1]); if (i - 1 >= 0) f[i] += f[i - 1]; }
	//printf("f:"); REP(i, n - 1) printf(" %lld", f[i]); puts("");
	ll ret = 0;
	ll best = LLONG_MIN;
	REP(i, n) {
		if (best != LLONG_MIN) {
			ll cur = (ll)c[i] - 1 + 2 * i + f[i - 1] + best;
			//printf("ans%d: %lld\n", i, cur);
			ret = max(ret, cur);
		}
		if (l[i + 1] == r[i + 1]) best = LLONG_MIN;
		if (i + 1 < n) {
			ll opt = (ll)r[i + 1] - l[i + 1] - 2 * i - f[i];
			//printf("opt%d: %lld\n", i, opt);
			best = max(best, opt);
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &c[i]);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}