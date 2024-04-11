#include <iostream>
#include <map>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// b[0] ^ b[1] = x[0]
	// b[1] ^ b[2] = x[1]
	// ..
	// b[n-1] ^ b[0] = x[n-1]

	// b[1] = x[0]
	// b[2] = b[1] ^ x[1] = x[0] ^ x[1]
	// ...
	// 0 = b[n-1] ^ x[n-1] = ^x[i]
	// -> cycles of length k must have an even amount of ones

	int n;
	cin >> n;
	string str;
	cin >> str;

	map<int, int> counts;
	for (int i = 0; i < n; ++i) {
		++counts[gcd(i, n)];
	}
	int res = 0;
	for (auto pr : counts) {
		bool works = true;
		for (int i = 0; works && i < pr.first; ++i) {
			int j = i;
			do {
				works ^= (str[j] == '1');
				j = (j + pr.first) % n;
			} while (j != i);
		}
		if (works) res += pr.second;
	}
	cout << res << '\n';
}