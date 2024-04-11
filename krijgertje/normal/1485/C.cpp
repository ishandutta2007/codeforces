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

int x, y;

ll solve() {
	ll ret = 0;
	//FORE(b, 1, y) ret += min(x / (b + 1), b - 1);
	int res = x;
	while (res != 0) {
		// floor(x/(b+1))=res -> x>=res*(b+1) && x<(res+1)*(b+1) -> x/(res+1)-1<b && b<=x/res-1
		int blo = x / (res + 1), bhi = x / res - 1;
		//printf("res=%d: blo=%d bhi=%d\n", res, blo, bhi);
		int nres = x / (bhi + 2);
		blo = max(blo, 1);
		bhi = min(bhi, y);
		if (blo <= bhi) {
			int bmi = min(bhi, max(blo - 1, res + 1));
			if (blo <= bmi) {
				ret += (ll)(blo - 1 + bmi - 1) * (bmi - blo + 1) / 2;
			}
			if (bmi < bhi) {
				ret += (ll)(bhi - bmi) * res;
			}
		}
		res = nres;
	}
	return ret;
}

void run() {
	scanf("%d%d", &x, &y);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}