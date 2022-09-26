#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	int f0 = 0, f1 = 0, cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '0') {
			cnt0++;
			if (b[i] == '0') f0++;
		}
		else {
			cnt1++;
			if (b[i] == '0') f1++;
		}
	}
	long long res = 1ll * cnt1 * f0 + 1ll * cnt0 * f1 - 1ll * f0 * f1;
	cout << res << '\n';
}