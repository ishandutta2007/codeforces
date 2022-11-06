#include <iostream>
#include <assert.h>
using namespace std;
long long count47(long long x) {
	long long ans = 0;
	while (x > 0) {
		if (x % 10 == 4 || x % 10 == 7) {
			ans++;
		}
		x /= 10;
	}
	return ans;
}

int main()
{
	long long n;
	long long k;
	long long ans = 0;
	cin >> n;
	cin >> k;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (count47(x) <= k) {
			ans++;
		}
	}
	cout << ans << endl;
}