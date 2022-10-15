#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


int main() {

	int T;
	read(T);
	while (T--) {
		int n, k;read(n); read(k);
		vector <LL> a;
		for (int i = 1; i <= n; i++) {
			LL x; scanf("%lld", &x);
			if (x) a.push_back(x);
		}
		n = (int)a.size();
		sort(a.begin(), a.end());
		LL p = 1; int m = 0;
		for (int i = 1; n; i++) {
			p *= k;
			m++;
			if (p >= a[n - 1]) break;
		}
		for ( ; n && m >= 0; p /= k, m--) {
			if (a[n - 1] == p) a.pop_back(), n--;
			else if (a[n - 1] > p) {
				LL x = a[n - 1] - p;
				a.pop_back(); a.push_back(x);
				sort(a.begin(), a.end());
			}
		}
		puts(n ? "NO" : "YES");
	}
}