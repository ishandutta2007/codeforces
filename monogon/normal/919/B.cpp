#include <iostream>

using namespace std;

int k;

bool perfect(long long n) {
	int sum = 0;
	while(n > 0 && sum <= 10) {
		sum += n % 10;
		n /= 10;
	}
	return sum == 10;
}

int main() {
	cin >> k;
	int count = 0;
	long long i = 0;
	for(i = 0; count < k; i++) {
		count += perfect(i);
	}
	cout << (i - 1) << endl;
}