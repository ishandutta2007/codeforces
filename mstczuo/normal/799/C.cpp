# include <bits/stdc++.h>

using namespace std;

int n, c, d;

const int maxn = 100010;

pair<int, int> a[maxn], b[maxn];

int nc, nd;

char buf[120];

int w, p;
int wc = -1, wd = -1;

int mx[maxn];
int calc(pair<int,int> a[],int n,int C) {
	if(n < 2) return 0;
	sort(a, a + n);
	int ret = 0;
	mx[0] = a[0].second;
	for(int i = 1; i < n; ++i) mx[i] = max(mx[i-1], a[i].second);
	for(int i = 1; i < n; ++i) {
		int j = upper_bound(a, a + n, pair<int,int>(C - a[i].first, ~0u>>1)) - a;
		j = min(j - 1, i - 1);
		if(j >= 0) ret = max(ret, a[i].second + mx[j]);
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &c, &d);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%s", &w, &p, buf);
		if(buf[0] == 'C') {
			if(p <= c) a[nc++] = {p, w}, wc = max(wc, w);
		} else {
			if(p <= d) b[nd++] = {p, w}, wd = max(wd, w);
		}
	}
	int ans = max(calc(a, nc, c), calc(b, nd, d));
	if(wc != -1 && wd != -1) ans = max(ans, wc + wd);
	printf("%d\n", ans);
	return 0;
}