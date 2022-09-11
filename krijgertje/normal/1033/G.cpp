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

const int MAXN = 100;

int n, mxtake;
ll have[MAXN];

ll winalice, winbob, winfirst, winsecond;

int one[MAXN], none; // piles in which only A player can move when a<=one[i]
int two[MAXN], ntwo; // piles in which either (only A player can move) or (both players can move, but A player may move twice) when a<=two[i]
int both[MAXN], nboth; // piles in which either of the players can move exactly once when a>=both[i]

void solve() {
	winalice = winbob = winfirst = winsecond = 0;
	FORE(sametake, 1, mxtake) {
		ll moves = 0; REP(i, n) moves += have[i] / sametake;
		if (moves % 2 == 0) ++winsecond; else ++winfirst;
	}
	FORE(sumtake, 3, 2 * mxtake) { // suppose a<b
		none = ntwo = nboth = 0;
		REP(i, n) {
			int rem = have[i] % sumtake;
			if (2 * rem < sumtake) { one[none++] = rem; continue; }
			one[none++] = sumtake - rem - 1; // rem < b = sumtake-a  ->  a < sumtake-rem
			if (sumtake - rem <= rem / 2) two[ntwo++] = rem / 2;
			both[nboth++] = max(sumtake - rem, rem / 2 + 1);
		}
		int l = max(1, sumtake - mxtake), h = (sumtake - 1) / 2;
		int mxone = l - 1; REP(i, none) mxone = max(mxone, one[i]);
		int mxtwo1 = mxone, mxtwo2 = mxone; REP(i, ntwo) if (two[i] > mxtwo1) mxtwo2 = mxtwo1, mxtwo1 = two[i]; else if (two[i] > mxtwo2) mxtwo2 = two[i];
		int par = nboth % 2;
		// l..mxone -> win, mxone+1..mxtwo2 -> win, mxtwo2+1..mxtwo1 -> par==0?win:fst, mxtwo1+1..ways -> par==0?snd:fst
		int cwin = max(0, (par == 0 ? mxtwo1 : mxtwo2) - l + 1), cfst = par == 0 ? 0 : h - mxtwo2, csnd = par == 0 ? h - mxtwo1 : 0;
		//printf("sumtake=%d -> mxone=%d mxtwo=%d/%d, range=%d..%d par=%d -> cwin=%d cfst=%d csnd=%d\n", sumtake, mxone, mxtwo1, mxtwo2, l, h, par, cwin, cfst, csnd);
		winalice += cwin, winbob += cwin, winfirst += 2 * cfst, winsecond += 2 * csnd;
	}
}

void run() {
	scanf("%d%d", &n, &mxtake);
	REP(i, n) scanf("%lld", &have[i]);
	solve();
	printf("%lld %lld %lld %lld\n", winalice, winbob, winfirst, winsecond);
}

int main() {
	run();
	return 0;
}