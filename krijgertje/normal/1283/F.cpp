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

const int MAXN = 200000;

int n;
int a[MAXN - 1];
int ansroot;
pair<int, int> ansedge[MAXN - 1];

bool intree[MAXN];

bool solve() {
	REP(i, n) intree[i] = false;
	int at = n - 1;
	int pending = -1;
	int nansedge = 0;
	ansroot = -1;
	REP(i, n - 1) {
		int x = a[i];
		//printf("x=%d at=%d pending=%d\n", x + 1, at + 1, pending + 1);
		if (intree[x]) {
			if (pending != -1) {
				ansedge[nansedge++] = MP(pending, at);
				intree[at] = true;
			}
		} else {
			if (pending == -1) {
				ansroot = x;
			} else {
				ansedge[nansedge++] = MP(pending, x);
			}
			intree[x] = true;
		}
		pending = x;
		while (at >= 0 && intree[at]) --at;
		assert(at >= 0);
	}
	if (pending != -1) {
		ansedge[nansedge++] = MP(pending, at);
		intree[at] = true;
	}
	REP(i, n) assert(intree[i]);
	assert(nansedge == n - 1);
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) scanf("%d", &a[i]), --a[i];
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", ansroot + 1);
	REP(i, n - 1) printf("%d %d\n", ansedge[i].first + 1, ansedge[i].second + 1);
}

int main() {
	run();
	return 0;
}