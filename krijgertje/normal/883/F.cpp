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

const int MAXN = 400;
const int MAXLEN = 20;

int n;
char s[MAXN][MAXLEN + 1];

char t[2 * MAXLEN + 1]; int tlen;

set<string> all;


void run() {
	scanf("%d", &n); REP(i, n) scanf("%s", s[i]);

	all.clear();
	REP(i, n) {
		int slen = strlen(s[i]);
		tlen = 0;
		REP(j, slen) {
			char c = s[i][j];
			if (c == 'u') { t[tlen++] = 'o'; t[tlen++] = 'o'; continue; }
			if (c == 'h') while (tlen >= 1 && t[tlen - 1] == 'k') --tlen;
			t[tlen++] = c;
		}
		t[tlen] = '\0';
		all.insert(t);
	}
	printf("%d\n", SZ(all));
}

int main() {
	run();
	return 0;
}