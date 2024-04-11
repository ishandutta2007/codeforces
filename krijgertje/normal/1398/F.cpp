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

const int MAXN = 1000000;

int n;
char s[MAXN + 1];
int ans[MAXN + 1];

int a[2 * MAXN + 1], na;


void solve() {
	{
		na = 0;
		int at = 0; char last = 'x';
		while (true) {
			int nquestionmark = 0;
			while (at < n && s[at] == '?') ++nquestionmark, ++at;
			if (at < n && s[at] == last) {
				a[na - 1] += nquestionmark + 1;
				++at;
				continue;
			}
			a[na++] = nquestionmark;
			if (at >= n) break;
			a[na++] = 1;
			last = s[at];
			++at;
		}
	}

	FORE(i, 1, n) {
		for (int j = 1; j < na; j += 2) if (a[j - 1] + a[j] + a[j + 1] < i) a[j] = -1;
		for (int j = 2; j + 1 < na; j += 2) if (a[j - 1] == -1 && a[j + 1] == -1) a[j] = -1;
		int nna = 0; REP(j, na) if (a[j] != -1 || nna == 0 || a[nna - 1] != -1) a[nna++] = a[j]; na = nna;
		//printf("a:"); REP(j, na) printf(" %d", a[j]); puts("");

		ans[i] = 0;
		int at = 0, rem = a[at];
		while (true) {
			ans[i] += rem / i;
			rem %= i;
			++at;
			if (at >= na) break;
			if (at % 2 == 1) {
				if (a[at] == -1) {
					++at;
					rem = a[at];
				} else {
					rem += a[at];
				}
			} else {
				if (rem + a[at] >= i) {
					++ans[i];
					rem += a[at] - i;
				} else {
					rem = a[at];
				}
			}
		}
	}
}


void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}