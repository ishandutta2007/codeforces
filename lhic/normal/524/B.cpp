#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

int n;

int h[2000];
int w[2000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> h[i];
		if (h[i] < w[i])
			swap(h[i], w[i]);
	}
	int ans = 2000 * 1000 * 1000;

	for (int k = 1; k <= 1000; ++k) {
		int sum = 0;
		int fl = 0;
		for (int i = 0; i < n; ++i) {
			if (h[i] <= k)
				sum += w[i];
			else if (w[i] <= k)
				sum += h[i];
			else
				fl = 1;
		}
		if (!fl)
			ans = min(ans, k * sum);
	}

	cout << ans;
	return 0;
}