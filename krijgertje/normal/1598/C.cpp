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

const int MAXN = 200000;

int n;
int a[MAXN];

pair<int, int> b[MAXN]; int nb;

ll solve() {
	ll sum = 0;
	REP(i, n) sum += a[i];
	sum *= 2;
	if (sum % n != 0) return 0;
	sum /= n;
	sort(a, a + n);
	nb = 0;
	REP(i, n) if (nb == 0 || a[i] != b[nb - 1].first) b[nb++] = MP(a[i], 1); else ++b[nb - 1].second;
	int r = nb - 1;
	ll ret = 0;
	REP(l, n) {
		while (r >= 0 && b[l].first + b[r].first > sum) --r;
		if (r < l || b[l].first + b[r].first != sum) continue;
		if (r == l) {
			int cnt = b[l].second;
			ret += (ll)cnt * (cnt - 1) / 2;
		} else {
			ret += (ll)b[l].second * b[r].second;
		}
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