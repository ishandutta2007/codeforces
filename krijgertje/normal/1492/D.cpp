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

const int MAXLEN = 200000;

int nzero, none, nwant;
char a[MAXLEN + 1];
char b[MAXLEN + 1];

bool solve() {
	assert(none >= 1);
	if (nwant == 0) {
		int at = 0;
		REP(i, none) a[at] = b[at] = '1', ++at;
		REP(i, nzero) a[at] = b[at] = '0', ++at;
		a[at] = b[at] = '\0';
		return true;
	} else {
		if (none < 2 || nzero < 1 || nwant >= nzero + none - 1) return false;
		int at = 0;
		a[at] = b[at] = '1', ++at;
		int remone = none - 2;
		int remzero = nzero - 1;
		int to = nzero + none - nwant - 1;
		while (at < to && remone>0) a[at] = b[at] = '1', ++at, --remone;
		while (at < to && remzero>0) a[at] = b[at] = '0', ++at, --remzero;
		a[at] = '1', b[at] = '0', ++at;
		to = nzero + none - 1;
		while (at < to && remone>0) a[at] = b[at] = '1', ++at, --remone;
		while (at < to && remzero>0) a[at] = b[at] = '0', ++at, --remzero;
		a[at] = '0', b[at] = '1', ++at;
		a[at] = b[at] = '\0';
		return true;
	}
}

void run() {
	scanf("%d%d%d", &nzero, &none, &nwant);
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	printf("%s\n", a);
	printf("%s\n", b);
}

int main() {
	run();
	return 0;
}