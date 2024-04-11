#include <iostream>

using namespace std;

int n;
int a[15];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = (1 << n);
	for(int i = 0; i < max; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) {
			if((i >> j) & 1) {
				sum += a[j];
			}else {
				sum += 360 - a[j];
			}
			sum %= 360;
		}
		if(sum == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}