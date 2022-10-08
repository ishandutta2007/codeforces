
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long z;
long long x[200000];

bool checkK(int k) {
	for(int i = 0; i < k; i++) {
		if(x[n + i - k] - x[i] < z) {
			return false;
		}
	}
	return true;
}

int getK(int l, int r) {
	if(l >= r) return l;
	if(r - l == 1) {
		return checkK(r) ? r : l;
	}
	int m = (l + r) / 2;
	if(checkK(m)) {
		return getK(m, r);
	}
	return getK(l, m - 1);
}

int main() {
	cin >> n >> z;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);
	cout << getK(0, n / 2) << endl;
}