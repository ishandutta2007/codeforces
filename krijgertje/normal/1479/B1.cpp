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
int a[MAXN];

pair<int, int> b[MAXN];
int nb;

int solve() {
	nb = 0;
	REP(i, n) if (nb == 0 || a[i] != b[nb - 1].first) b[nb++] = MP(a[i], 1); else ++b[nb - 1].second;
	REP(i, nb) b[i].second = min(b[i].second, 2);
	int ret = 0;
	REP(i, nb) ret += b[i].second;
	FOR(i, 1, nb) if (b[i].second == 2 && b[i - 1].second == 1) {
		int j = i - 2;
		while (j >= 1 && b[j] == MP(b[i].first, 1) && b[j - 1].second == 1) j -= 2;
		if (j >= 0 && b[j] == b[i]) --ret;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}