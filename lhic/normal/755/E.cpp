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


int main() {
	int n, k;
	cin >> n >> k;
	if (n <= 3 || k > 3 || k == 1) {
		cout << -1 << "\n";
		return 0;
	}
	if (k == 2) {
		if (n == 4) {
			cout << -1 << "\n";
			return 0;
		}
		cout << n - 1 << "\n";
		for (int i = 0; i < n - 1; ++i)
			cout << i + 1 << " " << i + 2 << "\n";
	}
	else {
		cout << 3 + (n - 4) * 2 << "\n";
		for (int i = 0; i < 3; ++i)
			cout << i + 1 << " " << i + 2 << "\n";
		for (int i = 4; i < n; ++i) {
			cout << i + 1 << " " << 2 << "\n";
			cout << i + 1 << " " << 3 << "\n";
		}
	}
	return 0;
}