#include <bits/stdc++.h>

using namespace std;

int main() {
	int dif;
	cin >> dif;
	dif += 2000;
	cout << 2000 << '\n' << -1 << ' ';
	for (int i = 0; i < 1999; ++i) {
		cout << (dif / 1999) + (i < (dif % 1999)) << ' ';
	}
}