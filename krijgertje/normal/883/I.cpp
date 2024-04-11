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

const int MAXN = 300000;

int n, minsz;
int a[MAXN];

int nxt[MAXN];
int delta[MAXN + 2]; int cur;

bool can(int dmx) {
	// [i+sz..nxt[i]]
	int at = 0;
	REP(i, n) { while (at < n&&a[at] - a[i] <= dmx) ++at; nxt[i] = at; }
	
	REPE(i, n + 1) delta[i] = 0; cur = 0; ++delta[0]; --delta[1];
	REP(i, n) {
		cur += delta[i];
		if (cur > 0) {
			int l = i + minsz, r = nxt[i];
			if (l <= r) ++delta[l], --delta[r + 1];
		}
	}
	cur += delta[n]; return cur > 0;
}

void run() {
	scanf("%d%d", &n, &minsz);
	REP(i, n) scanf("%d", &a[i]);
	
	sort(a, a + n);
	int l = -1, r = a[n - 1] - a[0];
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (can(m)) r = m; else l = m;
	}
	printf("%d\n", r);
}

int main() {
	run();
	return 0;
}