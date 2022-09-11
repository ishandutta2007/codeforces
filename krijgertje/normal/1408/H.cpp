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

const int MAXN = 500000;

int n;
int a[MAXN];

int zbefore[MAXN + 1];
int ztot;

int mxl[MAXN + 1];
int mxr[MAXN + 1];

int solve() {
	zbefore[0] = 0; REP(i, n) zbefore[i + 1] = zbefore[i] + (a[i] == 0 ? 1 : 0);
	ztot = zbefore[n];
	int lim = ztot / 2;
	FORE(i, 1, n) mxl[i] = 0, mxr[i] = 0;
	REP(i, n) if (a[i] != 0) {
		int v = a[i], l = zbefore[i], r = ztot - zbefore[i + 1];
		if (l >= lim) mxr[v] = max(mxr[v], r);
		if (r >= lim) mxl[v] = max(mxl[v], l);
	}

	set<int> avail; FORE(i, 1, lim) avail.insert(i);
	priority_queue<int> pq;
	int ret = 0;
	vector<pair<int, int>> opt;
	FORE(v, 1, n) opt.PB(MP(mxl[v], mxr[v]));
	sort(opt.begin(), opt.end());
	REPSZ(i, opt) {
		int l = opt[i].first, r = opt[i].second;
		++ret;
		pq.push(r);
		while (SZ(pq) > l) {
			int at = pq.top(); pq.pop();
			auto it = avail.upper_bound(at);
			if (it == avail.begin()) { --ret; continue; }
			it = prev(it);
			avail.erase(it);
		}
	}
	return min(ret,lim);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}