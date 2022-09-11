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

const int MAXN = 1000;
const int MAXVAL = 1000000;

int n;
int a[2 * MAXN];
int ansstart;
vector<pair<int, int>> ansmoves;

int pos[MAXVAL + 1];
bool used[2 * MAXN];

bool test(int fst) {
	REP(i, 2 * n) if (pos[a[i]] = i);
	REP(i, 2 * n) used[i] = false;
	used[2 * n - 1] = used[fst] = true;
	vector<pair<int, int>> curmoves;
	curmoves.PB(MP(a[fst], a[2 * n - 1]));
	int have = a[2 * n - 1];
	int at = 2 * n - 1;
	while (at>=0) {
		if (used[at]) { --at; continue; }
		used[at] = true;
		int big = a[at], small = have - big;
		if (small<0 || small>MAXVAL || pos[small] == -1) return false;
		while (true) {
			if (pos[small] < 0) return false;
			if (a[pos[small]] != small) return false;
			if (!used[pos[small]]) break;
			--pos[small];
		}
		int to = pos[small];
		used[to] = true;
		curmoves.PB(MP(a[to], a[at]));
		have = a[at];
	}
	ansstart = a[fst] + a[2 * n - 1];
	ansmoves = curmoves;
	return true;
}

bool solve() {
	sort(a, a + 2 * n);
	REPE(i, MAXVAL) pos[i] = -1;
	REP(fst, 2 * n - 1) if (test(fst)) return true;
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", ansstart);
	REPSZ(i, ansmoves) printf("%d %d\n", ansmoves[i].first, ansmoves[i].second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}