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

const int MAXN = 5000;

int n;
char s[MAXN + 1];
char ans[MAXN + 1];
int kans;

char tmp[MAXN + 1];

void solve() {
	kans = 1; REPE(i, n) ans[i] = s[i];
	FORE(k, 2, n) {
		REPE(i, n - k) tmp[i] = s[i + k - 1];
		REP(i, k - 1) tmp[n - k + 1 + i] = s[i];
		tmp[n] = '\0';
		if ((n - k + 1) % 2 == 1) reverse(tmp + n - k + 1, tmp + n);
		REP(i, n) if (tmp[i] != ans[i]) { if (tmp[i] < ans[i]) { kans = k; REP(j, n) ans[j] = tmp[j]; } break; }
	}
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	solve();
	printf("%s\n", ans);
	printf("%d\n", kans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}