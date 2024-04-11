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

const int MAXN = 200000;

int n;
char s[MAXN + 1];
int ans[MAXN];

int who[26];

int solve() {
	int ret = 0;
	REP(i, 26) who[i] = -1;
	REP(i, n) {
		int x = s[i] - 'a';
		int idx = x; while (idx >= 0 && who[idx] == -1) --idx;
		if (idx >= 0) {
			if (idx != x) {
				who[x] = who[idx];
				who[idx] = -1;
			}
		} else {
			who[x] = ret++;
		}
		//printf("%d: x=%d idx=%d who[x]=%d\n", i, x, idx, who[x]);
		ans[i] = who[x];
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	int res = solve();
	printf("%d\n", res);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}