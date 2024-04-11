#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200200;

int n;
int w[MAXN];
int h[MAXN];
int prefix_max_h[MAXN];
int suffix_max_h[MAXN];

void solve() {
	scanf("%d", &n);
	int sum_w = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &w[i], &h[i]);
		sum_w += w[i];
	}
	prefix_max_h[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefix_max_h[i] = max(prefix_max_h[i - 1], h[i]);
	}
	suffix_max_h[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		suffix_max_h[i] = max(suffix_max_h[i + 1], h[i]);
	}
	for (int i = 1; i <= n; i++) {
		int ws = sum_w - w[i];
		int hs = max(prefix_max_h[i - 1], suffix_max_h[i + 1]);
		printf("%d ", ws * hs);
	}
	printf("\n");
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}