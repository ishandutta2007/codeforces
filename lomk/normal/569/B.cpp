#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a[100005], b[100005];
	int cur = 1;
	cin >> n;
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]] += 1;
	}
	for (int i = 0; i < n; i++) {
		if (b[a[i]] > 1 && a[i] <= n) {
			b[a[i]]--;
			while (b[cur] >= 1) cur++;
			a[i] = cur;
			b[cur]++;
		}
		else if (a[i] > n) {
			while (b[cur] >= 1) cur++;
			a[i] = cur;
			b[cur]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}