#include<bits/stdc++.h>
#define mid ((l + r) / 2)
#define ls p + 1
#define rs p + (mid - l + 1) * 2
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e5 + 10;
int tag[N << 1], sum[N << 1];
int n, q, l[N], r[N];
char s[N], f[N];
void upd(int p, int l, int r) {
	sum[p] = sum[ls] + sum[rs];
}

void build(int p, int l, int r) {
	tag[p] = -1;
	if(l == r) {
		sum[p] = f[l] - '0';
		return;
	}
	build(ls, l, mid), build(rs, mid + 1, r);
	upd(p, l, r);
}

void D(int p, int l, int r, int v) {
	tag[p] = v;
	sum[p] = (r - l + 1) * v;
	return;
}

void pushd(int p, int l, int r) {
	if(tag[p] < 0) return;
	D(ls, l, mid, tag[p]), D(rs, mid + 1, r, tag[p]);
	tag[p] = -1;
}

void modify(int p, int l, int r, int L, int R, int t) {
	if(L <= l && r <= R) {
		D(p, l, r, t);
		return;
	}
	pushd(p, l, r);
	if(L <= mid) modify(ls, l, mid, L, R, t);
	if(R > mid) modify(rs, mid + 1, r, L, R, t);
	upd(p, l, r);
}

int Quer(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) return sum[p];
	pushd(p, l, r);
	int res = 0;
	if(L <= mid) res += Quer(ls, l, mid, L, R);
	if(R > mid) res += Quer(rs, mid + 1, r, L, R);
	return res;
}

int work() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	scanf("%s", f + 1);
	build(1, 1, n);
	for(int i = 1; i <= q; i++) scanf("%d%d", &l[i], &r[i]);
	for(int i = q; i >= 1; i--) {
		int now = Quer(1, 1, n, l[i], r[i]);
		int t = r[i] - l[i] + 1;
		if(now * 2 == t) return 0;
		if(now * 2 < t) modify(1, 1, n, l[i], r[i], 0);
		else modify(1, 1, n, l[i], r[i], 1);
	}
	for(int i = 1; i <= n; i++) if(Quer(1, 1, n, i, i) != s[i] - '0') return 0;
	return 1;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) printf(work() ? "YES\n" : "NO\n");
	return 0;
}