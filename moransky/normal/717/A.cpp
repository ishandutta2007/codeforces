// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int P = 1e9 + 7, S = 505;

int T, m;

LL l, r;

int k;

int o;

struct C{
	int x, y;
	// x + y * sqrt(o);
} A, B, a, b;

// fn = Aa^n + Bb^n

int inline power(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1ll * ret * a % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return ret;
}

int mod(int x) {
	return x >= P ? x - P : x;
}

C operator + (const C &a, const C &b) {
	return (C) { mod(a.x + b.x), mod(a.y + b.y) };
};

C operator * (const C &a, const C &b) {
	C c;
	c.x = (1ll * a.x * b.x + 1ll * a.y * b.y % P * o) % P;
	c.y = (1ll * a.x * b.y + 1ll * a.y * b.x) % P;
	return c;
};

int inline inv(int x) {
	return power(x, P - 2);
}

int I, s[S][S], c[S][S];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

C pw(C a, LL b) {
	C ret = (C) { 1, 0 };
	while (b) {
		if (b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}

C calc(C a, LL n) {
	if (n == 1) return (C) { 1, 0 };
	if (n & 1) {
		C v = calc(a, n - 1);
		return (v * a + (C) { 1, 0 });
	} else {
		C v = calc(a, n / 2);
		return v + v * pw(a, n / 2);
	}
}

C get(C a) {
	return pw(a, l) * calc(a, r - l + 1);
}

void inline wk() {
	if (l > r) {
		puts("0");
		return;
	}
	s[0][0] = 1;
	c[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * (i - 1ll)) % P;
			c[i][j] = mod(c[i - 1][j - 1] + c[i - 1][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int w = s[k][i];
		C z = (C) { 0, 0 };
		if ((k - i) & 1) w = mod(P - w);
		for (int j = 0; j <= i; j++) {
			C u = pw(A, j) * pw(B, i - j);
			u = u * get(pw(a, j) * pw(b, i - j));
			u = u * (C) { c[i][j], 0 };
			z = z + u;
		}
		assert(!z.y);
		add(ans, 1ll * w * z.x % P);
	}
	ans = 1ll * ans * I % P;
	printf("%d\n", ans);
}

int main() {
    T = 1, m = 2;
    if (m == 2) {
    	o = 5;
    	int inv2 = inv(2), inv10 = inv(10);
    	A = (C) { inv2, P - inv10 };
    	B = (C) { inv2, inv10 };
    	a = (C) { inv2, P - inv2 };
    	b = (C) { inv2, inv2};
    } else {
    	o = 3;
    	int inv2 = inv(2);
    	int inv3 = inv(3);
    	A = (C) { inv2, P - inv3 };
    	B = (C) { inv2, inv3 };
    	a = (C) { 2, P - 1};
    	b = (C) { 2, 1 };
    }
    while (T--) {
    	read(k);
    	read(l), read(r); l++, r++;
    	I = 1;
    	for (int i = 1; i <= k; i++) I = 1ll * I * i % P;
    	I = inv(I);
    	if (m == 3) l = (l + 1) / 2, r /= 2;
    	wk();
    }
    return 0;
}