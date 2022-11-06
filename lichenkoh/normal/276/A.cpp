#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long n;
	long k;
	long maxj = 0;
	bool first = true;
	cin >> n;
	cin >> k;
	for (long i = 0; i < n; i++) {
		long f,t;
		cin >> f;
		cin >> t;
		long joy;
		if (t > k) {
			joy = f-(t-k);
		}
		else {
			joy = f;
		}
		if (first) {
			maxj = joy;
			first = false;
		}
		else {
			maxj = max(maxj,joy);
		}
	}
	cout << maxj << endl;
}