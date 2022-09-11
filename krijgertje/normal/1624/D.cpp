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

const int MAXN = 200000;
const int ALPH = 26;

int n, ncol;
char s[MAXN + 1];

int cnt[ALPH];

int solve() {
	REP(i, ALPH) cnt[i] = 0;
	REP(i, n) ++cnt[s[i] - 'a'];
	int npair = 0, nsingle = 0;
	REP(i, ALPH) npair += cnt[i] / 2, nsingle += cnt[i] % 2;
	int eachpair = npair / ncol;
	nsingle += (npair % ncol) * 2;
	int eachsingle = min(1, nsingle / ncol);
	return 2 * eachpair + eachsingle;
}

void run() {
	scanf("%d%d", &n, &ncol);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}