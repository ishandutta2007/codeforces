#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
long long a[(int) 2e5];

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if(k == 0) {
		cout << (a[0] == 1 ? -1 : 1) << endl;
	}else if(k == n || a[k - 1] != a[k]) {
		cout << a[k - 1] << endl;
	}else {
		cout << -1 << endl;
	}
}