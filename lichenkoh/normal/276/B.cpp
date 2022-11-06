#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a[26];
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		int ind = s[i] - 'a';
		a[ind]++;
	}
	int odds = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i]%2 != 0) {
			odds++;
		}
	}
	if (odds == 0 || odds == 1) {
		cout << "First" << endl;
		return 0;
	}
	else if (odds%2 == 0) {
		cout << "Second" << endl;
		return 0;
	}
	else {
		cout << "First" << endl;
		return 0;
	}
	return 0;
}