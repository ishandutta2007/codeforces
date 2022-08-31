#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 1010;

int a[N];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);

	int n, res = 0;
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for (;n;) {
		int m = 0;
		for (int i=1; i<n; ++i)
			if (a[i-1] == a[i])
				a[m++] = a[i];
		res += n-m-1;
		n = m;
	}
	cout << res << endl;

	return 0;
}