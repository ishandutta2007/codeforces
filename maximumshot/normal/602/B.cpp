#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

const int LOG = 21;

vec< int > lg, mn[LOG], mx[LOG];

void build(int n, vec< int > a) {
	lg.resize(n + 1);
	int q = 0;
	while((1 << q) <= n) q++; 
	for(int i = n;i >= 1;i--) {
		if((1 << q) > i) q--;
		lg[i] = q;
	}
	for(int i = 0;i < LOG;i++) {
		mn[i].resize(n + 1, inf);
		mx[i].resize(n + 1, -inf);
	}
	
	mn[0] = mx[0] = a;

	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j + (1 << (i - 1)) <= n;j++) {
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int get_diff(int l, int r) {
	return max(mx[lg[r - l + 1]][l], mx[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]) - 
		   min(mn[lg[r - l + 1]][l], mn[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
}

bool solve()
{
	int n;
	cin >> n;
	vec< int > a(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}

	build(n, a);

	int ans = 0;

	for(int i = 1;i <= n;i++) {
		int bl, br, bm, bp;
		bl = 1, br = i;
		while(br - bl > 1) {
			bm = (bl + br) >> 1;
			if(get_diff(bm, i) <= 1) br = bm;
			else bl = bm + 1;
		}
		bp = (get_diff(bl, i) <= 1?bl : br);
		ans = max(ans, i - bp + 1);
	}

	cout << ans << '\n';

	return true;
} 

int main() {

	//while(solve());
	solve();	

	return 0;
}