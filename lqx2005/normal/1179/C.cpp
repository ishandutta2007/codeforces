#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e6 + 10, V = N - 10;
struct node {
	int suf, sum;
	node() {suf = sum = 0; }
	node(int _suf, int _sum) {suf = max(0, _suf), sum = _sum; }
	friend node operator + (const node a, const node b) {
		return node(max(a.suf + b.sum, b.suf), a.sum + b.sum);
	}
};
int n, m, a[N], b[N], sum[N];
node t[N << 1];

void modify(int p, int l, int r, int x) {
	if(l == r) {
		t[p] = node(sum[x], sum[x]);
		return;
	}
	if(x <= mid) modify(ls, l, mid, x);
	else modify(rs, mid + 1, r, x);
	t[p] = t[ls] + t[rs];
	return;
}

int find(int p, int l, int r, node now) {
	if(l == r) return l;
	if((t[rs] + now).suf > 0) return find(rs, mid + 1, r, now);
	return find(ls, l, mid, t[rs] + now);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[a[i]]++;
		modify(1, 0, V, a[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		sum[b[i]]--;
		modify(1, 0, V, b[i]);
	}
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int opt, p, x;
		scanf("%d%d%d", &opt, &p, &x);
		if(opt == 1) {
			sum[a[p]]--;
			modify(1, 0, V, a[p]);
			a[p] = x; 
			sum[a[p]]++;
			modify(1, 0, V, a[p]);
		} else {
			sum[b[p]]++;
			modify(1, 0, V, b[p]);
			b[p] = x;
			sum[b[p]]--;
			modify(1, 0, V, b[p]);
		}
		int pos = find(1, 0, V, node());
		if(pos == 0) printf("-1\n");
		else printf("%d\n", pos);
	}
	return 0;
}