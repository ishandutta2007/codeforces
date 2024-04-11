
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, k;
long long a[100000];

long long mypow(int x) {
	long long m = 1;
	for(int i = 0; i < x; i++) {
		m *= 2;
	}
	return m;
}

int main() {
	cin >> n >> k;
	long long m = 0;
	long long N = n;
	for(int i = 0; i < k; i++) {
		long long l = (N + pow(2, k - i) - 2) / (pow(2, k - i) - 1);
		long long r = 1 + (N - ((k - i)*(k - i + 1)) / 2) / (k - i);
		if(l < m + 1) l = m + 1;
		if(i > 0 && r > 2 * m) r = 2 * m;
//		cout << N << " " << l << " " << r << endl;
		if(l <= r) {
			a[i] = l;
			N -= a[i];
			m = l;
		}else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
}