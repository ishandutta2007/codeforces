#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 3e4 + 10;
const i64 oo = 0x3f3f3f3f3f3f3f3f;
struct Mat {
	i64 a[3][3];
	Mat() {memset(a, 0xc0, sizeof(a)); }
	friend Mat operator + (const Mat a, const Mat b) {
		Mat c;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k < 3; k++) {
					c.a[i][j] = max(c.a[i][j], a.a[i][k] + b.a[k][j]);
				}
			}
		}
		return c;
	}
}t[N << 1];
int n, q, w[N], h[N], W[N], H[N];
int id1[N], id2[N], rev1[N], rev2[N];
int match[N];

void chkmax(i64 &x, i64 y) {
	if(x < y) x = y;
}

void upd(int p, int l, int r) {
	t[p] = t[lc] + t[rc];
}

void updata(int p, int x) {
	memset(t[p].a, 0xc0, sizeof(t[p].a));
	t[p].a[2][1] = 0, t[p].a[1][0] = 0;
	if(match[x] != x) t[p].a[0][0] = 1ll * W[x] * H[x];
	if(x + 1 <= n && match[x] != x + 1 && match[x + 1] != x) t[p].a[0][1] = 1ll * W[x] * H[x + 1] + 1ll * W[x + 1] * H[x];
	if(x + 2 <= n) {
		if(match[x] != x + 1 && match[x + 1] != x + 2 && match[x + 2] != x) {
			chkmax(t[p].a[0][2], 1ll * W[x] * H[x + 1] + 1ll * W[x + 1] * H[x + 2] + 1ll * W[x + 2] * H[x]);
		}
		if(match[x + 1] != x && match[x + 2] != x + 1 && match[x] != x + 2) {
			chkmax(t[p].a[0][2], 1ll * W[x] * H[x + 2] + 1ll * W[x + 1] * H[x] + 1ll * W[x + 2] * H[x + 1]);
		}
	}
	return;
}

void modify(int p, int l, int r, int x) {
	if(l == r) return updata(p, x);
	if(x <= mid) modify(lc, l, mid, x);
	else modify(rc, mid + 1, r, x);
	return upd(p, l, r);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]), id1[i] = i;
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]), id2[i] = i;
	sort(id1 + 1, id1 + n + 1, [&](int x, int y) {
		return w[x] < w[y];
	});
	sort(id2 + 1, id2 + n + 1, [&](int x, int y) {
		return h[x] < h[y];
	});
	for(int i = 1; i <= n; i++) {
		W[i] = w[id1[i]];
		H[i] = h[id2[i]];
		rev1[id1[i]] = rev2[id2[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		match[i] = rev2[id1[i]];
	}
	for(int i = 1; i <= n; i++) modify(1, 1, n, i);
	for(int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = rev1[a], b = rev1[b];
		swap(match[a], match[b]);
		for(int j = max(1, a - 2); j <= a; j++) modify(1, 1, n, j);
		for(int j = max(1, b - 2); j <= b; j++) modify(1, 1, n, j);
		printf("%lld\n", t[1].a[0][0]);
	}
    return 0;
}