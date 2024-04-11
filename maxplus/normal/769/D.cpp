#include <iostream>
using namespace std;
constexpr int N = 1 << 14, M = 10001;
int pc[N], a[M], n = 100000, k = 7;
int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	int64_t ans;
	cin >> n >> k;
	for (int i = 0; i < N; ++i)
		pc[i] = __builtin_popcount(i) == k;
	for (int i = 0; i < n; ++i)
		cin >> ans, ++a[ans];
	for (int i = ans = 0; i < M; ans += pc[0] * a[i] * int64_t(a[i] - 1) / 2, ++i)
		for (int j = 0; j < i; ++j)
			ans += pc[i ^ j] * a[i] * int64_t(a[j]);
	cout << ans;
	return 0;
}