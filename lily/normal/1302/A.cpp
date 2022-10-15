#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 101111

int n;
int a[N], b[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 29; j++) {
			b[j] += (a[i] >> j) & 1;
		}
	}
	int ans = 0, id = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 29; j++) {
			b[j] -= (a[i] >> j) & 1;
		}
		int t = 0;
		for (int j = 0; j <= 29; j++) {
			if (((a[i] >> j) & 1) && b[j] == 0) t += 1 << j;
		}
		if (t > ans) {
			ans = t;
			id = i;
		}
		for (int j = 0; j <= 29; j++) {
			b[j] += (a[i] >> j) & 1;
		}
	}
	swap(a[1], a[id]);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}