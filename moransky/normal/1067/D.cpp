#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define x(u) (g[u].p)
#define y(u) (g[u].p * g[u].a)
using namespace std;
 
typedef long long LL;

const double eps = 1e-14;
 
const int N = 100005, L = 34;
 
LL T;
 
int n, q[N], hh = 1, tt = 0;
 
double B;
 
struct Game{
	int a, b;
	double p;
	bool operator < (const Game &y) const {
		if (fabs(y.p - p) < eps) return a * p > y.a * y.p;
		return p < y.p;	
	}
} g[N];
 
double inline K(int a, int b) {
	return (y(b) - y(a)) / (x(b) - x(a));
}
 
struct Matrix{
	int n, m;
	double w[3][3];
	Matrix operator * (const Matrix b) const {
		Matrix c; c.n = n, c.m = b.m;
		memset(c.w, 0, sizeof c.w);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < b.m; j++) 
				for (int k = 0; k < m; k++)
					c.w[i][j] += w[i][k] * b.w[k][j];
		return c;
	}
} res, A[L];
 
Matrix inline build(int j) { 
	Matrix c; memset(c.w, 0, sizeof c.w);
	c.n = 3, c.m = 3;
	c.w[0][0] = 1 - g[j].p, c.w[1][0] = g[j].p * B, c.w[2][0] = g[j].p * g[j].a;
	c.w[1][1] = c.w[2][1] = c.w[2][2] = 1;
	return c;
}
 
double inline get(double S, int j) {
	return g[j].p * (g[j].a - S);
}
 
int main() {
	scanf("%d%lld", &n, &T);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%lf", &g[i].a, &g[i].b, &g[i].p);
		B = max(B, g[i].b * g[i].p);
	}
	sort(g + 1, g + 1 + n);
	for (int i = 1; i <= n; i++) {
	    if (i > 1 && fabs(g[i].p - g[i - 1].p) < eps) continue;
	    while (hh < tt && K(q[tt - 1], q[tt]) <= K(q[tt], i)) tt--;
		q[++tt] = i;
	}
	res.n = 1, res.m = 3, res.w[0][2] = 1;
	LL x = 0; double k = 0;
	while (x != T) {
		while (hh < tt && get(k, q[hh]) < get(k, q[hh + 1])) hh++;
		A[0] = build(q[hh]);
		for (int i = 1; i < L; i++) A[i] = A[i - 1] * A[i - 1];
		for (int i = L - 1; ~i; i--) {
			if (x + (1ll << i) < T) {
				Matrix C = res * A[i];
				double nK = C.w[0][0] - B * C.w[0][1];
				if (hh == tt || get(nK, q[hh]) > get(nK, q[hh + 1]))
					res = C, x += 1ll << i;
			} 
		}
		res = res * A[0], k = res.w[0][0] - B * res.w[0][1], ++x;
	}		
	printf("%.16f\n", res.w[0][0]);
	return 0;
}