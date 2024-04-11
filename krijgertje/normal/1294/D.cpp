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

const int MAXQ = 400000;
const int MAXMOD = 400000;

int nq, mod;
int q[MAXQ], qans[MAXQ];

int cnt[MAXMOD];

void solve() {
	REP(i, mod) cnt[i] = 0;
	int cur = 0, at = 0, need = 1;
	REP(i, nq) {
		int x = q[i] % mod;
		++cnt[x];
		while (cnt[at] >= need) {
			++at, ++cur; if (at >= mod) at = 0, ++need;
		}
		qans[i] = cur;
	}
}

void run() {
	scanf("%d%d", &nq, &mod);
	REP(i, nq) scanf("%d", &q[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}