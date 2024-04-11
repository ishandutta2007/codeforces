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

const int MAXN = 100000;
const int MAXP = 6;

int n;
char s[MAXN + 1];

int p[MAXP], np;
int val[MAXN];

bool solve() {
	{ int x = n; np = 0; for (int i = 2; i*i <= x; ++i) if (x%i == 0) { p[np++] = i; while (x%i == 0) x /= i; } if (x != 1) p[np++] = x; }
	//printf("p:"); REP(i, np) printf(" %d", p[i]); puts("");

	REP(j, n) val[j] = s[j] - '0';
	REP(i, np) {
		int a = n / p[i], b = p[i], c = 1; while (a%p[i] == 0) a /= p[i], b *= p[i], c *= p[i];
		REP(off, c) for (int j = off; j < n; j += b) {
			//printf("p%d off=%d j=%d a=%d b=%d\n", p[i], off, j, a, b);
			int by = -val[j];
			REP(k, p[i]) { int idx = (j + k*a*c) % n; val[idx] += by; }
		}
		//printf("val:"); REP(j, n) printf(" %d", val[j]); puts("");
	}
	bool ok = true; REP(j, n) if (val[j] != 0) ok = false; return ok;
}

void run() {
	scanf("%d", &n); scanf("%s", s);
	printf("%s\n", solve() ? "YES" : "NO");
}

void stress() {
	//n = 3960; REP(i, n) s[i] = '0' + rand() % 10;
	REP(rep, 1000) {
		n = 4*9*5*7;
		REP(i, n) s[i] = '0'; s[n] = '\0';
		vector<int> d; FOR(i, 1, n) if (n%i == 0) d.PB(i);
		int times = rand() % (2 * n);
		REP(it, times) {
			int idx = rand() % SZ(d);
			int off = rand() % d[idx];
			bool ok = true; REP(i, n / d[idx]) if (s[off + d[idx] * i] == '9') ok = false; if (!ok) continue;
			REP(i, n / d[idx]) ++s[off + d[idx] * i];
		}
		printf("%s\n", s);
		bool have = solve();
		if (have) { printf("."); continue; }
		printf("err\n"); break;
	}

}


int main() {
	run();
	//stress();
	return 0;
}