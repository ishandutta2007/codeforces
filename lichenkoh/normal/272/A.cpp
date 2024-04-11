#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int f;
		cin >> f;
		sum += f;
	}
	int ways = 0;
	for (int ans = 1; ans <= 5; ans++) {
		int mod = (ans + sum) % (n+1);
		if (mod < 0) {
			mod += (n+1);
		}
		if (mod != 1) {
			ways ++;
		}
	}
	cout << ways << endl;
}