#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> people (n + (k - n % k) % k, 0);
	for (int i = 0; i < n; i++)
		cin >> people[i];

	sort(people.begin(), people.end());
	long long sum = 0;
	for (int i = 0; i < people.size() / k; i++) {
		int maxim = people[k * i];
		for (int j = 1; j < k; j++)
			maxim = max(maxim, people[k * i + j]);
		sum += maxim - 1;
	}

	cout << sum * 2;
	return 0;
}