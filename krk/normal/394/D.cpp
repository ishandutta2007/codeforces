#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int lim = 20000;
const int Inf = 1000000000;

int n;
int a[Maxn];
int res1 = Inf, res2, res3;

bool Ok(int y, int rad, int &mn, int &mx)
{
	if (abs(y - a[0]) > rad) return false;
	mn = 0, mx = Inf;
	for (int i = 1; i < n && mn <= mx; i++) {
		if (y > a[i] + rad) return false;
		if (y + i * mn < a[i] - rad) {
			mn = (a[i] - rad - y) / i;
			if (y + i * mn < a[i] - rad) mn++;
		}
		if (y + i * mx > a[i] + rad)
			mx = (a[i] + rad - y) / i;
	}
	return mn <= mx;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = a[0] - lim; i <= a[0] + lim; i++) {
		int l = 0, r = lim;
		int cand = Inf, mn, mx;
		while (l <= r) {
			int mid = l + r >> 1, mmn, mmx;
			if (Ok(i, mid, mmn, mmx)) { cand = mid; mn = mmn; mx = mmx; r = mid - 1; }
			else l = mid + 1;
		}
		if (cand < res1) { res1 = cand; res2 = i; res3 = mn; }
	}
	printf("%d\n", res1);
	printf("%d %d\n", res2, res3);
	return 0;
}