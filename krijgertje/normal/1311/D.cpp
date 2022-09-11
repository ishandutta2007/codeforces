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

int a, b, c;
int ans;
int A, B, C;

void calc(int bb) {
	int cur = abs(b - bb);
	if (cur >= ans) return;
	int tc = c / bb * bb;
	assert(tc <= c && tc + bb > c);
	int cc = tc == 0 || tc + bb - c < c - tc ? tc + bb : tc;
	cur += abs(c - cc);
	if (cur >= ans) return;
	int aa = -1;
	for (int i = 1; i*i <= bb; ++i) if (bb%i == 0) {
		if (aa == -1 || abs(i - a) < abs(aa - a)) aa = i;
		if (aa == -1 || abs(bb / i - a) < abs(aa - a)) aa = bb / i;
	}
	cur += abs(a - aa);
	if (cur >= ans) return;
	ans = cur, A = aa, B = bb, C = cc;
}

void solve() {
	ans = INT_MAX;
	bool stopneg = false;
	bool stoppos = false;
	for (int db = 0;!stopneg||!stoppos; ++db) {
		if (!stopneg && db != 0) {
			int bb = b - db;
			if (bb < 1) stopneg = true; else calc(bb);
		}
		if (!stoppos) {
			int bb = b + db;
			calc(bb);
			if (bb >= c&&bb%a == 0) stoppos = true;
		}
	}
}

void run() {
	scanf("%d%d%d", &a, &b, &c);
	solve();
	printf("%d\n", ans);
	printf("%d %d %d\n", A, B, C);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}