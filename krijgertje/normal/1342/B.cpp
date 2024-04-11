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

const int MAXSLEN = 100;

char s[MAXSLEN + 1]; int slen;
char ans[2 * MAXSLEN + 1]; int anslen;

void solve() {
	bool allsame = true; FOR(i, 1, slen) if (s[i] != s[0]) allsame = false;
	if (allsame) { 
		anslen = 0; REP(i, slen) ans[anslen++] = s[i]; ans[anslen] = '\0'; 
	} else {
		anslen = 0; REP(i, slen) ans[anslen++] = '0', ans[anslen++] = '1'; ans[anslen] = '\0';
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}