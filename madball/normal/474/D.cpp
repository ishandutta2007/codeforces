#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long lint;
const int size = 100001;
const lint limit = 1000000007;

int main() {
	vector<lint> ways(size);
	vector<lint> sums(size);
	int t, k;
	cin >> t >> k;
	ways[0] = 1;
	sums[0] = 1;

	for (int i = 1; i < ways.size(); i++)
		ways[i] = (ways[i - 1] + (i >= k ? ways[i - k] : 0)) % limit;
	
	for (int i = 1; i < sums.size(); i++)
		sums[i] = (sums[i - 1] + ways[i]) % limit;

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << ((sums[b] - sums[a - 1] % limit) + limit) % limit << '\n';
	}

	return 0;
}