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

const int MAXN = 100000;

int n;
vector<int> seq[MAXN];

vector<int> l, r;

ll solve() {
	l.clear(); r.clear();
	REP(i, n) {
		bool hasinc = false; FORSZ(j, 1, seq[i]) if (seq[i][j - 1] < seq[i][j]) hasinc = true; if (hasinc) continue;
		l.PB(seq[i][0]);
		r.PB(seq[i][SZ(seq[i]) - 1]);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	//printf("l:"); REPSZ(i, l) printf(" %d", l[i]); puts("");
	//printf("r:"); REPSZ(i, r) printf(" %d", r[i]); puts("");
	ll ret = (ll)n*n;
	int li = -1; // r[ri]>=l[li]
	REPSZ(ri, r) {
		while (li + 1 < SZ(l) && r[ri] >= l[li + 1]) ++li;
		ret -= li + 1;
		//printf("%d: %d\n", ri, li);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int len; scanf("%d", &len); seq[i] = vector<int>(len); REP(j, len) scanf("%d", &seq[i][j]); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}