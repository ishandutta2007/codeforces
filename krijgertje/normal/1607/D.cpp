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

int n;
int a[MAXN];
char s[MAXN + 1];

bool solve() {
	vector<int> dec, inc;
	REP(i, n) if (s[i] == 'B') dec.PB(a[i]); else inc.PB(a[i]);
	sort(dec.begin(), dec.end());
	sort(inc.begin(), inc.end());
	//printf("dec:"); REPSZ(i, dec) printf(" %d", dec[i]); puts("");
	//printf("inc:"); REPSZ(i, inc) printf(" %d", inc[i]); puts("");
	REPSZ(i, dec) if (dec[i] < i + 1) return false;
	REPSZ(i, inc) if (inc[i] > SZ(dec) + i + 1) return false;
	return true;

}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%s", s);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}