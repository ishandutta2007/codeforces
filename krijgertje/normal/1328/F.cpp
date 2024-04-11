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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;

int n, need;
int a[MAXN];

int bval[MAXN], bcnt[MAXN], nb;

ll calc(int rem, int cnta, ll suma, int cntb, ll sumb) {
	//printf("rem=%d cnta=%d suma=%lld cntb=%d sumb=%lld\n", rem, cnta, suma, cntb, sumb);
	if (cnta >= rem) return suma - (cnta - rem);
	else return suma + sumb - (cnta + cntb - rem);
}

ll solve() {
	sort(a, a + n);
	int nb = 0;
	for (int l = 0, r = l; l < n; l = r) {
		int v = a[l];
		while (r < n&&a[r] == v) ++r;
		int cnt = r - l;
		bval[nb] = v, bcnt[nb] = cnt, ++nb;
	}
	int cntbefore = 0; ll sumbefore = 0;
	int cntafter = 0; ll sumafter = 0; REP(i, nb) cntafter += bcnt[i], sumafter += (ll)bval[i] * bcnt[i];
	ll ret = LLONG_MAX;
	REP(i, nb) {
		cntafter -= bcnt[i]; sumafter -= (ll)bval[i] * bcnt[i];
		if (bcnt[i] >= need) ret = min(ret, 0LL);
		if (bcnt[i] < need) {
			ll valbefore = (ll)cntbefore*bval[i] - sumbefore, valafter = sumafter - (ll)cntafter*bval[i];
			ret = min(ret, calc(need - bcnt[i], cntbefore, valbefore, cntafter, valafter));
			ret = min(ret, calc(need - bcnt[i], cntafter, valafter, cntbefore, valbefore));
		}
		cntbefore += bcnt[i]; sumbefore += (ll)bval[i] * bcnt[i];
		//printf("after %d: %lld\n", i, ret);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &need);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}