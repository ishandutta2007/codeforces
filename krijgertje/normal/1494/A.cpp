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

const int MAXN = 50;

char s[MAXN + 1]; int n;

int bal[MAXN + 1];

bool solve() {
	assert(n % 2 == 0);
	//printf("%s (%d)\n", s, n);
	char fst = s[0], lst = s[n - 1];
	if (fst == lst) return false;
	char oth = 'A' ^ 'B' ^ 'C' ^ fst ^ lst;
	int nfst = 0, nlst = 0, noth = 0;
	REP(i, n) if (s[i] == fst) ++nfst; else if (s[i] == lst) ++nlst; else if (s[i] == oth) ++noth; else assert(false);
	//printf("%c %d %c %d %c %d\n", fst, nfst, lst, nlst, oth, noth);

	int vfst = +1, vlst = -1, voth = nfst <= nlst ? +1 : -1;
	bal[0] = 0; REP(i, n) bal[i + 1] = bal[i] + (s[i] == fst ? vfst : s[i] == lst ? vlst : voth);
	//printf("bal:"); REPE(i, n) printf(" %d", bal[i]); puts("");
	REPE(i, n) if (bal[i] < 0) return false;
	return bal[n] == 0;
}

void run() {
	scanf("%s", s); n = strlen(s);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}