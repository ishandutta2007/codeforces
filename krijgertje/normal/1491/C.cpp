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

const int MAXN = 5000;

int n;
int a[MAXN];

int b[MAXN];
int visits[MAXN];

ll solve() {
	REP(i, n) b[i] = a[i];
	REP(i, n) visits[i] = 0;
	ll ret = 0;
	REP(i, n - 1) {
		if (i + b[i] >= n) {
			int cur = i + b[i] - n + 1;
			int use = min(cur, visits[i]);
			cur -= use;
			b[i] -= use;
			visits[i] -= use;
			ret += cur;
			b[i] -= cur;
		}
		while (b[i] > 1) {
			if (visits[i] > 0) --visits[i]; else ++ret;
			if (i + b[i] < n) ++visits[i + b[i]];
			--b[i];
		}
		visits[i + 1] += visits[i];
	}
	{
		int cur = b[n - 1] - 1;
		int use = min(cur, visits[n - 1]);
		cur -= use;
		b[n-1] -= use;
		visits[n - 1] -= use;
		ret += cur;
		b[n - 1] -= cur;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}