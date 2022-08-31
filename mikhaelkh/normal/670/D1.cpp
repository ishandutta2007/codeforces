#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int const N = 1010;

int n;
ll k, a[N], b[N];

ll calc(ll x) {
	ll res = 0;
	for (int i=0; i<n && res <= k; ++i)
		res += max(0LL, a[i]*x - b[i]);
	return res <= k;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	int L = 0, R = 1e9;
	while (L < R) {
//		cerr << L << ' ' << R << endl;
		int M = L + (R-L+1)/2;
		if (calc(M)) L = M;
		else R = M-1;
	}
	cout << L << endl;
	return 0;
}