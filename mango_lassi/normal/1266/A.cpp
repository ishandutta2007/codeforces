#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		// Divisible by 60 if
		// 1. divisible by 20, that is, has at least one zero and one other even number
		// 2. divisible by 3, that is, sum of digits is zero mod 3

		int sum = 0;
		int ec = 0;
		int zc = 0;
		for (auto c : str) {
			int v = (c - '0');
			sum = (sum + v) % 3;
			if (v == 0) ++zc;
			if (v % 2 == 0) ++ec;
		}
		if (sum == 0 && ec >= 2 && zc >= 1) cout << "red\n";
		else cout << "cyan\n";
	}
}