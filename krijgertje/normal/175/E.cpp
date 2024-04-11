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

int nf, ne, ns;
int rf, re, rs;
int df, de;

int ncalc;

double calc(const vector<string> &g) {
	//printf("[%s,%s]\n", g[0].c_str(), g[1].c_str());
	++ncalc;
	int len = SZ(g[0]);
	vector<pair<double, double>> val;
	double slen = sqrt(1.0*rs*rs - 1);
	double flen = sqrt(1.0*rf*rf - 1);
	double elen = sqrt(1.0*re*re - 1);
	REP(x, 2) REP(y, len) if (g[x][y] == 'D') {
		double fmlt = 2 * flen, emlt = 2 * elen;
		REP(xx, 2) REP(yy, len) if (g[xx][yy] == 'S') {
			int dy = abs(y - yy);
			if (slen + flen >= dy) fmlt += min(min(2 * flen, 2 * slen), slen + flen - dy);
			if (slen + elen >= dy) emlt += min(min(2 * elen, 2 * slen), slen + elen - dy);
		}
		val.PB(MP(fmlt*df, emlt*de));
	}
	assert(SZ(val) == nf + ne);
	sort(val.begin(), val.end(), [](const pair<double, double> &a, const pair<double, double> &b) { return a.first - a.second > b.first - b.second; });
	double ret = 0; REPSZ(i, val) ret += i < nf ? val[i].first : val[i].second;
	//printf("=%lf\n", ret);
	return ret;
}

double rec(vector<string> &g, int at, int remfreeze, int remdamage) {
	//printf("%d: %d,%d (%s,%s)\n", at, remfreeze, remdamage,g[0].c_str(),g[1].c_str());
	if (at >= SZ(g[0])) {
		assert(remfreeze == 0 && remdamage == 0);
		return calc(g);
	} else {
		if (g[0][at] != '?' || g[1][at] != '?') return rec(g, at + 1, remfreeze, remdamage);
		double ret = 0;
		REPE(cfreeze, 2) {
			int cdamage = 2 - cfreeze;
			if (cfreeze > remfreeze || cdamage > remdamage) continue;
			REP(i, cfreeze) g[i][at] = 'S';
			REP(i, cdamage) g[cfreeze + i][at] = 'D';
			double cur = rec(g, at + 1, remfreeze - cfreeze, remdamage - cdamage);
			ret = max(ret, cur);
			REP(i, 2) g[i][at] = '?';
		}
		return ret;
	}
}

double solve() {
	double ret = 0;
	REP(havesinglefreeze, 2) if (havesinglefreeze <= ns) REP(havesingledamage, 2) if (havesingledamage <= nf + ne) {
		int rem = nf + ne + ns - havesinglefreeze - havesingledamage;
		if (rem % 2 != 0) continue;
		int len = rem / 2 + havesinglefreeze + havesingledamage;
		REP(singlefreezeidx, havesinglefreeze ? len : 1) REP(singledamageidx, havesingledamage ? len : 1) {
			if (havesinglefreeze && havesingledamage && singlefreezeidx == singledamageidx) continue;
			vector<string> g(2, string(len, '?'));
			if (havesinglefreeze) g[0][singlefreezeidx] = '-', g[1][singlefreezeidx] = 'S';
			if (havesingledamage) g[0][singledamageidx] = '-', g[1][singledamageidx] = 'D';
			double cur = rec(g, 0, ns - havesinglefreeze, nf + ne - havesingledamage);
			ret = max(ret, cur);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &nf, &ne, &ns);
	scanf("%d%d%d", &rf, &re, &rs);
	scanf("%d%d", &df, &de);
	printf("%.15lf\n", solve());
}

void stress() {
	int mxtower = 20;
	FORE(ntower, 1, mxtower) {
		for (ns = 0; ns <= ntower; ++ns) {
			ne = ntower - ns, nf = 0;
			ncalc = 0;
			double have = solve();
			printf("(%d,%d): %d\n", ntower, ns, ncalc);
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}