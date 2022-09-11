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

const int MAXN = 400000;

int n;
int a[MAXN];
int b[MAXN];

int solve() {
	sort(a, a + n);
	int mxsum = a[n - 2] + a[n - 1];
	int mxbit = 0; while ((2 << mxbit) <= mxsum) ++mxbit;

	int ret = 0;
	REPE(bit, mxbit) {
		REP(i, n) b[i] = a[i] & ((2 << bit) - 1);
		sort(b, b + n);
		// b[i]+b[j] in [1<<bit..2<<bit) or in [3<<bit..)
		int x = n, y = n, z = n;
		ll cnt = 0;
		REP(i, n) {
			while (x - 1 >= 0 && b[i] + b[x - 1] >= (1 << bit)) --x;
			while (y - 1 >= 0 && b[i] + b[y - 1] >= (2 << bit)) --y;
			while (z - 1 >= 0 && b[i] + b[z - 1] >= (3 << bit)) --z;
			if (y >= i + 1) cnt += y - max(x, i + 1);
			cnt += n - max(z, i + 1);
		}
		if (cnt & 1) ret += 1 << bit;
	}
	//int chk = 0; REP(i, n) FOR(j, i + 1, n) chk ^= (a[i] + a[j]); printf("chk=%d\n", chk);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}