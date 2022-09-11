#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 1000000;

int n;
char s[MAXN + 1];

int pac[MAXN], npac;
int ast[MAXN],  nast;
int prvpac[MAXN], prvast[MAXN];

int mxpos[MAXN]; // maximum position when i moves left (only considering characters up to i). only defined when s[i]=='P'
bool canrgt[MAXN]; // whether the positions can be covered by pacmans going right (only considering characters up to i). only defined when s[i]=='*'

int calcmxpos(int i, int t) {
	int x = i - t >= 0 ? prvast[i - t] : -1;
	if (x == -1) return prvpac[i] == -1 ? i : max(i, prvpac[i] + t);
	if (prvpac[i] == -1 || prvpac[i] <= x) return canrgt[x] ? i : -1;
	if (prvpac[prvpac[i]] != -1 && prvpac[prvpac[i]] > x) return mxpos[prvpac[prvpac[i]]] != -1 ? max(i, prvpac[i] + t) : -1;
	return canrgt[x] ? max(i, prvpac[i] + t) : mxpos[prvpac[i]] != -1 ? i : -1;
}
bool calccanrgt(int x, int t) {
	int i = prvpac[x];
	if (i == -1 || x - i > t) return false;
	int y = prvast[i];
	return mxpos[i] != -1 && mxpos[i] >= x || y == -1 || (prvpac[i] != -1 && prvpac[i] > y && mxpos[prvpac[i]] != -1) || canrgt[y];
}

bool canall(int t) {
	//printf("t=%d\n", t);
	REP(i, n) {
		if (s[i] == 'P') {
			mxpos[i] = calcmxpos(i, t);
			//printf("mxpos[%d]=%d\n", i, mxpos[i]);
		}
		if (s[i] == '*') {
			canrgt[i] = calccanrgt(i, t);
			//printf("canrgt[%d]=%s\n", i, canrgt[i] ? "yes" : "no");
		}
	}
	int idx = max(pac[npac - 1], ast[nast - 1]);
	if (s[idx] == 'P') return mxpos[idx] != -1; else if (s[idx] == '*') return canrgt[idx]; else { assert(false); return false; }
}

pair<int, int> solve() {
	npac = nast = 0;
	REP(i, n) {
		prvast[i] = nast == 0 ? -1 : ast[nast - 1];
		prvpac[i] = npac == 0 ? -1 : pac[npac - 1];
		if (s[i] == 'P') pac[npac++] = i; else if (s[i] == '*') ast[nast++] = i;
	}
	assert(npac > 0 && nast > 0);
	if (npac == 1) {
		int nleft = 0, tleft = 0, nright = 0, tright = 0;
		REP(i, nast) if (ast[i] < pac[0]) { ++nleft; tleft = max(tleft, pac[0] - ast[i]); } else { ++nright; tright = max(tright, ast[i] - pac[0]); }
		if (nleft > nright || nleft == nright&&tleft <= tright) return MP(nleft, tleft); else return MP(nright, tright);
	}
	int l = 0, r = n - 1;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (canall(m)) r = m; else l = m;
	}
	return MP(nast, r);
}

void run() {
	scanf("%d", &n); scanf("%s", s);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}


int main() {
	run();
	return 0;
}