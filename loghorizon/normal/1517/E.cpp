// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5, P = 998244353;

int n, a[N], ans;

LL s[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

void solve(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int t = 0; LL s0 = 0, s1 = 0;
	vector<LL> b;
	for (int i = mid; i >= l; i--) {
		if (i == 1) continue;
		if (t == 1) {
			s1 += a[i];
			b.pb((s0 + s[i - 1]) - s1);
			if (i > 2) b.pb((s0 + s[i - 1] - a[1]) - (s1 + a[1]));
		} else {
			s0 += a[i];
		}
		t ^= 1;
	}
	t = 1, s0 = 0, s1 = 0;
	vector<LL> c;
	for (int i = mid + 1; i <= r; i++) {
		if (i == n) continue;
		if (t == 0) {
			s0 += a[i];
			c.pb((s1 + s[n] - s[i]) - s0);
			if (i + 1 != n)
			c.pb((s1 + s[n] - s[i] - a[n]) - (s0 + a[n]));
		} else {
			s1 += a[i];
		}
		t ^= 1;
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (int i = 0, j = 0; i < c.size(); i++) {
		while (j < b.size() && b[j] < c[i]) j++;
		add(ans, j);
	}
	b.clear(), c.clear();
	t = 1; s0 = 0, s1 = 0;
	for (int i = mid; i >= l; i--) {
		if (i == 1) continue;
		if (t == 1) {
			s1 += a[i];
			b.pb((s0 + s[i - 1]) - s1);
			if (i > 2) b.pb((s0 + s[i - 1] - a[1]) - (s1 + a[1]));
		} else {
			s0 += a[i];
		}
		t ^= 1;
	}
	t = 0, s0 = 0, s1 = 0;
	for (int i = mid + 1; i <= r; i++) {
		if (i == n) continue;
		if (t == 0) {
			s0 += a[i];
			c.pb((s1 + s[n] - s[i]) - s0);
			if (i + 1 != n)
			c.pb((s1 + s[n] - s[i] - a[n]) - (s0 + a[n]));
		} else {
			s1 += a[i];
		}
		t ^= 1;
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (int i = 0, j = 0; i < c.size(); i++) {
		while (j < b.size() && b[j] < c[i]) j++;
		add(ans, j);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
		for (int i = 1; i <= n; i++) {
			LL s0 = s[i - 1], s1 = s[n] - s[i - 1];
			if (s0 < s1) (ans += 1) %= P;
			if (i > 2) {
				s0 -= a[1], s1 += a[1];
				if (s0 < s1) (ans += 1) %= P;
				s0 += a[1], s1 -= a[1];
			}
			if (i < n) {
				s0 += a[n], s1 -= a[n];
				if (s0 < s1) (ans += 1) %= P;
				s0 -= a[n], s1 += a[n];
			}
			if (i > 2 && i < n) {
				s0 -= a[1], s1 += a[1];
				s0 += a[n], s1 -= a[n];
				if (s0 < s1) (ans += 1) %= P;
			}
		}
		for (int i = 1; i + 1 < n; i++) {
			if (s[i] > s[n] - s[i]) (ans += 1) %= P;
		}
		solve(1, n);
		printf("%d\n", ans);
	}
	return 0;
}