#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define db double
#define i64 long long
#define u64 unsigned long long
#define mid ((l + r) >> 1)
#define lson (p + 1)
#define rson (p + ((mid - l + 1) << 1)) 
using namespace std;
const int N = 2e5 + 10, oo = 0x3f3f3f3f;
int T, n, a[N], id[N];
int mx[N << 1], tag[N << 1];

void pushd(int p, int l, int r) {
	if(!tag[p]) return;
	tag[lson] += tag[p], tag[rson] += tag[p], mx[lson] += tag[p], mx[rson] += tag[p];
	tag[p] = 0;
	return;
}

void build(int p, int l, int r) {
	tag[p] = 0;
	if(l == r) {
		mx[p] = (l & 1) + (n - l);
		return;
	}
	build(lson, l, mid), build(rson, mid + 1, r);
	mx[p] = max(mx[lson], mx[rson]);
	return;
} 

void change(int p, int l, int r, int L, int R, int v) {
	if(L > R) return;
	if(L <= l && r <= R) {
		tag[p] += v;
		mx[p] += v;
		return;
	}
	pushd(p, l, r);
	if(L <= mid) change(lson, l, mid, L, R, v);
	if(R > mid) change(rson, mid + 1, r, L, R, v);
	mx[p] = max(mx[lson], mx[rson]);
	return; 
}

void modify(int p, int l, int r, int x, int v) {
	if(l == r) return mx[p] = v, void();
	pushd(p, l, r);
	if(x <= mid) modify(lson, l, mid, x, v);
	else modify(rson, mid + 1, r, x, v);
	mx[p] = max(mx[lson], mx[rson]);
	return; 
}

int query(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return mx[p];
	}
	pushd(p, l, r);
	int res = -oo;
	if(L <= mid) res = max(res, query(lson, l, mid, L, R));
	if(R > mid) res = max(res, query(rson, mid + 1, r, L, R));
	return res;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i], id[i] = i;
	}	
	sort(id + 1, id + n + 1, [&](int x, int y) {
		return a[x] > a[y];
	});
	build(1, 1, n);
	int ans = 0, left = n + 1;
	for(int i = 1; i <= n; i++) {
		modify(1, 1, n, id[i], -oo);
		change(1, 1, n, 1, id[i] - 1, -1);
		change(1, 1, n, id[i] + 1, n, 1);
		left = min(left, id[i]);
		ans = max(ans, query(1, 1, n, left, n));
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T--; ) solve();
	return 0;
}
/*
b[i] = (m - i + k[i] + p[i] % 2)
*/