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

const int MAXN = 500;

int n;
int a[MAXN];

vector<pair<int,int>> anschanges;
vector<int> ansparts;

bool solve() {
	anschanges.clear();
	ansparts.clear();
	vector<int> cur(a, a + n);
	int before = 0;
	while (SZ(cur) >= 1) {
		int idx = -1;
		FORSZ(i, 1, cur) if (cur[i] == cur[0]) { idx = i; break; }
		if (idx == -1) return false;
		FOR(i, 1, idx) anschanges.PB(MP(cur[i], before + idx + i));
		ansparts.PB(2 * idx);
		before += 2 * idx;
		reverse(cur.begin() + 1, cur.begin() + idx);
		cur.erase(cur.begin() + idx);
		cur.erase(cur.begin() + 0);
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(anschanges));
	REPSZ(i, anschanges) printf("%d %d\n", anschanges[i].second, anschanges[i].first);
	printf("%d\n", SZ(ansparts));
	REPSZ(i, ansparts) { if (i != 0) printf(" "); printf("%d", ansparts[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}