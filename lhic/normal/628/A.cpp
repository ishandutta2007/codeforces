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


int main() {
	int n, b, p;
	cin >> n >> b >> p;
	int n2 = n;
	int ans = 0;
	while (n > 1) {
		int k = 1;
		while (k * 2 <= n)
			k *= 2;
		ans += b * k + (k / 2);
		n -= k / 2;
	}
	cout << ans << " " << n2 * p << "\n";
	return 0;
}