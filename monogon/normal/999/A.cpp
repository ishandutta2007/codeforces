#include <iostream>

using namespace std;

int n, k;
int a[100];
int l, r;

int main() {
	cin >> n >> k;
	l = 0;
	r = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] <= k && l == i) {
			l++;
		}
		if(a[i] > k) {
			r = i + 1;
		}
	}
	cout << (n - max(l, r)) + (l) << endl;
}