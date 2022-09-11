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
const int MAXBIT = 59;

ll want; int n;
ll have[MAXN];

int wantbit[MAXBIT + 1];
int havebit[MAXBIT + 1];


int solve() {
	REPE(b, MAXBIT) wantbit[b] = (want >> b) & 1;
	REPE(b, MAXBIT) havebit[b] = 0;
	REP(i, n) REPE(b, MAXBIT) if (have[i] == (1LL << b)) ++havebit[b];
	int ret = 0, carry = 0;
	REPE(b, MAXBIT) {
		int sofar = max(0, carry) + havebit[b];
		int target = wantbit[b] + max(0, -carry);
		int delta = sofar - target;
		if (delta>=0) {
			carry = delta / 2;
		} else {
			assert(delta >= -2);
			carry = -1;
			++ret;
		}
	}
	if (carry < 0) return -1;
	return ret;
}

void run() {
	scanf("%lld%d", &want, &n);
	REP(i, n) scanf("%lld", &have[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}