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
#include <functional>
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 18;
const int MAXQ = 200000;

int n;
int a[1 << MAXN];
int nq;
int qbit[MAXQ];
ll qans[MAXQ];

ll sum[2 << MAXN];
vector<ll> inside[2 << MAXN], pref[2 << MAXN], suff[2 << MAXN];

void solve() {
	{
		int offset = 1 << n;
		REP(i, 1 << n) {
			sum[offset + i] = a[i];
			inside[offset + i] = pref[offset + i] = suff[offset + i] = vector<ll>(1, max(0LL, (ll)a[i]));
		}
	}
	REP(bit, n) {
		int offset = 1 << (n - bit - 1);
		REP(i, 1 << (n - bit - 1)) {
			int me = offset + i, l = 2 * me, r = 2 * me + 1;
			sum[me] = sum[l] + sum[r];
			inside[me] = pref[me] = suff[me] = vector<ll>(2 << bit);
			REP(mask, 1 << bit) {
				inside[me][mask] = max(max(inside[l][mask], inside[r][mask]), suff[l][mask] + pref[r][mask]);
				inside[me][mask | (1 << bit)] = max(max(inside[l][mask], inside[r][mask]), suff[r][mask] + pref[l][mask]);
				pref[me][mask] = max(pref[l][mask], sum[l] + pref[r][mask]);
				pref[me][mask | (1 << bit)] = max(pref[r][mask], sum[r] + pref[l][mask]);
				suff[me][mask] = max(suff[r][mask], sum[r] + suff[l][mask]);
				suff[me][mask | (1 << bit)] = max(suff[l][mask], sum[l] + suff[r][mask]);
			}
			//printf("bit=%d idx=%d:\n", bit, i);
			//printf("\tinside:"); REP(mask, 2 << bit) printf(" %lld", inside[me][mask]); puts("");
			//printf("\tpref:"); REP(mask, 2 << bit) printf(" %lld", pref[me][mask]); puts("");
			//printf("\tsuff:"); REP(mask, 2 << bit) printf(" %lld", suff[me][mask]); puts("");
		}
	}
	int curmask = 0;
	REP(i, nq) {
		curmask ^= 1 << qbit[i];
		qans[i] = inside[1][curmask];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, 1 << n) scanf("%d", &a[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qbit[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}