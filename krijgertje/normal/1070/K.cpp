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

const int MAXN = 100000;

int n, nparts;
int a[MAXN];
int ans[MAXN];

bool solve() {
	ll sum = 0; REP(i, n) sum += a[i]; if (sum%nparts != 0) return false; ll each = sum / nparts;
	int at = 0, cnt = 0; ll rem = each;
	REP(i, n) {
		if (a[i] > rem) return false;
		rem -= a[i], ++cnt;
		if (rem == 0) ans[at++] = cnt, cnt = 0, rem = each;
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &nparts);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i, nparts) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}