#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (x > a) {
		return false;
	}
	a -= x;
	if (y > a + b) {
		return false;
	}
	if (y + z > a + b + c) {
		return false;
	}
	return true;
}

int main() {
	if (solve()) {
		puts("Yes");
	} else {
		puts("No");
	}
}