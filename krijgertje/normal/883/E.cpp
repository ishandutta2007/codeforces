#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXLEN = 50;
const int MAXDICT = 1000;

int len, ndict;
char s[MAXLEN + 1];
char w[MAXDICT][MAXLEN + 1];

int have[26];
bool can[26];
int contain[26];

void run() {
	scanf("%d", &len); scanf("%s", s);
	scanf("%d", &ndict); REP(i, ndict) scanf("%s", w[i]);

	REP(k, 26) have[k] = 0; REP(j, len) if (s[j] != '*') ++have[s[j] - 'a'];
	REP(k, 26) can[k] = have[k] == 0;
	REP(i, ndict) {
		bool ok = true;
		REP(k, 26) contain[k] = 0; REP(j, len) { ++contain[w[i][j] - 'a']; if (s[j] != '*'&&w[i][j] != s[j]) ok = false; }
		REP(k, 26) if (have[k] != 0 && contain[k] != have[k]) ok = false;
		if (!ok) continue;
		REP(k, 26) if (contain[k] == 0) can[k] = false;
	}
	int ret = 0; REP(k, 26) if (can[k]) ++ret; printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}