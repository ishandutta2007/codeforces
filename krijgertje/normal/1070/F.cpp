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
char pview[MAXN][3];
int influence[MAXN];

int a[MAXN], na;
int b[MAXN], nb;
int c[MAXN], nc;
int d[MAXN], nd;

ll solve() {
	na = nb = nc = 0;
	int cnt = 0, nvote = 0; ll ret = 0;
	REP(i, n) {
		bool suppa = pview[i][0] == '1', suppb = pview[i][1] == '1';
		if (suppa && suppb) ++cnt, ret += influence[i], ++nvote;
		else if (suppa) a[na++] = influence[i];
		else if (suppb) b[nb++] = influence[i];
		else c[nc++] = influence[i];
	}
	sort(a, a + na); reverse(a, a + na);
	sort(b, b + nb); reverse(b, b + nb);
	sort(c, c + nc); reverse(c, c + nc);
	int addab = min(na, nb);
	REP(i, addab) cnt += 2, ret += a[i] + b[i], ++nvote;
	nd = 0; FOR(i, addab, na) d[nd++] = a[i]; FOR(i, addab, nb) d[nd++] = b[i]; REP(i, nc) d[nd++] = c[i];
	sort(d, d + nd); reverse(d, d + nd);
	int addd = min(nd, 2 * nvote - cnt);
	REP(i, addd) ++cnt, ret += d[i];
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s%d", pview[i], &influence[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}