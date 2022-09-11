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

const int MAXN = 400000;

int n;
char s[MAXN + 1];

int cnt[256];
int odd[256], nodd;

char ans[MAXN];

void run() {
	scanf("%d", &n); scanf("%s", s);
	
	REP(i, 256) cnt[i] = 0; REP(i, n) ++cnt[s[i]];
	nodd = 0; REP(i, 256) if (cnt[i] % 2 == 1) odd[nodd++] = i;
	FORE(npal, 1, n) if (n%npal == 0 && npal >= nodd && (nodd == 0 || n / npal % 2 == 1)) {
		int plen = n / npal;
		int atevn = plen == 1 ? npal : 0, atevnpos = 0, atodd = 0;
		REP(i, 256) {
			if (cnt[i] % 2 == 1) {
				assert(atodd < npal);
				ans[atodd*plen + (plen - 1) / 2] = (char)i;
				++atodd;
			}
			REP(j, cnt[i] / 2) {
				if (atevn < npal) {
					ans[atevn*plen + atevnpos] = ans[atevn*plen + plen - atevnpos - 1] = (char)i;
					++atevnpos;
					if (atevnpos >= plen / 2) ++atevn, atevnpos = 0;
				} else {
					assert(plen % 2 == 1 && atodd < npal&&atodd + 1 < npal);
					ans[atodd*plen + (plen - 1) / 2] = ans[atodd*plen + plen + (plen - 1) / 2] = (char)i;
					atodd += 2;
				}
			}
		}
		printf("%d\n", npal); REP(i, npal) { if (i != 0) printf(" "); printf("%.*s", plen, ans + i*plen); } puts("");
		return;
	}
	assert(false);
}

int main() {
	run();
	return 0;
}