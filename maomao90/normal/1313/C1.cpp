#include <bits/stdc++.h>
using namespace std;

int n;
int m[1005];
int ans;
int arr[1005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &m[i]);
	long long curmax = -1;
	for (int i = 0; i < n; i++) {
		int temp = m[i];
		long long sum = 0;
		for (int j = i; j >= 0; j--) {
			temp = min(m[j], temp);
			sum += temp;
		}
		temp = m[i];
		for (int j = i + 1; j < n; j++) {
			temp = min(m[j], temp);
			sum += temp;
		}
		if (sum > curmax) {
			curmax = sum;
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