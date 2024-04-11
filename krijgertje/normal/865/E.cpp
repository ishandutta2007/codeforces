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

const int MAXN = 14;

char s[MAXN + 1]; int n;
int diff[MAXN];
int mdiff[MAXN]; // modified difference after carry
ll p[MAXN + 1];

int decode(char c) { return isdigit(c) ? c - '0' : c - 'a' + 10; }
char encode(int x) { return x < 10 ? '0' + x : 'a' + x - 10; }

int mdiffsum[1 << MAXN];
ll dp[1 << MAXN];

ll solvefixedcarry() {
	//printf("solvefixedcarry:"); REP(i, n) printf(" %d", mdiff[i]); puts("");
	REP(i, 1 << n) dp[i] = -1; dp[0] = 0;
	mdiffsum[0] = 0; REP(i, n) REP(j, 1 << i) mdiffsum[j + (1 << i)] = mdiffsum[j] + mdiff[i];
	REP(i, 1 << n) if (dp[i] != -1) {
		int a = mdiffsum[i];
		REP(j, n) if ((i&(1 << j)) == 0) {
			int b = a + mdiff[j]; if (b < 0 || b >= 16) continue;
			int ii = i | (1 << j); ll nval = dp[i] + p[j] * a; if (dp[ii] != -1 && dp[ii] < nval) continue;
			dp[ii] = nval;
		}
	}
	return dp[(1 << n) - 1];
}

void run() {
	scanf("%s", s); n = strlen(s); reverse(s, s + n);
	REP(i, n) diff[i] = decode(s[i]);
	p[0] = 1; REP(i, n) p[i + 1] = p[i] * 16;
	ll ret = -1;
	REP(carrymask, 1 << (n - 1)) {
		int sum = 0; bool ok = true;
		REP(i, n) {
			mdiff[i] = diff[i];
			if (carrymask&(1 << i)) mdiff[i] -= 16;
			if (i != 0 && (carrymask&(1 << (i - 1)))) mdiff[i] += 1;
			sum += mdiff[i]; if (mdiff[i] <= -16 || mdiff[i] >= 16) ok = false;
		}
		//printf("%x: sum=%d / ", carrymask, sum); REP(i, n) printf(" %d", mdiff[i]); puts("");
		if (!ok || sum != 0) continue;
		ll cur = solvefixedcarry();
		if (cur != -1 && (ret == -1 || cur < ret)) ret = cur;
	}
	if (ret == -1) { printf("NO\n"); return; }
	REP(i, n) s[i] = encode(ret / p[i] % 16); reverse(s, s + n); printf("%s\n", s);
}

int main() {
	run();
	return 0;
}