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

const int MAXN = 200000;
const int MAXTYPE = 200000;

int n;
int type[MAXN], lim[MAXN];
vector<int> ans;

int val[MAXTYPE];
int ord[MAXTYPE];

void solve() {
	ans.clear();
	int bestnum = 0, bestden = 1;
	FOR(t, 1, 20) {
		REP(i, MAXTYPE) val[i] = 0;
		REP(i, n) val[type[i]] += min(t, lim[i]);
		REP(i, MAXTYPE) ord[i] = i;
		sort(ord, ord + MAXTYPE, [&](int i, int j) { return val[i] > val[j]; });
		int curnum = 0, curden = t;
		REP(i, t) curnum += val[ord[i]];
		//printf("t=%d: %d/%d\n", t, curnum, curden);
		if ((ll)curnum * bestden > (ll)bestnum * curden) {
			bestnum = curnum, bestden = curden;
			ans.clear();
			REP(i, t) ans.PB(ord[i]);
		}
	}
	{
		REP(i, MAXTYPE) val[i] = 0;
		REP(i, n) val[type[i]] += lim[i];
		REP(i, MAXTYPE) ord[i] = i;
		sort(ord, ord + MAXTYPE, [&](int i, int j) { return val[i] > val[j]; });
		int curnum = 0;
		int locnum = 0, locden = 1;
		FORE(curden, 20, MAXTYPE) {
			if (curden == 20) REP(i, curden) curnum += val[ord[i]];
			else curnum += val[ord[curden - 1]];
			if ((ll)curnum * locden > (ll)locnum * curden) {
				locnum = curnum, locden = curden;
			}
		}
		if ((ll)locnum * bestden > (ll)bestnum * locden) {
			bestnum = locnum, bestden = locden;
			ans.clear();
			REP(i, locden) ans.PB(ord[i]);
		}
	}
	//printf("%d/%d\n", bestnum, bestden);
	sort(ans.begin(), ans.end());
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &type[i], &lim[i]), --type[i];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}