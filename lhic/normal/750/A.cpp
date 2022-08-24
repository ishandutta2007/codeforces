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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;


int n, k;
int main() {
	cin >> n >> k;
	int x = 240 - k;
	x /= 5;
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int sum = 0;
		int cur = 0;
		for (int j = 0; j < n; ++j)
			if ((i >> j) & 1)
				++cur, sum += (j + 1);
		if (sum <= x && cur > ans)
			ans = cur;
	}
	cout << ans << "\n";
	return 0;
}