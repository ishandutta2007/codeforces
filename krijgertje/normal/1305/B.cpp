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

const int MAXLEN = 1000;

char s[MAXLEN + 1]; int slen;
vector<vector<int>> ans;

void solve() {
	int nclose = 0; REP(i, slen) if (s[i] == ')') ++nclose;
	vector<int> cur;
	REP(i, slen) if (i < nclose && s[i] == '(') cur.PB(i); else if (i >= nclose && s[i] == ')') cur.PB(i);
	ans.clear(); if (SZ(cur) > 0) ans.PB(cur);
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { printf("%d\n", SZ(ans[i])); REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j] + 1); } puts(""); }
}

int main() {
	run();
	return 0;
}