#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	int a[15], b[15];
	for (int i = 0;i < 14;++i) cin >> a[i];
	int res = 0;
	for (int i = 0;i < 14;++i) {
		for (int j = 0;j < 14;++j) b[j] = a[j];
		if (a[i] == 0) continue;
		b[i] = 0;
		for (int j = 0;j < 14;++j) b[j] += (a[i] / 14);
		int rem = a[i] % 14;
		for (int j = 1;j <= rem;++j) b[(i + j) % 14]++;
		int cnt = 0;
		for (int j = 0;j < 14;++j) if (b[j] % 2 == 0) cnt += b[j];
		res = max(res, cnt); 
	}
	cout << res;
}