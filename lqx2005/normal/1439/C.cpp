#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
int n, q, a[N]; 
int mx[N << 1], tag[N << 1];
LL sum[N << 1];


void upd(int p, int l, int r) {
	sum[p] = sum[lc] + sum[rc];
	mx[p] = max(mx[lc], mx[rc]);
	return;
}

void pushd(int p, int l, int r) {
	if(!tag[p]) return;
	tag[lc] = mx[lc] = tag[rc] = mx[rc] = tag[p];
	sum[lc] = 1ll * (mid - l + 1) * tag[p], sum[rc] = 1ll * (r - mid) * tag[p];
	tag[p] = 0;
	return;
}

void build(int p, int l, int r) {
	tag[p] = 0;
	if(l == r) return sum[p] = mx[p] = a[l], void();
	build(lc, l, mid), build(rc, mid + 1, r);
	return upd(p, l, r), void();
}

void modify(int p, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) {
		sum[p] = 1ll * (r - l + 1) * v;
		mx[p] = tag[p] = v;
		return;
	}
	pushd(p, l, r);
	if(L <= mid) modify(lc, l, mid, L, R, v);
	if(R > mid) modify(rc, mid + 1, r, L, R, v);
	return upd(p, l, r), void();
}

int find(int p, int l, int r, int v) {
	if(l == r) return l - (mx[p] <= v);
	return pushd(p, l, r), mx[rc] > v ? find(rc, mid + 1, r, v) : find(lc, l, mid, v);
}

LL ask(int p, int l, int r, int x) {
	if(l == r) return sum[p] * (x >= l);
	pushd(p, l, r);
	if(x <= mid) return ask(lc, l, mid, x);
	return sum[lc] + ask(rc, mid + 1, r, x);
}

int Find(int p, int l, int r, LL v) {
	if(l == r) return l - (sum[p] > v); 
	return pushd(p, l, r), sum[lc] > v ? Find(lc, l, mid, v) : Find(rc, mid + 1, r, v - sum[lc]);
}

int query(int x, int y) {
	int ans = 0;
	for(x = max(find(1, 1, n, y) + 1, x); x <= n; x = max(find(1, 1, n, y) + 1, x)) {
		LL s = ask(1, 1, n, x - 1);
		int ed = Find(1, 1, n, y + s);
		ans += ed - x + 1;
		y -= ask(1, 1, n, ed) - s;
		x = ed + 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			int p = find(1, 1, n, y);
			if(p + 1 <= x) modify(1, 1, n, p + 1, x, y);
		} else printf("%d\n", query(x, y)); 
	}
	return 0;
}