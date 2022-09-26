#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int M = 1000007;

struct Node {
	long long sum, suf;
	Node Merge(const Node& nd) {
		Node ret;
		ret.sum = sum + nd.sum;
		ret.suf = max(suf + nd.sum, nd.suf);
		return ret;
	}
};

int q;
int tt[N], dd[N];
int add[M];
Node T[M << 2];

#define mid ((l + r) >> 1)
void build(int v,int l,int r) {
	if (l == r) {
		T[v].sum = -1;
		T[v].suf = 0;
		return;
	}
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	T[v] = T[v << 1].Merge(T[v << 1 | 1]);
}

void upd(int v,int l,int r,int u,int z) {
	if (l == r) {
		T[v].sum += 1LL * z;
		T[v].suf = max(0LL, T[v].sum);
		return;
	}
	if (u <= mid) upd(v << 1, l, mid, u, z);
	else upd(v << 1 | 1, mid + 1, r, u, z);
	T[v] = T[v << 1].Merge(T[v << 1 | 1]);
}

Node get(int v,int l,int r,int L,int R) {
	if (L == l && R == r) return T[v];
	if (R <= mid) return get(v << 1, l, mid, L, R);
	else if (L > mid) return get(v << 1 | 1, mid + 1, r, L, R);
	else {
		return get(v << 1, l, mid, L, mid).Merge(
			get(v << 1 | 1, mid + 1, r, mid + 1, R)
		);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> q;
	build(1, 0, M - 1);
	for (int i = 1; i <= q; ++i) {
		char op; cin >> op;
		if (op == '+') {
			cin >> tt[i] >> dd[i];
			add[tt[i]] += dd[i];
			upd(1, 0, M - 1, tt[i], dd[i]);
		} else if (op == '-') {
			int id; cin >> id;
			add[tt[id]] -= dd[id];
			upd(1, 0, M - 1, tt[id], -dd[id]);
		} else {
			int t; cin >> t;
			long long ans = get(1, 0, M - 1, 0, t - 1).suf;
			ans += add[t];
			cout << ans << '\n';
		}
	}
}