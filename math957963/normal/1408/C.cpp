#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 500010
#define MOD 998244353



int main() {
	int t, n;
	long double a[N];
	int x, y;
	long double tx, ty, sx, sy, nx, ny, z;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		cin >> a[n + 1];
		a[0] = 0;
		rep(i, n)cin >> a[i + 1];
		x = 0;
		y = n + 1;
		tx = 0;
		ty = 0;
		sx = 1;
		sy = 1;
		while ((x + 1) < y) {
			nx = tx + ((a[x + 1] - a[x]) / sx);
			ny = ty + ((a[y] - a[y - 1]) / sy);
			if (nx < ny) {
				x++;
				tx = nx;
				sx += 1;
			}
			else {
				y--;
				ty = ny;
				sy += 1;
			}
		}
		if (tx < ty) {
			z = a[x + 1] - a[x] - (sx*(ty - tx));
			z = ty + (z / (sx + sy));
		}
		else {
			z = a[x + 1] - a[x] - (sy*(tx - ty));
			z = tx + (z / (sx + sy));
		}
      printf("%.10Lf\n",z);
	}
	return 0;
}