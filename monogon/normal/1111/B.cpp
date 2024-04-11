
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>

using namespace std;

long long n, k, m;
long long a[100000];

int main() {
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long sum = 0;
	double max = 0;
	for(int i = n - 1; i >= 0; i--) {
		sum += a[i];
		double x = 1.0 * (sum + min(m - i, (n - i) * k)) / (n - i);
		if(m >= i && x > max) {
			max = x;
		}
	}
	cout << fixed << setprecision(8) << max << endl;
}