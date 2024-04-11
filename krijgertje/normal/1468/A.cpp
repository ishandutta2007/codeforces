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

int x[MAXN], nx; // x[i] = minimum value of last element of a LaIS of length i+1
int y[MAXN], ny; // y[i] = minimum value of second last element of a LaIS of length i+1, where value of last element is no smaller than value of second last element (y[0]=0)

int solve() {
	//printf("solving\n");
	nx = 0;
	ny = 0;
	set<int> xchange;
	xchange.insert(-1);
	REP(i, n) {
		int xpos = -1;
		{
			int lo = -1, hi = nx;
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (a[i] < x[mi]) hi = mi; else lo = mi;
			}
			xpos = hi;
		}
		int ypos = -1;
		{
			int lo = -1, hi = ny;
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (a[i] < y[mi]) hi = mi; else lo = mi;
			}
			ypos = hi;
		}
		if (xpos != -1 && xpos >= nx || a[i] < x[xpos]) { xchange.insert(xpos); x[xpos] = a[i]; while (xpos >= nx) ++nx; }
		if (ypos >= 1 && ypos >= nx || a[i] < x[ypos]) { xchange.insert(ypos); x[ypos] = a[i]; while (ypos >= nx) ++nx; }
		while (SZ(xchange) != 0 && *xchange.begin() + 1 <= xpos) { int idx = *xchange.begin(); xchange.erase(xchange.begin()); y[idx + 1] = idx == -1 ? 0 : x[idx]; while (idx + 1 >= ny) ++ny; }
		//printf("after %d (xpos=%d ypos=%d)\n", a[i], xpos, ypos);
		//printf("x:"); REP(j, nx) printf(" %d", x[j]); puts("");
		//printf("y:"); REP(j, ny) printf(" %d", y[j]); puts("");
	}
	return max(nx, ny);
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