#include <bits/stdc++.h>
using namespace std;

char s[200050];

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		scanf("%s", s);
		vector<int> a, maxi1, mini1, maxi2, mini2;
		a.resize(n+1, 0);
		maxi1.resize(n+1, 0);
		mini1.resize(n+1, 0);
		maxi2.resize(n+1, 0);
		mini2.resize(n+1, 0);
		for (int i = 0; i < n; i++) {
			if (s[i] == '+') a[i+1] = a[i] + 1;
			else if (s[i] == '-') a[i+1] = a[i] - 1;
			maxi1[i+1] = max(maxi1[i], a[i+1]);
			mini1[i+1] = min(mini1[i], a[i+1]);
		}
		maxi2[n] = a[n];
		mini2[n] = a[n];
		for (int i = n-1; i >= 0; i--) {
			maxi2[i] = max(maxi2[i+1], a[i]);
			mini2[i] = min(mini2[i+1], a[i]);
		}
		int i1, i2;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &i1, &i2);
			int dif = a[i2] - a[i1-1];
			int maxi = max(maxi1[i1-1], maxi2[i2] - dif);
			int mini = min(mini1[i1-1], mini2[i2] - dif);
			printf("%d\n", maxi - mini + 1);
		}
	}
	return 0;
}