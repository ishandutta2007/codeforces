#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Pick most frequent value and make all other positions have that value
	map<int, int> cou;
	vector<int> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		++cou[vals[i]];
	}

	int bc = 0;
	int bv = 0;
	for (auto pr : cou) {
		if (pr.second > bc) {
			bc = pr.second;
			bv = pr.first;
		}
	}

	cout << n - bc << '\n';
	for (int i = 0; i < n; ++i) {
		if (vals[i] == bv) continue;
		if (i > 0 && vals[i-1] == bv) {
			if (vals[i] > bv) {
				cout << 2 << ' ' << i+1 << ' ' << i << '\n';
			} else {
				cout << 1 << ' ' << i+1 << ' ' << i << '\n';
			}
			vals[i] = bv;
		} else {
			int j = i;
			while(vals[j] != bv) ++j;
			while(j > i) {
				if (vals[j-1] > bv) {
					cout << 2 << ' ' << j << ' ' << j+1 << '\n';
				} else {
					cout << 1 << ' ' << j << ' ' << j+1 << '\n';
				}
				vals[j-1] = bv;
				--j;
			}
		}
	}
}