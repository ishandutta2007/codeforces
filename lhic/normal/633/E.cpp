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

const int MAXN = 1000010;

int rmq1[MAXN * 4];
int rmq2[MAXN * 4];
int arr[MAXN];
int vv[MAXN];
int cc[MAXN];
int n, k;

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq1[v] = vv[tl];
		rmq2[v] = cc[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq1[v] = max(rmq1[v * 2 + 1], rmq1[v * 2 + 2]);
	rmq2[v] = min(rmq2[v * 2 + 1], rmq2[v * 2 + 2]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (tr <= l || r <= tl)
		return make_pair(0, 1000000000);
	if (l <= tl && tr <= r)
		return make_pair(rmq1[v], rmq2[v]);
	int m = (tl + tr) >> 1;
	pair<int, int> g1 = get(v * 2 + 1, tl, m, l, r);
	pair<int, int> g2 = get(v * 2 + 2, m, tr, l, r);
	g1.first = max(g1.first, g2.first);
	g1.second = min(g1.second, g2.second);
	return g1;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", vv + i), vv[i] *= 100;
	for (int i = 0; i < n; ++i)
		scanf("%d", cc + i);
	int now = 0;
	build(0, 0, n);
	for (int i = 0; i < n; ++i) {
		now = max(now, i);
		pair<int, int> gnow = get(0, 0, n, i, now);
		while (now < n && max(vv[now], gnow.first) <= min(cc[now], gnow.second))
			gnow.first = max(gnow.first, vv[now]), gnow.second = min(gnow.second, cc[now]), ++now;
		arr[i] = gnow.first;
		if (now < n)
			arr[i] = max(arr[i], min(gnow.second, cc[now]));
	}

//	for (int i = 0; i < n; ++i)
//		cerr << arr[i] << " ";

	sort(arr, arr + n);
	reverse(arr, arr + n);
	ld d = (ld)k / n;
	ld ans = 0;
	for (int i = n - 1; i >= k - 1; --i) {
		if (d < 1e-22)
			break;
		ans += d * arr[i];
		if (i > 0)
			d /= i, d *= (i - k + 1);
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";

	return 0;
}