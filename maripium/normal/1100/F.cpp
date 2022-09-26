#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, q;
int a[N];
vector<int> pre[N], suf[N];
int ll[N], rr[N];
int ans[N];

int get(int x) {
	return 1 << __lg(x);
}

void add(vector<int> &a,int v) {
	for (int x : a) {
		if (get(x) & v) v ^= x;
	}
	if (!v) {
		return;
	}
	for (int& x : a) {
		if (get(v) & x) x ^= v;
	}
	a.push_back(v);
}
 
int merge(vector<int> a,vector<int> b) {
	vector<int> z;
	for (int x : a) add(z, x);
	for (int x : b) add(z, x);
	sort(z.begin(), z.end(), greater<int>());
	int ans = 0;
	for (int x : z) {
		ans = max(ans, ans ^ x);
	}
	return ans;
}

void solve(int l,int r, vector<int> vq) {
	if (l == r) {
		for (int id : vq) {
			ans[id] = a[l];
		}
		return;
	}
	for (int i = l; i <= r; ++i) {
		pre[i].clear();
		suf[i].clear();
	}
	int mid = (l + r) >> 1;
	for (int i = mid; i >= l; --i) {
		suf[i] = suf[i + 1];
		add(suf[i], a[i]);
	}
	for (int i = mid + 1; i <= r; ++i) {
		pre[i] = pre[i - 1];
		add(pre[i], a[i]);
	}
	vector<int> vql, vqr;
	for (int id : vq) {
		if (ll[id] >= mid + 1) {
			vqr.push_back(id);
		} else if (rr[id] <= mid) {
			vql.push_back(id);
		} else {
			ans[id] = merge(suf[ll[id]], pre[rr[id]]);
		}
	}
	solve(l, mid, vql);
	solve(mid + 1, r, vqr);
}

int main() {	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	scanf("%d", &q);
	vector<int> vq;
	for (int i = 1; i <= q; ++i) {
		scanf("%d %d", ll + i, rr + i);
		vq.push_back(i);
	} 
	solve(1, n, vq);
	for (int i = 1; i <= q; ++i) {
		printf("%d\n", ans[i]);
	}
}