# include <bits/stdc++.h>
using namespace std;

int p[300000+10];
char col[300000+10];

int main() {
	char buff[120];
	int n; scanf("%d", &n);
	int r0 = -1, b0 = -1, g0 = -1;
	int r1 = -1, b1 = -1, g1 = -1;
	for(int i = 0; i < n; ++i) {
		scanf("%d%s", &p[i], buff);
		col[i] = buff[0];
		if(col[i] == 'R' && r0 == -1) r0 = i;
		if(col[i] == 'B' && b0 == -1) b0 = i;
		if(col[i] == 'G' && g0 == -1) g0 = i;
		if(col[i] == 'R') r1 = i;
		if(col[i] == 'B') b1 = i;
		if(col[i] == 'G') g1 = i;
	}

	long long ans = 0;
	if(g0 == -1) {
		if(~r0) ans += p[r1] - p[r0];
		if(~b0) ans += p[b1] - p[b0];
		cout << ans << endl;
		return 0;
	}

	if(~r0 && r0 < g0) ans += p[g0] - p[r0];
	if(~b0 && b0 < g0) ans += p[g0] - p[b0];
	if(~r1 && r1 > g1) ans += p[r1] - p[g1];
	if(~b1 && b1 > g1) ans += p[b1] - p[g1];
	for(int i = g0, j; i < g1; i = j) {
		for(j = i + 1; col[j] != 'G'; ++j);
		int len = p[j] - p[i], tmp = 0;
		{
			int last = i, max_int = 0;
			for(int k = i + 1; k < j; ++k) if(col[k] == 'R') {
				max_int = max(max_int, p[k] - p[last]);
				last = k;
			}
			max_int = max(max_int, p[j] - p[last]);
			tmp += max_int;
		}
		{
			int last = i, max_int = 0;
			for(int k = i + 1; k < j; ++k) if(col[k] == 'B') {
				max_int = max(max_int, p[k] - p[last]);
				last = k;
			}
			max_int = max(max_int, p[j] - p[last]);
			tmp += max_int;
		}
		ans += len * 2; ans += min(len - tmp, 0);
	}
	cout << ans << endl;
	return 0;
}