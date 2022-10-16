#include <bits/stdc++.h>
using namespace std;

int b, k;

int main() {
	cin >>b >> k;
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		ans *= b;
		ans ^= x;
		ans &= 1;
	}
	cout << (ans ? "odd" : "even") << endl;


}