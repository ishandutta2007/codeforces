#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXM = 100100;
const int MAXK = 100100;
const int INF  = 1000000000;

int m, k;
int dish_cnt[MAXK];
int dish_max_pos[MAXK];
int a[MAXM], b[MAXM];
int prefix_zeroes[MAXM]; 

void solve() {
	scanf("%d%d", &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &dish_cnt[i]);
		dish_max_pos[i] = 0;
	}
	int first_one = m;
	for (int i = 1; i < m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		prefix_zeroes[i] = prefix_zeroes[i - 1];
		dish_max_pos[a[i]] = i; 
		if (a[i]) {
			--dish_cnt[a[i]];
		} else {
			++prefix_zeroes[i];
		}
		if (b[i] == 1) {
			first_one = min(first_one, i);
		}
	}
	int mn_cnt = INF;
	for (int i = 1; i <= k; i++) {
		if ( dish_max_pos[i] < first_one ) {
			mn_cnt = min(mn_cnt, dish_cnt[i]);
		}
	}
	assert(mn_cnt != INF);
	for (int i = 1; i <= k; i++) {
		char result = 'N';
		if (prefix_zeroes[first_one - 1] >= dish_cnt[i] && dish_max_pos[i] < first_one) {
			result = 'Y';
		}
		if (prefix_zeroes[m - 1] - mn_cnt >= dish_cnt[i]) {
			result = 'Y';
		}
		printf("%c", result);
	}
	printf("\n");
}

int main() {
	time_t start = clock();
	int t; scanf("%d", &t);
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}