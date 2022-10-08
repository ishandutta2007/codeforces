
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a, b;
vector<int> v[100000];

bool checkK(int k) {
	if(k == n) return false;
	for(int i = 0; i < n; i++) {
		if(v[i] != v[(i + k) % n]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a - 1].push_back((b - a + n) % n);
		v[b - 1].push_back((a - b + n) % n);
	}
	for(int i = 0; i < n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	for(int k = 1; k * k <= n; k++) {
		if(n % k == 0) {
			if(checkK(k) || checkK(n / k)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}