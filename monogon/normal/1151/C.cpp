
#define P 1000000007

#include <iostream>

using namespace std;

long long l, r;

long long sumA(long long l, long long n) {
	return (((l + n - 1) * (l + n - 1) - (l - 1) * (l - 1)) % P + P) % P;
}
long long sumB(long long l, long long n) {
	return (((l + n - 1) * (l + n) - (l - 1) * l) % P + P) % P;
}

long long sumTo(long long n) {
	if(n == 0) {
		return 0;
	}
	long long p = 1;
	long long a = 1;
	long long b = 1;
	long long idx = 0;
	long long sum = 0;
	while(true) {
		if(idx + p >= n) {
			sum = (sum + sumA(a % P, (n - idx) % P)) % P;
			break;
		}else {
			sum = (sum + sumA(a % P, p % P)) % P;
		}
		idx += p;
		a += p;
		p *= 2;

		if(idx + p >= n) {
			sum = (sum + sumB(b % P, (n - idx) % P)) % P;
			break;
		}else {
			sum = (sum + sumB(b % P, p % P)) % P;
		}
		idx += p;
		b += p;
		p *= 2;
	}
	return sum;
}

int main() {
	cin >> l >> r;
	cout << ((((sumTo(r) - sumTo(l - 1)) % P) + P) % P) << endl;
}