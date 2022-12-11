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

int a[6];

void solve() {
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}

	long long answer = 0;
	while (true) {
		int ii = -1;
		int jj = -1;
		int kk = -1;
		int value = 0;

		for (int i = 0; i < 6; i++) {
			int j = (i + 1) % 6;
			int k = (j + 1) % 6;
			
			int cur = min(a[i], a[k] );
			if (cur > value) {
				ii = i;
				jj = j;
				kk = k;
				value = cur;
			}
		}

		if (value == 0) {
			break;
		}
		answer += 2 * a[jj] + 1;
		a[ii] -= 1;
		a[jj] += 1;
		a[kk] -= 1;
	}

	cout << answer << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}