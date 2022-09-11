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

const int MAXN = 1000000;

int n;
char s[MAXN + 1];

vector<int> a;
int bsum[MAXN + 1];
int csum[MAXN + 1];

int solve() {
	a.clear(); REP(i, n) if (s[i] == 'a') a.PB(i);
	bsum[0] = 0; REP(i, n) bsum[i + 1] = bsum[i] + (s[i] == 'b' ? 1 : 0);
	csum[0] = 0; REP(i, n) csum[i + 1] = csum[i] + (s[i] == 'c' ? 1 : 0);
	int ret = INT_MAX;
	REPSZ(ii, a) {
		int upto = min(SZ(a) - 1, ii + 2);
		FORE(jj, ii + 1, upto) {
			int na = jj - ii + 1;
			int nb = bsum[a[jj]] - bsum[a[ii]];
			int nc = csum[a[jj]] - csum[a[ii]];
			//printf("%d..%d: %d/%d/%d\n", a[ii], a[jj], na, nb, nc);
			if (na > nb && na > nc) ret = min(ret, a[jj] - a[ii] + 1);
		}
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}