#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 1e+9;
const int lim = 111;
const int maxloop = 1005;
int ar[lim];
int bs[lim * maxloop];
ll cnt[301];

int main() {
	int n, t, i, most = 1;
	ll res = 0, addres = 0;
	cin >> n >> t;
	for (i = 0; i < n; ++i) {
		cin >> ar[i];
		++cnt[ar[i]];
	}
	for (i = 2; i <= 300; ++i)
		if (cnt[i] > cnt[most]) most = i;
	if (t > maxloop) {
		addres = (t - maxloop) * cnt[most];
		t = maxloop;
	}
	bs[0] = 0;
	for (i = 1; i < lim * maxloop; ++i)
		bs[i] = inf;
	int l, r, m;
	for (i = 0; i < n * t; ++i) {
		for (l = 0, r = n * t; l + 1 < r;) {
			m = (l + r) / 2;
			(bs[m] <= ar[i % n] ? l : r) = m;
		}
		bs[l + 1] = min(bs[l + 1], ar[i % n]);
		if (l + 1 > res) res = l + 1;
	}
	cout << res + addres;
	return 0;
}