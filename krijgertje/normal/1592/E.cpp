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
const int NBIT = 20;

int n;
int a[MAXN];

int first[1 << NBIT];
int sum[MAXN + 1];

int solve() {
	memset(first, -1, sizeof(first));
	int ret = 0;
	REP(bit, NBIT) {
		sum[0] = 0;
		REP(i, n) sum[i + 1] = sum[i] ^ (a[i] >> bit);
		for (int l = 0, r = l; l < n; l = r) {
			while (r < n && ((a[r] >> bit) & 1) == ((a[l] >> bit) & 1)) ++r;
			if (((a[l] >> bit) & 1) == 0) continue;
			//printf("bit=%d l=%d r=%d\n", bit, l, r);
			REP(par, 2) {
				for (int j = l + par; j <= r; j += 2) if (first[sum[j]] == -1) first[sum[j]] = j; else ret = max(ret, j - first[sum[j]]);
				for (int j = l + par; j <= r; j += 2) first[sum[j]] = -1;
			}
		}
		
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