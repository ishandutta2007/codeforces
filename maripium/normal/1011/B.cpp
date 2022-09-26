#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt[105];

bool ok(int mid) {
	if (mid == 0) return 1;
	int sum = 0;
	for (int i = 1; i <= 100; ++i) sum += (cnt[i] / mid);
	return sum >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	while (m--) {
		int x; cin >> x;
		cnt[x]++;
	}
	
	int l = 0, r = 100;
	for (int i = 100; i >= 0; --i) if (ok(i)) {
		cout << i << '\n';
		return 0;
	}
}