#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10, M = 500, K = N * M, B = 450;
int n, a[N];
int cnt[K * 2];
int arr[N * 2];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int d = -B; d <= B; d++) {
		for(int i = 1; i <= n; i++) {
			int v = K + a[i] - d * (i - 1);
			cnt[v]++;
			ans = max(ans, cnt[v]);
		}
		for(int i = 1; i <= n; i++) cnt[K + a[i] - d * (i - 1)]--;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= i + B && j <= n; j++) {
			if((a[j] - a[i]) % (j - i) == 0) {
				int v = (a[j] - a[i]) / (j - i) + N;
				arr[v]++;
				ans = max(ans, arr[v] + 1);
			}
		}
		for(int j = i + 1; j <= i + B && j <= n; j++) {
			if((a[j] - a[i]) % (j - i) == 0) {
				int v = (a[j] - a[i]) / (j - i) + N;
				arr[v]--;
			}
		}
	}
	cout << n - ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(t = 1; t--; ) {
		solve();
	}
    return 0;
}