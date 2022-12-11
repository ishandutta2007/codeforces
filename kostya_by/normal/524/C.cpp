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

const int MAXN = 5555;
const int LIM = 200000000 + 5;

int n, k, q;
int a[MAXN];
char value[ LIM ];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j <= k; j++) {
			if (value[a[i] * j] == 0) {
				value[a[i] * j] = (char)(j + 1);
			}
			value[a[i] * j] = min(value[a[i] * j], (char)(j + 1));
		}
	}
	cin >> q;
	for (int it = 0; it < q; it++) {
		int x; cin >> x;
		int answer = k + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				int new_x = x - a[i] * j;
				if (new_x < 0 || new_x >= LIM) {
					continue;
				}
				int z = (int)value[new_x] - 1;
				if (z == -1) {
					continue;
				}
				answer = min(answer, j + z);
			}
		}
		if (answer > k) {
			answer = -1;
		}
		cout << answer << "\n";
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}