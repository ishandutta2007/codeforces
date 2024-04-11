#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
int a[Maxn];
bool dp[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int all = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			all ^= a[i];
		}
		if (all == 0) { printf("YES\n"); continue; }
		bool res = false;
		int nd = 0;
		for (int i = 0; i + 1 < n; i++) {
			nd ^= a[i];
			if (nd != all) continue;
			bool ok = false;
			int my = 0;
			for (int j = i + 1; j < n; j++) {
				my ^= a[j];
				if (my == nd) ok = true;
			}
			if (ok) res = true;
		}
		printf("%s\n", res? "YES": "NO");
	}
    return 0;
}