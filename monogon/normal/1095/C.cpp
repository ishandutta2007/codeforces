#include <iostream>

using namespace std;

long long n, k;
long long a[32];

int main() {
	cin >> n >> k;
	long long min1 = 0;
	for(int i = 0; i < 32; i++) {
		a[i] = (n >> i) & 1;
		min1 += a[i];
	}
	if(k < min1 || k > n) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;

	for(int i = 31; i > 0; i--) {
		long long num = min(k - min1, a[i]);
		a[i] -= num;
		a[i - 1] += 2 * num;
		min1 += num;
	}
	for(int i = 0; i < 31; i++) {
		long long m = (1 << i);
		for(int j = 0; j < a[i]; j++) {
			cout << m << " ";
		}
	}
}