#include <bits/stdc++.h>
using namespace std;

int tc;
int n, k;
vector<pair<int, int> > a;
vector<set<int> > c;
char b[1005][1005];
char ans[1005][1005];


int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		a.clear();
		c.clear(); c.resize(n);
		int zeros = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", b[i]);
			for (int j = 0; j < n; j++) {
				if (b[i][j] == '0') {
					zeros++;
					//a.emplace_back(n-i-1, j);
					c[n-i-1].insert(j);
				}
				ans[i][j] = '0';
			}
			ans[i][n] = '\0';
		}
		for (int i = k - 2; i >= 0; i--) {
			int curi = i;
			for (int j = 0; j <= n - i - 1; j++) {
				ans[n - j - 1][curi] = '1';
				auto it = c[j].lower_bound(curi);
				while (it != c[j].end()) {
					for (; curi <= *it; curi++) ans[n - j - 1][curi] = '1';
					curi--;
					zeros--;
					c[j].erase(it++);
				}
			}
			for (int l = curi; l < n; l++) {
				ans[i][l] = '1';
			}
		}
		if (zeros != 0) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				printf("%s\n", ans[i]);
			}
		}
	}
	return 0;
}