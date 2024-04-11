#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
i64 n;
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n;
	i64 l = 0, r = 1e12, ans = -1;
	auto chk = [&] (i64 x) {
		i64 cnt = x - 1 - (x + 2 >> 2) - (x >= 4);
		return cnt;
	};
	while(l <= r) {
		i64 mid = l + r >> 1;
		if(chk(mid) >= n) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
	return 0;
}