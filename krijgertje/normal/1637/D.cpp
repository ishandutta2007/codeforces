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
#include <functional>
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

const int MAXN = 100;

int n;
int a[MAXN];
int b[MAXN];

int solve() {
	if (n == 1) return 0;
	// sum(i<j: (ai+aj)^2) = 1/2*sum(i!=j: (ai+aj)^2) = 1/2*(sum(i,j: ai^2+aj^2+2ai*aj)-4*sum(ai^2)) = 1/2*(2*n*sum(ai^2)+2*sum(ai)^2-sum(ai^2))= (n-2)*sum(ai^2)+sum(ai)^2
	int sum = 0;
	REP(i, n) sum += a[i] + b[i];
	vector<bool> can(sum + 1, false);
	can[0] = true;
	REP(i, n) {
		for (int j = sum; j >= 0; --j) if(can[j]) {
			assert(j + a[i] <= sum && j + b[i] <= sum);
			can[j + a[i]] = can[j + b[i]] = true;
			can[j] = false;
		}
	}
	int ret = INT_MAX;
	REPE(j, sum) if (can[j]) {
		int x = j, y = sum - j, cur = x * x + y * y;
		//printf("%d -> %d\n", j, cur);
		ret = min(ret, cur);
	}
	REP(i, n) ret += (n - 2) * (a[i] * a[i] + b[i] * b[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}