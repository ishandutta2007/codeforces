#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
#define A 1
#define B 2
#define C 3
int main() {
	ll state = A;
	bool bad = false;
	string s;
	cin >> s;
	for (ll i = 0; i < s.length(); i++) {
		char d = s[i];
		if (state == A) {
			if (d == '1') {
				state = B;
			}
			else {
				bad = true;
			}
		}
		else if (state == B) {
			if (d == '1') {
				state = B;
			}
			else if (d == '4') {
				state = C;
			}
			else {
				bad = true;
			}
		}
		else if (state==C) {
			if (d == '1') {
				state = B;
			}
			else if (d == '4') {
				state = A;
			}
			else {
				bad = true;
			}
		}
	}
	if (bad) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}