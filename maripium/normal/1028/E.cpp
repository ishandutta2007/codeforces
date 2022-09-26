#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
long long b[N], a[N], f[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	bool allZero = 1;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		a[i] = b[i];
		allZero &= (b[i] == 0);
	}
	if (allZero) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << 123 << ' ';
		return 0;
	}
	
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] > a[(i + n - 1) % n]) {
			pos = i;
			break;
		}
	}
	
	if (pos == -1) return cout << "NO\n",0;
	
	for (int i = 0; i < n; ++i) {
		a[i] = b[(i + pos + 1) % n];
	}
	
	f[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		f[i] = (max(0ll, (a[(i + n - 1) % n] - a[i]) / f[i + 1]) + 1) * f[i + 1] + a[i];
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) cout << f[(i + n - pos - 1) % n] << ' ';
}