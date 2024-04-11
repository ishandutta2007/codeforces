#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, x;
int a[N];
bool have[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (have[a[i]]) return cout << 0 << '\n',0;
		have[a[i]] = 1;
	} 
	for (int i = 1; i <= n; ++i) {
	 	if ((a[i] & x) == a[i]) continue;
	 	if (have[a[i] & x]) return cout << 1 << '\n',0;
	 	a[i] &= x;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; ++i) {
		if (a[i] == a[i - 1]) return cout << 2 << '\n',0;
	}
	cout << -1 << '\n';
}