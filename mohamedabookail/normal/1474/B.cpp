/**
*    author:  Mohamed AboOkail
*    created: 11/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
bool is_prime(long long n) {
	for (int i = 2; i * i <= n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		long long n;
		cin >> n;
		long long a = 0, b = 0;
		for (int i = n + 1; ; i++) {
			if(is_prime(i)) {
				a = i;
				break;
			}
		}
		for (int i = a + n; ; i++) {
			if(is_prime(i)) {
				b = i;
				break;
			}
		}
		cout << a * b << "\n";
	}
}