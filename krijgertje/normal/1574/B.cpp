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

int a, b, c, neq;

bool solve() {
	vector<int> have = { a,b,c };
	sort(have.begin(), have.end());
	int rem = neq;
	int cur = min(rem, have[2] - have[1]);
	rem -= cur; have[2] -= cur;
	cur = min(rem / 2, have[1] - have[0]);
	rem -= 2 * cur; have[1] -= cur, have[2] -= cur;
	cur = min(rem / 3, have[0] - 1);
	rem -= 3 * cur; have[0] -= cur, have[1] -= cur, have[2] -= cur;
	for (int i = 2; i >= 0; --i) if (rem > 0 && have[i] >= 2) --rem, --have[i];
	if (rem != 0) return false;
	if (have[2] > have[0] + have[1] + 1) return false;
	return true;
}

void run() {
	scanf("%d%d%d%d", &a, &b, &c, &neq);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}