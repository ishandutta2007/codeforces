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

bool is_prime(int x) {
	for (int d = 2; d * d <= x; d++) {
		if (x % d == 0) {
			return false;
		}
	}

	return true;
}

void solve() {
	int n; cin >> n;
	set<int> answer;
	for (int d = 2; d <= n; d++) {
		if (!is_prime(d)) {
			continue;
		}

		int carry = d;
		while (carry <= n) {
			answer.insert(carry);
			carry *= d;
		}
	}

	cout << answer.size() << "\n";
	for (int x : answer) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}