#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, c, a[100100]; long long s[100100], h[4004004];

void go(int l, int r)
{
	h[c++] = s[r] - s[l];
	if (a[l] == a[r - 1]) return;

	int m = (a[l] + a[r - 1]) / 2;
	int mp = upper_bound(a + l, a + r, m) - a;
	if (l == mp || mp == r) return;
	go(l, mp); go(mp, r);
}

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		sort(a, a + n);
		for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

		c = 0;
		go(0, n);
		h[c++] = 1e18;
		sort(h, h + c);
		while (m--){
			long long s; scanf ("%lld", &s);
			int i = lower_bound(h, h + c, s) - h;
			puts(h[i] == s ? "Yes" : "No");
		}
	}
	return 0;
}