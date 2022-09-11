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

const int MAXVERT = 200000;
const int MAXHOR = 200000;
const int MAXP = 300000;

int nvert, nhor, np;

int xvert[MAXVERT];
int yhor[MAXHOR];
int px[MAXP], py[MAXP];

vector<int> cntvert[MAXVERT - 1];
vector<int> cnthor[MAXHOR - 1];

ll solve() {
	REP(i, nvert - 1) cntvert[i].clear();
	REP(i, nhor - 1) cnthor[i].clear();
	REP(i, np) {
		int x = lower_bound(xvert, xvert + nvert, px[i]) - xvert;
		int y = lower_bound(yhor, yhor + nhor, py[i]) - yhor;
		//printf("%d vs %d and %d vs %d\n", xvert[x], px[i], yhor[y], py[i]);
		if (px[i] != xvert[x]) cntvert[x - 1].PB(y);
		if (py[i] != yhor[y]) cnthor[y - 1].PB(x);
	}
	ll ret = 0;
	auto calc = [&](int x) { return (ll)x * (x - 1) / 2; };
	auto calcv = [&](vector<int>& v) { sort(v.begin(), v.end()); ll ret = calc(SZ(v)); for (int l = 0, r = l; l < SZ(v); l = r) { while (r < SZ(v) && v[r] == v[l]) ++r; ret -= calc(r - l); } return ret; };
	REP(i, nvert - 1) ret += calcv(cntvert[i]);
	REP(i, nhor - 1) ret += calcv(cnthor[i]);
	return ret;
}

void run() {
	scanf("%d%d%d", &nvert, &nhor, &np);
	REP(i, nvert) scanf("%d", &xvert[i]);
	REP(i, nhor) scanf("%d", &yhor[i]);
	REP(i, np) scanf("%d%d", &px[i], &py[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}