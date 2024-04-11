#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

typedef long long LL;

const int N = 5e5 + 5, P = 1e9 + 7;

int n, m, s[N], f[N], h[N], pos[N], loc, L[N], R[N];

vector<int> a[N], b[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", s + i), a[s[i]].pb(i);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", f + i, h + i);
		swap(f[i], h[i]);
		b[h[i]].pb(f[i]);
		if (f[i] - 1 < a[h[i]].size())
			pos[a[h[i]][f[i] - 1]] = i;
	}
	for (int i = 1; i <= n; i++) sort(b[i].begin(), b[i].end());
	int ans = 0, cnt = 1;
	for (int i = 0; i <= n; i++) {
		if (pos[i] || i == 0) {
			loc = i;
			for (int j = 1; j <= n; j++) {
				L[j] = R[j] = 0;
				for (int k = 0; k < a[j].size(); k++) {
					if (a[j][k] <= loc) L[j]++;
					else R[j]++;
				}
			}
			int mx = 0, res = 1;
			//cout << "join for fun " << i << " " << pos[i] << " qwq\n";
			if (i) {
				mx = 1;
				int sm = 0; bool o = false;
				for (int j = 1; j <= m; j++) {
					if (pos[i] != j && h[j] == s[i] && f[j] <= R[s[i]]) {
						sm++; o = true;
					}
				}
				if (o) mx++, res = 1ll * res * sm % P;
			}
			for (int j = 1; j <= n; j++) {
				if (j == s[i]) continue;
				if (b[j].size() >= 2 && ((b[j][0] <= L[j] && b[j][1] <= R[j]) || (b[j][0] <= R[j] && b[j][1] <= L[j]))) {
					mx += 2;
					int s1 = 0, s2 = 0, s3 = 0;
					for (int k = 0; k < b[j].size(); k++) {
						int t = b[j][k];
						if (t <= L[j]) s1 ++;
						if (t <= R[j]) s2 ++;
						if (t <= L[j] && t <= R[j]) s3++;
					}
					int rs = (1ll * s1 * s2 - s3 + P) % P;
					res = 1ll * res * rs % P;
				} else if (b[j].size() >= 1 && (b[j][0] <= L[j] || b[j][0] <= R[j])) {
					mx += 1;
					int sm = 0;
					for (int k = 0; k < b[j].size(); k++) {
						int t = b[j][k];
						if (t <= L[j]) sm ++;
						if (t <= R[j]) sm++;
					}
					res = 1ll * res * sm % P;
				}
			}
			if (mx > ans) ans = mx, cnt = res;
			else if (mx == ans) cnt = (cnt + res) % P;
		}
	}
	if (ans == 0) cnt = 1;
	printf("%d %d\n", ans, cnt);
	return 0;
}