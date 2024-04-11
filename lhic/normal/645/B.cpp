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

int n, k;

int main() {
	cin >> n >> k;
	k = min(k, n / 2);
	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		int j = n - 1 - i;
		ans += 1;
		ans += j - i - 1;
		ans += j - i - 1;
	}
	cout << ans << "\n";
	return 0;
}