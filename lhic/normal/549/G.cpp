#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 220000;
const int INF = 1000000000;

int rmq[MAXN * 4];

int a[MAXN];
int ans[MAXN];
int n;


void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = tl;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	int xl = rmq[v * 2 + 1];
	int xr = rmq[v * 2 + 2];
	if (a[xl] + xl >= a[xr] + xr)
		rmq[v] = xl;
	else
		rmq[v] = xr;
}



void upd(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		rmq[v] = tl;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	int xl = rmq[v * 2 + 1];
	int xr = rmq[v * 2 + 2];
	if (a[xl] + xl >= a[xr] + xr)
		rmq[v] = xl;
	else
		rmq[v] = xr;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	build(0, 0, n);
	for (int i = n - 1; i >= 0; --i) {
		int x = rmq[0];
		ans[i] = a[x] + x - i;
		a[x] = -INF;
		upd(0, 0, n, x);
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] < 0) {
			cout << ":(";
			return 0;
		}
	}
	for (int i = 0; i < n - 1; ++i)
		if (ans[i] > ans[i + 1]) {
			cout << ":(";
			return 0;
		}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	return 0;
}