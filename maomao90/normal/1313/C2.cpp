#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n;
int m[500005];
long long lsum[500005], rsum[500005];
stack<ii> lstack, rstack;
int arr[500005];
int ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &m[i]);
	for (int i = 0; i < n; i++) {
		while (!lstack.empty() && lstack.top().first >= m[i]) lstack.pop();
		if (lstack.empty()) {
			lsum[i] = (long long) m[i] * (i + 1);
		} else {
			int left = lstack.top().second;
			lsum[i] = (long long) m[i] * (i - left) + lsum[left];
		}
		lstack.emplace(m[i], i);
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!rstack.empty() && rstack.top().first >= m[i]) rstack.pop();
		if (rstack.empty()) {
			rsum[i] = (long long) m[i] * (n - i);
		} else {
			int right = rstack.top().second;
			rsum[i] = (long long) m[i] * (right - i) + rsum[right];
		}
		rstack.emplace(m[i], i);
	}
	long long cursum = 0;
	for (int i = 0; i < n; i++) {
		if (lsum[i] + rsum[i] - m[i] > cursum) {
			cursum = lsum[i] + rsum[i] - m[i];
			ans = i;
		}
	}
	int temp = m[ans];
	for (int j = ans; j >= 0; j--) {
		temp = min(m[j], temp);
		arr[j] = temp;
	}
	temp = m[ans];
	for (int j = ans + 1; j < n; j++) {
		temp = min(m[j], temp);
		arr[j] = temp;
	}
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}