
#include <iostream>
#include <set>

using namespace std;

long long a, b;

set<long long> divs;

long long gcd(long long a, long long b) {
	long long r;
	do {
		r = a % b;
		a = b;
		b = r;
	}while(r != 0);
	return a;
}
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	cin >> a >> b;
	if(a > b) {
		swap(a, b);
	}else if(a == b) {
		cout << 0 << endl;
		return 0;
	}
	// now a < b
	long long A = b - a;
	for(int i = 1; i * i <= A; i++) {
		if(A % i == 0) {
			divs.insert(i);
			divs.insert(A / i);
		}
	}
	long long mink = 0;
	long long M = a * b;
	for(long long n : divs) {
		long long k = (n - (b % n)) % n;
		long long m = lcm(a + k, b + k);
		if(m < M) {
			M = m;
			mink = k;
		}
	}
	cout << mink << endl;
}