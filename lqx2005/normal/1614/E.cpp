#include<bits/stdc++.h>
 
using namespace std;

#define x first
#define y second
#define pb push_back
 
typedef pair<int, int> par;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, K = 30, T = N * K * 6, V = 1e9;
int n;
int ls[T], rs[T], add[T], mn[T], mx[T], tot = 0;
int newd(int l, int r) {
	int p = ++tot;
	mn[p] = l, mx[p] = r, add[p] = 0;
	return p;
}
void updata(int p) {
	mn[p] = min(mn[ls[p]], mn[rs[p]]);
	mx[p] = max(mx[ls[p]], mx[rs[p]]);
	return;
}
void down(int &p, int l, int r, int v) {
	if(!p) p = newd(l, r);
	add[p] += v, mn[p] += v, mx[p] += v;
	return;
}
void pushdown(int p, int l, int r) {
	int mid = (l + r) / 2;
	down(ls[p], l, mid, add[p]);
	down(rs[p], mid + 1, r, add[p]);
	add[p] = 0;
	return;
}
void modify(int &p, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) {
		down(p, l, r, v);
		return;
	}
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	if(L <= mid) modify(ls[p], l, mid, L, R, v);
	if(R > mid) modify(rs[p], mid + 1, r, L, R, v);
	return updata(p);
}

int queryR(int p, int l, int r, int v) {
	if(mn[p] > v) return -1;
	if(l == r) return l;
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	if(mn[rs[p]] <= v) return queryR(rs[p], mid + 1, r, v);
	return queryR(ls[p], l, mid, v);
}
int queryL(int p, int l, int r, int v) {
	if(mx[p] < v) return V + 1;
	if(l == r) return l;
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	if(mx[ls[p]] >= v) return queryL(ls[p], l, mid, v);
	return queryL(rs[p], mid + 1, r, v);
}
int ask(int p, int l, int r, int x) {
	if(l == r) return mn[p];
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	if(x <= mid) return ask(ls[p], l, mid, x);
	return ask(rs[p], mid + 1, r, x);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	int lastans = 0, rt = newd(0, V);
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		int l = queryL(rt, 0, V, t), r = queryR(rt, 0, V, t);
		if(l - 1 >= 0) modify(rt, 0, V, 0, l - 1, 1);
		if(r + 1 <= V) modify(rt, 0, V, r + 1, V, -1);
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			(x += lastans) %= (V + 1);
			cout << (lastans = ask(rt, 0, V, x)) << endl;
		}
	}
    return 0;
}