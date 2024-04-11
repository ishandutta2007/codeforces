#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


int main() {
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long l, r, m, ll, rr, mm, s;
	long long ans[N];
	bool dec[N];
	bool v = true;
	scanf("%lld %lld", &n, &k);
	f(i, n) {
		scanf("%lld", &a[i]);
	}
	l = -7000000000000000000;
	r = 7000000000000000000;
	while ((l + 1) < r) {
		m = (l + r) / 2;
		s = 0;
		f(i, n) {
			x = (3 * a[i] * a[i]) - (3 * a[i]) + 1;
			if ((a[i] - 1) < m)s += 0;
			else if ((a[i] - x) >= m)s += a[i];
			else {
				ll = 1;
				rr = a[i];
				while (ll + 1 < rr) {
					mm = (ll + rr) / 2;
					x = (3 * mm * mm) - (3 * mm) + 1;
					if ((a[i] - x) >= m)ll = mm;
					else rr = mm;
				}
				s += ll;
			}
		}
		if (s >= k)l = m;
		else r = m;
	}
	f(i, n) {
		dec[i] = false;
		x = (3 * a[i] * a[i]) - (3 * a[i]) + 1;
		if ((a[i] - 1) < l)ans[i] = 0;
		else if ((a[i] - x) >= l) {
			ans[i] = a[i];
			if ((a[i] - x) == l)dec[i] = true;
		}
		else {
			ll = 1;
			rr = a[i];
			while (ll + 1 < rr) {
				mm = (ll + rr) / 2;
				x = (3 * mm * mm) - (3 * mm) + 1;
				if ((a[i] - x) >= l)ll = mm;
				else rr = mm;
			}
			x = (3 * ll * ll) - (3 * ll) + 1;
			if ((a[i] - x) == l)dec[i] = true;
			ans[i] = ll;
		}
	}
	f(i, n)k -= ans[i];
	f(i, n) {
		if (dec[i]) {
			if (k < 0) {
				ans[i]--;
				k++;
			}
		}
	}
	f(i, n - 1)printf("%lld ", ans[i]);
	printf("%lld\n", ans[n - 1]);


	return 0;
}