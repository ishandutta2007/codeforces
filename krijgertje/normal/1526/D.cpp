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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

struct BIT {
	int n; vector<ll> val;
	BIT() {} BIT(int _n) { init(_n); }
	void init(int _n) { n = _n; val = vector<ll>(n + 1, 0); }
	void mod(int idx, ll by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
	ll get(int idx) { ++idx; ll ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
};

const int MAXLEN = 100000;
const char CHARS[] = "ANOT";

char s[MAXLEN + 1]; int slen;
char ans[MAXLEN + 1];

char t[MAXLEN + 1];

int a[MAXLEN], na;
int b[MAXLEN], nb;
int ainv[MAXLEN];

ll calc() {
	na = nb = 0;
	REP(i, slen) a[i] = b[i] = -1;
	REP(j, 4) REP(i, slen)  if (s[i] == CHARS[j]) a[i] = na++;
	REP(j, 4) REP(i, slen)  if (t[i] == CHARS[j]) b[i] = nb++;
	REP(i, slen) ainv[a[i]] = i;

	ll ret = 0;
	BIT bit(slen);
	REP(i, slen) {
		int j = ainv[b[i]];
		ret += i - bit.get(j);
		bit.mod(j, +1);
	}
	//printf("%s = %lld\n", t, ret);
	return ret;
}

void solve() {
	vector<int> cnt(4, 0);
	REP(i, slen) REP(j, 4) if (CHARS[j] == s[i]) ++cnt[j];
	vector<int> perm(4);
	REP(i, 4) perm[i] = i;
	ll best = -1;
	do {
		int tlen = 0;
		for (int i : perm) REP(j, cnt[i]) t[tlen++] = CHARS[i];
		t[tlen] = '\0';
		ll cur = calc();
		if (cur > best) {
			best = cur;
			REPE(i, tlen) ans[i] = t[i];
		}
	} while (next_permutation(perm.begin(), perm.end()));
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}