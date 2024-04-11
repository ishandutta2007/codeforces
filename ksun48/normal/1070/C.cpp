#include <bits/stdc++.h>
using namespace std;

#define N 4100000

int len;
int n, k, m;
struct aa {
	int x, pos, s;
} a[N];

long long s[N], sum[N];

bool cmp(aa a, aa b) {
	return a.x < b.x;
}

void modify(int k, int q, int h, int x, int ss) {
	s[k] += ss;
	sum[k] += 1LL * x * ss;
	if (q < h) {
		if (x <= (q + h) / 2)
			modify(k * 2, q, (q + h) / 2, x, ss);
		else
			modify(k * 2 + 1, (q + h) / 2 + 1, h, x, ss);
	}
}

long long query(int k, int q, int h, int pre) {
	if (q == h) {
		return min(sum[k], 1LL * pre * q);
	}else {
		if (s[k * 2] <= pre)
			return query(k * 2 + 1, (q + h) / 2 + 1, h, pre - s[k * 2]) + sum[k * 2];
		else
			return query(k * 2, q, (q + h) / 2, pre);
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= m; i++) {
		int l, r, c, p;
		scanf("%d%d%d%d", &l, &r, &c, &p);
		len++;
		a[len].x = l;
		a[len].pos = p;
		a[len].s = c;
		len++;
		a[len].x = r + 1;
		a[len].pos = p;
		a[len].s = -c;
	}
	sort(a + 1, a + len + 1, cmp);
	long long ans = 0;
	int h = 1;
	for (int i = 1; i <= n; i++) {
		while (h <= len && a[h].x <= i) {
			modify(1, 1, 1000000, a[h].pos, a[h].s);
			h++;
		}
		ans += query(1, 1, 1000000, k);
	}
	cout << ans << endl;
}