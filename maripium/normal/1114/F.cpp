#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
const int mod = 1e9 + 7;

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int power(int x,int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int n, q;
int a[N];
int cf[305];
long long val[305];
int t1[N << 2];
long long t2[N << 2];
int lz1[N << 2];
long long lz2[N << 2];
char buf[123];
vector<int> pr;

void prep() {
	int now = 0;
	vector<bool> np(305, false);
	for (int i = 2; i < 305; ++i) if (!np[i]) {
		pr.push_back(i);
		cf[i] = mul(i - 1, power(i, mod - 2));
		for (int j = i; j < 305; j += i) {
			np[j] = true;
			val[j] |= (1LL << (pr.size() - 1));
		}
	}
}

#define mid ((l + r) >> 1)
void push(int v,int l,int r) {
	t1[v] = mul(t1[v], power(lz1[v], r - l + 1));
	t2[v] |= lz2[v];
	if (l < r) {
		lz1[v << 1] = mul(lz1[v << 1], lz1[v]);
		lz2[v << 1] |= lz2[v];
		lz1[v << 1 | 1] = mul(lz1[v << 1 | 1], lz1[v]);
		lz2[v << 1 | 1] |= lz2[v];
	}
	lz1[v] = 1;
	lz2[v] = 0;
}

void pull(int v) {
	t1[v] = mul(t1[v << 1], t1[v << 1 | 1]);
	t2[v] = t2[v << 1] | t2[v << 1 | 1];
}

void build(int v,int l,int r) {
	lz1[v] = 1;
	lz2[v] = 0;
	if (l == r) {
		t1[v] = a[l];
		t2[v] = val[a[l]];
		return;
	}
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	pull(v);
}

void upd(int v,int l,int r,int L,int R,int x) {
	push(v, l, r);
	if (L > r || R < l) return;
	if (L <= l && R >= r) {
		lz1[v] = x;
		lz2[v] = val[x];
		push(v, l, r);
		return;
	}
	upd(v << 1, l, mid, L, R, x);
	upd(v << 1 | 1, mid + 1, r, L, R, x);
	pull(v);
}

int get1(int v,int l,int r,int L,int R) {
	push(v, l, r);
	if (L > r || R < l) return 1;
	if (L <= l && R >= r) {
		return t1[v];
	}
	return mul(get1(v << 1, l, mid, L, R), get1(v << 1 | 1, mid + 1, r, L, R));
}

long long get2(int v,int l,int r,int L,int R) {
	push(v, l, r);
	if (L > r || R < l) return 0;
	if (L <= l && R >= r) {
		return t2[v];
	}
	return get2(v << 1, l, mid, L, R) | get2(v << 1 | 1, mid + 1, r, L, R);
}

int main() {
	prep();
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	build(1, 1, n);
	while (q--) {
		scanf("%s", buf);
		if (buf[0] == 'M') {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			upd(1, 1, n, l, r, x);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			int ans = get1(1, 1, n, l, r);
			long long val = get2(1, 1, n, l, r);
			for (int i = 0; i < pr.size(); ++i) if ((val >> i) & 1LL) {
				ans = mul(ans, cf[pr[i]]);
			}
			printf("%d\n", ans);
		}
	}
}