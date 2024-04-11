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

int n, m, k;
int p[120];

int get(int x) {
	for (int i = 0; i < k; ++i)
		if (p[i] == x) {
			rotate(p, p + i, p + i + 1);
			return i;
		}
	assert(false);
	return 0;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
		cin >> p[i];
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += m;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			sum += get(x);
		}
	}
	cout << sum << "\n";
	return 0;
}