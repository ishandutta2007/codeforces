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

int n; char s[MAXN - 1 + 1];
int mnans[MAXN];
int mxans[MAXN];

int b[MAXN];

void solve() {
	b[0] = 0;
	REP(i, n - 1) b[i + 1] = b[i] + (s[i] == '>' ? 0 : 1);
	for (int l = 0, r = l; l < n; l = r) {
		int c = b[l]; while (r < n && b[r] == b[l]) ++r;
		int cnt = r - l; REP(i, cnt) mxans[l + i] = l + cnt - i - 1;
	}
	b[0] = 0;
	REP(i, n - 1) b[i + 1] = b[i] + (s[i] == '<' ? 0 : 1);
	for (int l = 0, r = l; l < n; l = r) {
		int c = b[l]; while (r < n && b[r] == b[l]) ++r;
		int cnt = r - l; REP(i, cnt) mnans[l + i] = n - l - cnt + i;
	}
}

void run() {
	scanf("%d%s", &n, s); assert(strlen(s) == n - 1);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", mnans[i] + 1); } puts("");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", mxans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}