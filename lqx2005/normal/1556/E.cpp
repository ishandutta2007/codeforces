#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;
const int N = 1e5 + 10;

struct node {
	i64 mx, mn, sum;
	node() {mx = mn = sum = 0; }
	node(i64 Mx, i64 Mn, i64 Sum) {mx = Mx, mn = Mn, sum = Sum; }
	friend node operator + (node a, node b) {
		return node(max(a.mx, b.mx + a.sum), min(a.mn, b.mn + a.sum), a.sum + b.sum);
	}
}t[N << 2];
int a[N], b[N];
i64 sum[N];

void build(int p, int l, int r) {
	if(l == r) {
		t[p].mn = min(0, a[l] - b[l]);
		t[p].mx = max(0, a[l] - b[l]);
		t[p].sum = a[l] - b[l];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	t[p] = t[ls] + t[rs];
	return;
}

node query(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) return t[p];
	if(R <= mid) return query(ls, l, mid, L, R);
	if(L > mid) return query(rs, mid + 1, r, L, R);
	return query(ls, l, mid, L, mid) + query(rs, mid + 1, r, mid + 1, R); 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i] - b[i];
	}
	build(1, 1, n);
	for(int i = 1, l, r; i <= q; i++) {
		cin >> l >> r;
		node res = query(1, 1, n, l, r);
		if(res.mx > 0 || sum[r] - sum[l - 1] != 0) cout << -1 << endl;
		else cout << - res.mn << endl;
	}
	return 0; 
}