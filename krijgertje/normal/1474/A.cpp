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

const int MAXN = 100000;

int n;
char b[MAXN + 1];
char a[MAXN + 1];

void solve() {
	a[0] = '1';
	FOR(i, 1, n) {
		int last = (a[i - 1] - '0') + (b[i - 1] - '0');
		for (int j = 1; j >= 0; --j) {
			int cur = j + (b[i] - '0');
			if (cur == last) continue;
			a[i] = '0' + j;
			break;
		}
	}
	a[n] = '\0';
}

void run() {
	scanf("%d", &n);
	scanf("%s", b); assert(strlen(b) == n);
	solve();
	printf("%s\n", a);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}