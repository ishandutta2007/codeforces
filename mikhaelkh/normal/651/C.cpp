#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 200010;

int x[N], y[N], f[N];

bool lessx(int i, int j) {
	if (x[i] != x[j])
		return x[i] < x[j];
	return y[i] < y[j];
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);

	int n;
	ll res = 0;
	cin >> n;
	for (int i = 0; i<n; ++i)
		cin >> x[i] >> y[i];
	for (int i = 0; i<n; ++i)
		f[i] = i;
	sort(f, f+n, lessx);
	for (int j, i=0; i<n;) {
		for (j=i+1; j<n && x[f[i]] == x[f[j]]; ++j);
		res += ll(j-i)*(j-i-1);
		i = j;
	}
	for (int i = 0; i<n; ++i)
		swap(x[i], y[i]);
	sort(f, f+n, lessx);
	for (int j, i=0; i<n;) {
		for (j=i+1; j<n && x[f[i]] == x[f[j]]; ++j);
		res += ll(j-i)*(j-i-1);
		i = j;
	}
	for (int j, i=0; i<n;) {
		for (j=i+1; j<n && x[f[i]] == x[f[j]] && y[f[i]] == y[f[j]]; ++j);
		res -= ll(j-i)*(j-i-1);
		i = j;
	}
	cout << res/2 << endl;

	return 0;
}