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

const int MAXLEN = 100000;

char s[MAXLEN + 1]; int slen;
int step;
char ans[MAXLEN + 1];

char a[MAXLEN + 1]; int alen;
char b[MAXLEN + 1];

bool calc() {
	REP(i, alen) b[i] = '1'; b[alen] = '\0';
	REP(i, alen) if (a[i] == '0') for (int di = -1; di <= +1; di += 2) { int ni = i + di; if (ni < 0 || ni >= alen) continue; b[ni] = '0'; }
	REP(i, alen) if (a[i] == '1') { bool ok = false; for (int di = -1; di <= +1; di += 2) { int ni = i + di; if (ni < 0 || ni >= alen) continue; if (b[ni] == '1') ok = true; } if (!ok) return false; }
	//printf("%s -> %s\n", a, b);
	return true;
}

bool solve() {
	REP(i, slen) ans[i] = '?'; ans[slen] = '\0';
	REP(i, step) {
		alen = 0;
		for (int x = i; x < slen; x += step) a[alen++] = s[x];
		a[alen] = '\0';
		if (!calc()) return false;
		REP(x, alen) ans[i + x * step] = b[x];
	}
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &step);
	if (!solve()) { printf("-1\n"); return; }
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}