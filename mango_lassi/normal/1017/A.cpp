#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < 4; ++i) {
		ll v;
		cin >> v;
		sum += v;
	}
	int rank = 1;
	for (int j = 1; j < n; ++j) {
		ll val = 0;
		for (int i = 0; i < 4; ++i) {
			ll v;
			cin >> v;
			val += v;
		}
		if (val > sum) ++rank;
	}
	cout << rank << '\n';
}