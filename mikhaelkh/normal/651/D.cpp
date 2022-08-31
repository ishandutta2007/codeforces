#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 500010;

int n;
string s;
ll t, a, b, x[N], y[N];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> t >> s;
	x[0] = (s[0] == 'w') * b;
	for (int i=1; i<n; ++i)
		x[i] = x[i-1] + (s[i] == 'w') * b;
	for (int i=n-1; i>=0; --i)
		y[i] = y[i+1] + (s[i] == 'w') * b;

	int res = 0;
	for (int i=0; i<n; ++i) {
		ll cur = a * i + x[i] + i + 1;
		if (cur <= t && res < i+1)
			res = i+1;
		int L = n, R = i;
		while(L - R > 1) {
			int M = (L+R) / 2;
			if (cur + y[M] + a * (i+n-M) + n-M <= t) L = M;
			else R = M;
		}
		if (cur <= t && res < i+1+n-L)
			res = i+1+n-L;
	}
	for (int i=1; i<n-i; ++i)
		swap(s[i], s[n-i]);
	x[0] = (s[0] == 'w') * b;
	for (int i=1; i<n; ++i)
		x[i] = x[i-1] + (s[i] == 'w') * b;
	for (int i=n-1; i>=0; --i)
		y[i] = y[i+1] + (s[i] == 'w') * b;

	for (int i=0; i<n; ++i) {
		ll cur = a * i + x[i] + i + 1;
		if (cur <= t && res < i+1)
			res = i+1;
		int L = n, R = i;
		while(L - R > 1) {
			int M = (L+R) / 2;
			if (cur + y[M] + a * (i+n-M) + n-M <= t) L = M;
			else R = M;
		}
		if (cur <= t && res < i+1+n-L)
			res = i+1+n-L;
	}

	cout << res << endl;
	return 0;
}