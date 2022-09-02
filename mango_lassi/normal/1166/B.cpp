#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	bool fail = true;

	vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
	for (int d = ch.size(); d*d <= k; ++d) {
		if (k % d == 0) {
			fail = false;
			for (int j = 0; j < k/d; ++j) {
				for (int i = 0; i < d; ++i) {
					cout << ch[(i + j) % ch.size()]; 
				}
				// cerr << '\n';
			}
			cout << '\n';
			break;
		}
	}
	if (fail) {
		cout << "-1\n";
	}
}