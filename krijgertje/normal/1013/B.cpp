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
const int MAXVAL = 100000;

int n,op;
int a[MAXN];
int cnt[MAXVAL + 1];
int cnt2[MAXVAL + 1];

void run() {
	scanf("%d%d", &n, &op);
	REP(i, n) scanf("%d", &a[i]);

	memset(cnt, 0, sizeof(cnt));
	REP(i, n) ++cnt[a[i]];
	REPE(i, MAXVAL) if (cnt[i] >= 2) { printf("0\n"); return; }
	REP(i, n) if ((a[i] & op) != a[i] && cnt[a[i] & op] != 0) { printf("1\n"); return; }
	memset(cnt2, 0, sizeof(cnt2));
	REP(i, n) if ((a[i] & op) != a[i]) ++cnt2[a[i] & op];
	REPE(i, MAXVAL) if (cnt2[i] >= 2) { printf("2\n"); return; }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}