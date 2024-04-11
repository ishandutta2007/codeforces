#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
int a[N], p[N];
int l[N], r[N];
int ll[N], rr[N];
int par[N];
long long ans[N];
vector<int> buf[N];
int rmq[20][N];

struct FenwickTree {
	long long f[N];
	void add(int p,long long val) {
		for (; p <= n; p += p & -p) {
			f[p] += val;
		}
	}
	long long get(int p) {
		long long ans = 0;
		for (; p > 0; p -= p & -p) {
			ans += f[p];
		}
		return ans;
	}
};

struct Info {
	FenwickTree a, b;
	void reset() {
		b.add(1, 1);
	}
	void addA(int p,long long val) {
		a.add(p, val);
	}
	void addB(int p,long long val) {
		b.add(p, val);
	}
	void addA(int l,int r, long long val) {
		a.add(l, val);
		a.add(r + 1, -val);
	}
	void addB(int l,int r,long long val) {
		b.add(l, val);
		b.add(r + 1, -val);
	}
	long long get(int p) {
		return a.get(p) * p + b.get(p);
	}
} valL, valR;

long long getL(int p) {
	return valL.get(p);
}

long long getR(int p) {
	return valR.get(p);
}

int get(int l,int r) {
	int lg = __lg(r - l + 1);
	return max(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
}

int anc(int u) {
	if (par[u] == u) {
		return u;
	} else {
		return par[u] = anc(par[u]);
	}
}

void join(int u,int v) {
	u = anc(u), v = anc(v);
	par[v] = u;
	ll[u] = min(ll[u], ll[v]);
	rr[u] = max(rr[u], rr[v]);
}

void debug() {
	printf("valL: ");
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", getL(i));
	}
	puts("");
	printf("valR: ");
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", getR(i));
	}
	puts("");
}

int main() {
	int q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		p[a[i]] = i;
		rmq[0][i] = a[i];
		par[i] = i;
		ll[i] = rr[i] = i;
	} 
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
			rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
		}
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d", l + i);
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d", r + i);
	}
	valL.reset();
	valR.reset();
	for (int i = 1; i <= q; ++i) {
		buf[get(l[i], r[i])].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		int p = ::p[i];
		for (int id : buf[i]) {
			ans[id] = r[id] - l[id] + 1;
			if (l[id] < p) {
				ans[id] += getR(l[id]);
			}
			if (r[id] > p) {
				ans[id] += getL(r[id]);
			}
		}
		bool canL = (p > 1 && a[p] > a[p - 1]);
		bool canR = (p < n && a[p] > a[p + 1]);
		if (canL && canR) {
			int u = anc(p - 1), v = anc(p + 1);
			long long saveL = getR(ll[u]);
			long long saveR = getL(rr[v]);
			valR.addA(ll[u], rr[u], -1);
			valR.addB(ll[u], rr[u], saveR + rr[v] + 1);
			valL.addA(ll[v], rr[v], 1);
			valL.addB(ll[v], rr[v], saveL - ll[u] + 1);
			valL.addA(p, p, 1);
			valL.addB(p, p, saveL - ll[u]);
			valR.addA(p, p, -1);
			valR.addB(p, p, saveR + rr[v]);
			join(p, u), join(p, v);
		} else if (canL) {
			int u = anc(p - 1);
			long long saveL = getR(ll[u]);
			valR.addA(ll[u], rr[u], -1);
			valR.addB(ll[u], rr[u], p + 1);
			valL.addA(p, p, 1);
			valL.addB(p, p, saveL - ll[u]);
			join(p, u);
		} else if (canR) {
			int u = anc(p + 1);
			long long saveR = getL(rr[u]);
			valL.addA(ll[u], rr[u], 1);
			valL.addB(ll[u], rr[u], -p + 1);
			valR.addA(p, p, -1);
			valR.addB(p, p, saveR + rr[u]);
			join(p, u);
		}
		// debug();
	}
	for (int i = 1; i <= q; ++i) {
		printf("%lld ", ans[i]);
	} 
}