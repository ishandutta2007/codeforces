#include <iostream>
#include <set>

const int N = 1e5;
long long num [N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	long long sum = 0;
	std::multiset<long long> diffs;
	for (int i = 0; i < n; ++i) {
		std::cin >> num[i];
		sum += num[i];
		diffs.insert(2 * num[i]);
	}
	bool can = false;
	long long curr = 0;
	for (int i = 0; i < n; ++i) {
		diffs.erase(diffs.find(2 * num[i]));
		diffs.insert(-2 * num[i]);
		curr += num[i];
		sum -= num[i];
		if (diffs.find(sum - curr) != diffs.end()) {
			can = true;
		}
	}
	if (can) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}