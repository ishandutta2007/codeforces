#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 1010;

int a[N], b[N];

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	int res = 0;
	for (int i=0; i<n; ++i) {
		int ax = 0, bx = 0;
		for (int j=0; j<n; ++j) {
			ax |= a[j];
			bx |= b[j];
			res = max(res, ax+bx);
		}
	}
	cout << res << endl;

	return 0;
}