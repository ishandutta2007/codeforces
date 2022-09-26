#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, k;
int a[N], b[N];
int cnt;

long long solve(int mid) {
	priority_queue<int, vector<int>, greater<int>> pqA;
	priority_queue<int> pqB;
	cnt = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		pqA.push(a[i] - mid);
		long long add1 = pqA.top() + b[i] - mid;
		long long add2 = 0;
		if (pqB.size()) add2 = b[i] - mid - pqB.top();
		if (add1 <= add2 && add1 < 0) {
			ans += add1;
			cnt++;
			pqA.pop();
			pqB.push(b[i] - mid);
		}
		else if (add2 <= add1 && add2 < 0) {
			ans += add2;
			pqB.pop();
			pqB.push(b[i] - mid);
		}
	} 
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	int low = (int)-1e9, high = (int)1e9;
	while (low < high) {
		int mid = (low + high) >> 1;
		solve(mid);
		if (cnt >= k) high = mid;
		else low = mid + 1;
	}
	cout << solve(low) + 2LL * k * low << '\n';
}