#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1000005;

int n;
ld mx[Maxn], mn[Maxn];
ld P[Maxn], Q[Maxn];

void Solve(ld X, ld Y, ld A, ld B, ld &p, ld &q)
{
	ld a = 1;
	ld b = B - A - X;
	ld c = Y - X * B;
	ld d = max(b * b - 4 * a * c, 0.0l);
	ld x1 = (-b + sqrt(d)) / (2 * a);
	if (x1 + 1e-9 < 0 || x1 > 1 + 1e-9)
		x1 = (-b - sqrt(d)) / (2 * a);
	q = x1;
	p = X - q;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double x; scanf("%lf", &x);
		mx[i] = x;
	}
	for (int i = 0; i < n; i++) {
		double x; scanf("%lf", &x);
		mn[i] = x;
	}
	ld B = 0, A = 0;
	for (int i = n - 1; i >= 0; i--) {
		Solve(mx[i] + mn[i], mn[i], A, B, P[i], Q[i]);
		A += P[i]; B += Q[i];
	}
	for (int i = 0; i < n; i++)
		printf("%.15lf%c", double(P[i]), i + 1 < n? ' ': '\n');
	for (int i = 0; i < n; i++)
		printf("%.15lf%c", double(Q[i]), i + 1 < n? ' ': '\n');
	return 0;
}