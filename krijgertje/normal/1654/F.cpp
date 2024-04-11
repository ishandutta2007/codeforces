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
const int ALPH = 26;

int n;
char s[1 << MAXN + 1];
char ans[1 << MAXN + 1];

int val[1 << MAXN], nval;
int pos[1 << MAXN];
int lst[1 << MAXN];
int tmp[1 << MAXN];
int cnt[1 << MAXN];


void solve() {
	//printf("s:%s\n", s);
	vector<int> scnt(ALPH, 0);
	REP(i, 1 << n) val[i] = s[i] - 'a';
	REP(i, 1 << n) ++scnt[val[i]];
	FOR(i, 1, ALPH) scnt[i] += scnt[i - 1];
	for (int i = (1 << n) - 1; i >= 0; --i) pos[i] = --scnt[val[i]];
	REP(i, 1 << n) lst[pos[i]] = i;
	nval = 0; REP(i, 1 << n) tmp[lst[i]] = i != 0 && val[lst[i]] == val[lst[i - 1]] ? nval - 1 : nval++;
	REP(i, 1 << n) val[i] = tmp[i];
	//printf("lst:"); REP(i, 1 << n) printf(" %d", lst[i]); puts("");
	//printf("val:"); REP(i, 1 << n) printf(" %d", val[i]); puts("");

	//printf("initially:\n"); REP(i, 1 << n) { printf("\t"); REP(j, 1 << n) printf("%c", s[lst[i] ^ j]); puts(""); }
	REP(bit, n) {
		REP(i, nval) cnt[i] = 0;
		REP(i, 1 << n) ++cnt[val[i]];
		FOR(i, 1, nval) cnt[i] += cnt[i - 1];
		//printf("cnt:"); REP(i, nval) printf(" %d", cnt[i]); puts("");
		for (int i = (1 << n) - 1; i >= 0; --i) pos[lst[i]] = --cnt[val[lst[i] ^ (1 << bit)]];
		//printf("cnt:"); REP(i, nval) printf(" %d", cnt[i]); puts("");
		//printf("pos:"); REP(i, 1 << n) printf(" %d", pos[i]); puts("");
		REP(i, 1 << n) lst[pos[i]] = i;
		REP(i, 1 << n) pos[lst[i]] = cnt[val[lst[i]]]++;
		REP(i, 1 << n) lst[pos[i]] = i;
		nval = 0; REP(i, 1 << n) tmp[lst[i]] = i != 0 && val[lst[i]] == val[lst[i - 1]] && val[lst[i] ^ (1 << bit)] == val[lst[i - 1] ^ (1 << bit)] ? nval - 1 : nval++;
		REP(i, 1 << n) val[i] = tmp[i];
		//printf("after bit %d:\n", bit); REP(i, 1 << n) { printf("\t"); REP(j, 1 << n) printf("%c", s[lst[i] ^ j]); puts(""); }
	}

	int x = lst[0];
	REP(i, 1 << n) ans[i] = s[i ^ x];
	ans[1 << n] = '\0';

	/*



	vector<int> opt;
	REP(i, 1 << n) opt.PB(i);
	REP(i, 1 << n) {
		char c = '?';
		vector<int> nopt;
		for (int x : opt) {
			int y = x ^ i;
			char cc = s[y];
			//printf("\t%d -> %d -> %c\n", x, y, cc);
			if (c == '?') { c = cc; nopt.PB(x); continue; }
			if (cc < c) { c = cc; nopt.clear(); nopt.PB(x); continue; }
			if (cc == c) { nopt.PB(x); continue; }
		}
		ans[i] = c;
		opt = nopt;
		printf("%c:", c); for (int x : opt) printf(" %d", x); puts("");
	}
	ans[1 << n] = '\0';*/
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	solve();
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}