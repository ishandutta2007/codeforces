#include <bits/stdc++.h>
using namespace std;

const int N = 405;
const int inf = 1e9 + 123;

int n, m;
int a[N];
int f[N][N][N];

int get(int ref,int l,int r,int mid) {
	return max(f[ref - 1][l][mid], a[r] - a[mid]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int ref = 0; ref <= n; ++ref) {
		for (int l = 0; l <= n; ++l) {
			for (int r = 0; r <= n; ++r) {
				f[ref][l][r] = inf;
			}
		} 
	}
	for (int l = 1; l <= n; ++l) {
		for (int r = l; r <= n; ++r) {
			f[0][l][r] = a[r] - a[l];
		}
	}
	for (int ref = 1; ref <= n; ++ref) {
		for (int l = 1; l <= n; ++l) {
			int ptr = l;
			for (int r = l; r <= n; ++r) {
				while (ptr + 1 <= r && get(ref, l, r, ptr) > get(ref, l, r, ptr + 1)) {
					++ptr;
				}
				f[ref][l][r] = get(ref, l, r, ptr);
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		int l, r, cost, ref;
		scanf("%d %d %d %d", &l, &r, &cost, &ref);
		ans = max(ans, 1LL * cost * f[ref][l][r]);
	} 
	printf("%lld\n", ans);
}