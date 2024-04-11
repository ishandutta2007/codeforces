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

const int MAXN = 1010;
const int INF = 2000000000;

int n;
int w[MAXN];
int h[MAXN];

int process_h(int H) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int current = INF;
		if (w[i] <= H) {
			current = min(current, h[i]);
		}
		if (h[i] <= H) {
			current = min(current, w[i]);
		}
		if (current == INF) {
			return INF;
		}
		sum += current;
	}
	return sum * H;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
	}
	int answer = INF;
	for (int H = 1; H <= 1000; H++) {
		answer = min(answer, process_h(H));
	}
	cout << answer << "\n";
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}