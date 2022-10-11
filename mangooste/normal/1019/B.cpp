#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

int ask(int i) {
	cout << "? " << i + 1 << endl;
	int a;
	cin >> a;
	cout << "? " << (i + n / 2) % n + 1 << endl;
	int b;
	cin >> b;
	if (a == b) {
		cout << "! " << i + 1 << endl;
		exit(0);
	}
	return b - a;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int left_val = ask(0), right_val = -left_val;
	int L = 0, R = n / 2 + 1;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		((right_val < left_val) ^ (ask(mid) < 0) ? L : R) = mid;
	}
	ask(L);
	cout << "! -1\n";
}