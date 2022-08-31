#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 5010;

int a[N], ta[N], b[N], tb[N];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		int t, x, c;
		cin >> t >> x >> c;
		if (t == 1)
			a[x] = c, ta[x] = i+1;
		else
			b[x] = c, tb[x] = i+1;
	}
	for (int i=1; i<=n; ++i, cout << endl)
		for (int j=1; j<=m; ++j)
			if (ta[i] > tb[j])
				cout << a[i] << ' ';
			else
				cout << b[j] << ' ';

	return 0;
}