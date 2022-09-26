#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, k;
double f[N];

int main() {
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(9);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
		f[i] += f[i - 1];
	}
	double mx = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1;j <= i - k + 1; ++j) {
			mx = max(mx, (f[i] - f[j - 1]) / (i - j + 1));
		}
	}
	cout << mx;
}