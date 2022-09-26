#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[12];
int cnt[1 << 12];
int prf[1 << 12][1 << 12];
int f[1 << 12];
vector<pair<int,int>> vals[1 << 12];

int toInt(char s[]) {
	int ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		ret = ret * 2 + (s[i] - '0');
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	while (m--) {
		static char s[15]; scanf("%s", s);
		int tmp = toInt(s);
		cnt[tmp]++;
	}
	
	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) if ((mask >> i) & 1) {
			f[mask] += a[i];
		}
	}
	
	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
			int cur = ((1 << n) - 1) ^ (mask ^ mask2);
			vals[mask].push_back({f[cur], mask2});
		}
		sort(vals[mask].begin(), vals[mask].end());
		for (int i = 0; i < (1 << n); ++i) {
			prf[mask][i] = cnt[vals[mask][i].second];
			if (i) prf[mask][i] += prf[mask][i - 1];
		}
	}
	
	while (q--) {
		static char s[15]; int k; scanf("%s %d", s, &k);
		int tmp = toInt(s);
		int pos = upper_bound(vals[tmp].begin(), vals[tmp].end(), make_pair(k, (1 << n))) - vals[tmp].begin() - 1;
		if (pos < 0) {
			cout << 0 << '\n';
		}
		else {
			cout << prf[tmp][pos] << '\n';
		}
	}
}