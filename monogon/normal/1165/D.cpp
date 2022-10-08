
#include <iostream>
#include <algorithm>

using namespace std;

int n, T;
long long b[300];

int div(long long x) {
	int count = 0;
	for(int i = 1; i * i <= x; i++) {
		if(x % i == 0) {
			if(i * i == x) count++;
			else count += 2;
		}
	}
	return count;
}

int main() {
	cin >> T;
	for(int t = 0; t < T; t++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(b, b + n);
		long long x = b[n - 1];
		int num = 2;
		while(x % b[0] == 0) {
			x /= b[0];
			num++;
		}
		if(div(b[0]) == 2 && div(x) * num == n + 2) {
			x = b[0] * b[n - 1];
			int i = 0;
			for(i = 0; i < n; i++) {
				if(x % b[i] != 0) {
					cout << -1 << endl;
					break;
				}
			}
			if(i == n) {
				cout << x << endl;
			}
		}else {
			cout << -1 << endl;
		}
	}
}