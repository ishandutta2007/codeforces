#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
int d[205];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(d, 0, sizeof d);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a; scanf("%d", &a);
				d[i + j] ^= a;
			}
		}
		bool aWin = false;
		for (int i = 0; i < n + m - 1; i++) {
			if (d[i] != 0) aWin = true;
		}
		if (aWin) printf("Ashish\n");
		else printf("Jeel\n");
	}
	return 0;
}