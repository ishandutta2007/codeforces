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

const int MAXN = 200000;

int n, bsz; ll thave;
int a[MAXN];

pair<int,int> solve() {
	int mn = a[0], mx = a[0]; FOR(i, 1, n) mn = min(mn, a[i]), mx = max(mx, a[i]);
	int l = mn, r = mx; r = (int)min((ll)r, thave); l = min(l, r);
	int retval = -1, retcnt = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		int cnt = 0; ll t = 0, bsum = 0; int bcnt = 0; bool fits = true;
		REP(i, n) if (a[i] <= m) {
			if (t + a[i] > thave) { fits = false;  break; }
			t += a[i], bsum += a[i], ++cnt, ++bcnt;
			if (bcnt < bsz) continue;
			if (t + bsum > thave) { fits = false;  break; }
			t += bsum, bsum = 0, bcnt = 0;
		}
		if (cnt > retcnt) retcnt = cnt, retval = m;
		if (fits) l = m + 1; else r = m - 1;
	}
	return MP(retcnt, retval);
}

void run() {
	scanf("%d%d%lld", &n, &bsz, &thave);
	REP(i, n) scanf("%d", &a[i]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run();
	return 0;
}