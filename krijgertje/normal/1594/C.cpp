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

const int MAXN = 300000;

int n; char want;
char s[MAXN + 1];
vector<int> ans;

void solve() {
	ans.clear();
	{
		bool allsame = true;
		REP(i, n) if (s[i] != want) allsame = false;
		if (allsame) return;
	}

	FORE(x, 1, n) {
		bool allsame = true;
		for (int i = x - 1; i < n; i += x) if (s[i] != want) allsame = false;
		if (allsame) { ans.PB(x); return; }
	}

	ans.PB(n - 1), ans.PB(n);
}

void run() {
	scanf("%d %c", &n, &want);
	scanf("%s", s);
	solve();
	printf("%d\n", SZ(ans));
	if (SZ(ans) != 0) { REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}