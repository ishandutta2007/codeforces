#include <bits/stdc++.h>
using namespace std;

#define N 101111
int n, x, y;
int a[N];

int main() {
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		bool flag = 1;
		for (int j = max(i - x, 1); j <= min(i + y, n); j++) {
			if (a[i] > a[j]) flag = 0; 
		}
		if (flag) {
			cout << i << endl;
			return 0;
		}
	}
}