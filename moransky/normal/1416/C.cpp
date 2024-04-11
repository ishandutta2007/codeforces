#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 300005;

int n, a[N], b[N], x[N], y[N], d[N], ans;

LL sum, cnt[40];

void solve(int l, int r, int w) {
	if (l >= r) return;
	if (w == -1) return;
	int c0 = 0, c1 = 0;
	int len1 = 0, len2 = 0;
	for (int i = l; i <= r; i++) {
		if (b[i] >> w & 1) {
			y[++len2] = b[i];
			cnt[w] += c0;
		} else {
			x[++len1] = b[i];
			cnt[w] -= c1;
		}
		if (b[i] >> w & 1) c1++;
		else c0++;
	}
	for (int i = 1; i <= len1; i++) b[l + i - 1] = x[i];
	for (int i = 1; i <= len2; i++) b[l + len1 - 1 + i] = y[i];
	solve(l, l + len1 - 1, w - 1);
	solve(l + len1, r, w - 1);
}

void merge(int l, int mid, int r) {
    for (int i = l, j = mid + 1, k = l; k <= r; k++) {
        if (j > r || (i <= mid && a[i] <= a[j])) d[k] = a[i++];
        else d[k] = a[j++], sum += mid - i + 1;
    }
    for (int i = l; i <= r; i++) a[i] = d[i];
}
void Msort(int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        Msort(l, mid);
        Msort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
	solve(1, n, 30);
	for (int i = 30; ~i; i--) {
		if (cnt[i] < 0) ans |= 1 << i;
	}
	for (int i = 1; i <= n; i++) a[i] ^= ans;
	Msort(1, n);
	printf("%lld %d\n", sum, ans);
	return 0;
}