#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int binSearch(vector<int>& vec, int val) {
	int low = 0;
	int high = vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		// cout << low << ' ' << high << ' ' << vec[mid] << ' ' << val << '\n';
		if (val < vec[mid]) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}
	return low;
}

int main() {
	int n, u;
	cin >> n >> u;
	vector<int> states (n);
	for (int i = 0; i < n; ++i) cin >> states[i];

	long long a = 0;	// current answer is a/b
	long long b = 1;
	for (int i = 0; i < n; ++i) {
		int k = binSearch(states, states[i] + u);
		int j = i+1;
		// cout << i << ' ' << j << ' ' << k << '\n';
		if (k > j) {
			long long ofa = states[k] - states[j];
			long long ofb = states[k] - states[i];
			if (a*ofb < ofa*b) {
				a = ofa;
				b = ofb;
			}
		}
	}
	if (a == 0) {
		cout << "-1\n";
	} else {
		cout << std::setprecision(20) << std::fixed << (long double)a / b << '\n';
	}
}