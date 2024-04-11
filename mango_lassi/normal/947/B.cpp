#include <iostream>
using namespace std;

typedef long long ll;
const int N = 10 + (1e5);
ll sum[N+1];
ll ini[N];
ll res[N];
ll ful[N+1];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> ini[i];
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> sum[i+1];
		sum[i+1] += sum[i];
	}
	for (int i = 0; i < n; ++i) {
		int low = i;
		int high = n;
		while(low != high) {
			int mid = (low + high) >> 1;
			if (sum[mid+1] - sum[i] > ini[i]) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		ful[i] += 1;
		if (high < n) {
			ful[high] -= 1;
			res[high] += ini[i] - (sum[high]-sum[i]);
		}
	}
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += ful[i];
		res[i] += cur * (sum[i+1] - sum[i]);
		cout << res[i] << ' ';
	}
	cout << '\n';
}