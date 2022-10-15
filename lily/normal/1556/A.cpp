#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int c, d;
		cin >> c >> d;
		if (c == 0 && d == 0) puts("0");
		else if (abs(d - c) % 2) puts("-1");
		else puts( c == d ? "1" : "2");
	}
}