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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH = 300000;
const int MAXW = 8;

int h, w;
int a[MAXH][MAXW];

int how[1 << MAXW];


bool can(int want,pair<int,int> &res) {
	REP(mask, 1 << w) how[mask] = -1;
	REP(x, h) {
		int mask = 0;
		REP(y, w) if (a[x][y] >= want) mask |= 1 << y;
		if (how[mask] == -1) how[mask] = x;
	}
	REP(bit, w) {
		REP(mask, 1 << w) {
			if ((mask & (1 << bit)) == 0) continue;
			if (how[mask] == -1) continue;
			if (how[mask ^ (1 << bit)] != -1) continue;
			how[mask ^ (1 << bit)] = how[mask];
		}
	}
	REP(mask, 1 << w) {
		if (how[mask] == -1) continue;
		int rem = (1 << w) - mask - 1;
		if (how[rem] == -1) continue;
		res = MP(how[mask], how[rem]);
		return true;
	}
	return false;
}

int v[MAXH * MAXW], nv;

pair<int, int> solve() {
	nv = 0; REP(x, h) REP(y, w) v[nv++] = a[x][y];
	sort(v, v + nv);
	nv = unique(v, v + nv) - v;
	int lo = 0, hi = nv;
	pair<int, int> res;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(v[mi], res)) lo = mi; else hi = mi;
	}
	assert(can(v[lo], res));
	return res;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first + 1, ans.second + 1);
}

int main() {
	run();
	return 0;
}