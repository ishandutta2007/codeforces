#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

ld dp[200000];
ld dp2[200000];
int x[2000];
int n, m;

ld solve(int k) {
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		ld sum = 0;
		for (int j = 0; j < k; ++j) {
			sum += dp[j];
			if (j >= m)
				sum -= dp[j - m];
			dp2[j] = (sum - dp[j - x[i]]) / (m - 1);
		}
		for (int j = 0; j < k; ++j)
			dp[j] = dp2[j];
	}
	ld sum = 0;
	for (int i = 0; i < k; ++i)
		sum += dp[i];
	return sum;
}

int main() {
	int s = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i]), --x[i], s += x[i];


	cout.setf(ios::fixed);
	cout.precision(100);
	if (m == 1) {
		cout << 1.0 << "\n";
		return 0;
	}
	cout << (m - 1) * solve(s) + 1 << "\n";
	return 0;
}