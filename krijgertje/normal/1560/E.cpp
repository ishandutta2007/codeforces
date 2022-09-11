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

const int MAXLEN = 500000;

char s[MAXLEN + 1]; int slen;
char ans[MAXLEN + 1]; char ord[26 + 1];

int cnt[26];
bool done[26];

int ordpos[26];

bool solve() {
	REP(i, 26) cnt[i] = 0;
	REP(i, slen) ++cnt[s[i] - 'a'];
	int nord = 0;
	REP(i, 26) done[i] = false;
	for (int i = slen - 1; i >= 0; --i) {
		int x = s[i] - 'a';
		if (done[x]) continue;
		done[x] = true;
		ord[nord++] = 'a' + x;
	}
	ord[nord] = '\0';
	reverse(ord, ord + nord);
	int anslen = 0;
	REP(i, nord) {
		int x = ord[i] - 'a';
		int t = i + 1;
		if (cnt[x] % t != 0) return false;
		anslen += cnt[x] / t;
	}
	if (anslen > slen) return false;
	REP(i, anslen) ans[i] = s[i];
	ans[anslen] = '\0';
	REP(i, 26) ordpos[i] = -1;
	REP(i, nord) ordpos[ord[i] - 'a'] = i;
	int x = 0, len = anslen;
	REP(i, nord) {
		int y = x + len;
		REP(j, len) {
			char c = s[x + j];
			if (ordpos[c - 'a'] <= i) continue;
			if (y >= slen || s[y] != c) return false;
			++y;
		}
		x += len, len = y - x;
	}
	return x == slen;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	if (!solve()) { printf("-1\n"); return; }
	printf("%s %s\n", ans, ord);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}