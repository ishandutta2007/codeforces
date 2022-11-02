# include <iostream>
# include <cstdio>

using namespace std;

const int mod = 1000000007;

struct M { int v[2][2]; } A, V, c[1<<20];
struct Vec { int v[2]; } a[1<<20], Vec0;

bool E(const M&a) {
	return a.v[0][0] == 1 && a.v[1][1] == 1 && a.v[0][1] == 0 && a.v[1][0] == 0;
}

M operator*(const M&a,const M&b) {
	M ret;
	for(int i = 0; i < 2; ++i) 
		for(int j = 0; j < 2; ++j) 
			ret.v[i][j] = (1ll * a.v[i][0] * b.v[0][j] + 1ll * a.v[i][1] * b.v[1][j]) % mod;
	return ret;
};

Vec operator+(const Vec&a,const Vec&b) {
	Vec ret;
	ret.v[0] = (a.v[0] + b.v[0]) % mod;
	ret.v[1] = (a.v[1] + b.v[1]) % mod;
	return ret;
}

Vec operator*(const M&m,const Vec&vec) {
	Vec ret;
	ret.v[0] = (1ll * vec.v[0] * m.v[0][0] + 1ll * vec.v[1] * m.v[0][1]) % mod;
	ret.v[1] = (1ll * vec.v[0] * m.v[1][0] + 1ll * vec.v[1] * m.v[1][1]) % mod;
	return ret;
}

M pow(M a,int b) {
	M t;
	t.v[0][0] = t.v[1][1] = 1;
	t.v[0][1] = t.v[1][0] = 0;
	while(b) {
		if(b & 1) t = t * a;
		b = b >> 1;
		a = a * a;
	}
	return t;
}

void init(int u,int l,int r) {
	if(l == r) {
		int b;
		scanf("%d", &b);
		M t = pow(A, b - 1);
		a[u].v[0] = t.v[0][0];
		a[u].v[1] = t.v[0][1];
		return;
	}
	c[u].v[0][0] = c[u].v[1][1] = 1;
	c[u].v[0][1] = c[u].v[1][0] = 0;
	int mid = (l + r) >> 1;
	init(u << 1, l, mid);
	init(u << 1 | 1, mid + 1, r);
	a[u] = a[u << 1] + a[u << 1 | 1];
}

int L, R;

void change(int u,int l,int r) {
	if(R < l || r < L) return;
	if(L <= l && r <= R) {
		c[u] = V * c[u];
		a[u] = V * a[u];
		return;
	}
	if(!E(c[u])) {
		c[u << 1] = c[u] * c[u << 1];
		a[u << 1] = c[u] * a[u << 1];
		c[u << 1 | 1] = c[u] * c[u << 1 | 1];
		a[u << 1 | 1] = c[u] * a[u << 1 | 1];
		c[u].v[0][0] = c[u].v[1][1] = 1;
		c[u].v[0][1] = c[u].v[1][0] = 0;
	}
	int mid = (l + r) >> 1;
	change(u << 1, l, mid);
	change(u << 1 | 1, mid + 1, r);
	a[u] = a[u << 1] + a[u << 1 | 1];
}

Vec query(int u,int l,int r) {
	if(R < l || r < L) return Vec0;
	if(L <= l && r <= R) return a[u];
	int mid = (l + r) >> 1;
	return c[u] * (query(u << 1, l, mid) + query(u << 1 | 1, mid + 1, r));
}

int main() {
	A.v[0][0] = A.v[0][1] = A.v[1][0] = 1;
	int n, m;
	scanf("%d%d", &n, &m);
	init(1, 1, n);
	for(int i = 0; i < m; ++i) {
		int op, x;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d%d", &L, &R, &x);
			V = pow(A, x);
			change(1, 1, n);
		} else {
			scanf("%d%d", &L, &R);
			Vec vec = query(1, 1, n);
			printf("%d\n", vec.v[0]);
		}
	}
	return 0;
}