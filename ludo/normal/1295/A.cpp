#include<bits/stdc++.h>
using namespace std;

string calc(int n) {
	string s;
	while (n >= 4) {
		s += '1';
		n -= 2;
	}
	if (n == 3) s += '7';
	else s += '1';

	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int ntc;
	cin >> ntc;
	while (ntc--) {
		int n;
		cin >> n;
		cout << calc(n) << endl;
	}
	return 0;
}