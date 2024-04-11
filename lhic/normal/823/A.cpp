#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;

const int MAXN = 300001;
int a[MAXN];

int main() {
	cout.setf(ios::fixed); cout.precision(15);
#ifdef LOCAL
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	int d = (n - 1 - k);
	for (int i = 0; i < k; i++) {
		a[i] = (d + i) / k + 1;
	}

	cout << a[k - 2] + a[k - 1] << "\n";
	int c = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j + 1 < a[i]; j++) {
			cout << c << " " << c + 1 << "\n";
			c++;
		}
		cout << c++ << " " << n << "\n";
	}
	return 0;
}