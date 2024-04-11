#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long a[(int) 1e5];

int main() {
	cin >> n >> a[0] >> a[1];
	long long min1 = min(a[0], a[1]), min2 = max(a[0], a[1]);
	long long max1 = min2, max2 = min1;
	for(int i = 2; i < n; i++) {
		cin >> a[i];
		if(a[i] <= min1) {
			min2 = min1;
			min1 = a[i];
		}else if(a[i] < min2) {
			min2 = a[i];
		}

		if(a[i] >= max1) {
			max2 = max1;
			max1 = a[i];
		}else if(a[i] > max2) {
			max2 = a[i];
		}
	}
	cout << min(max2 - min1, max1 - min2) << endl;
}