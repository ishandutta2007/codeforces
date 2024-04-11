#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

const int N = 500;

int a[N];

signed main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, d;
		cin >> n >> d;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int sum = 0;
		for (int i = 1; i < n; i++) {
			int need = i;
			if (need * a[i] <= d) {
				d -= need * a[i];
				sum += a[i];
			} else {
				sum += d / need;
				d = 0;
			}
		}
		cout << a[0] + sum << '\n';
	}
}