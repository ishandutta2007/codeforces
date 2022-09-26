#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, k;
	cin >> b >> k; b %= 2;
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		a[i] &= 1;
	}
	// reverse(a.begin(), a.end());
	int n = 0;
	for (int v : a) {
		n = n * b + v;
		n %= 2;
	}
	if (n) {
		puts("odd");
	} else {
		puts("even");
	}
}