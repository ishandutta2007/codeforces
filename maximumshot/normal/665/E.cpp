#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int NMAX = 32 * 1000100;
const int st = 30;

int sz, n, k, bor[NMAX][2], cnt[NMAX];

void add(int xr) {
	int v = 0;
	for(int nx, bit = st;bit >= 0;bit--) {
		nx = ((1 << bit) & xr?1 : 0);
		if(bor[v][nx] == -1) {
			cnt[sz] = 0;
			bor[sz][0] = bor[sz][1] = -1;
			bor[v][nx] = sz++;
		}
		v = bor[v][nx];
		cnt[v]++;
	}
}

ll res = 0;

void upd(int xr) {
	int v = 0;
	for(int now, bit = st;bit >= 0;bit--) {
		now = ((1 << bit) & xr?1 : 0);
		if((1 << bit) & k) {
			if(bor[v][now ^ 1] != -1) v = bor[v][now ^ 1];
			else return;
		}else {
			if(bor[v][now ^ 1] != -1) res += cnt[bor[v][now ^ 1]];
			if(bor[v][now] != -1) v = bor[v][now];
			else return;
		}
	}
	res += cnt[v];
}

bool solve() {
	
	scanf("%d %d", &n, &k);
	
	sz = 1;
	bor[0][0] = bor[0][1] = -1;
	cnt[0] = 0;

	add(0);

	for(int x, xr = 0, i = 1;i <= n;i++) {
		scanf("%d", &x);
		xr ^= x;
		upd(xr);
		add(xr);
	}

	printf("%I64d\n", res);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}