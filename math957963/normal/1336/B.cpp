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
	vector<long long>a;
	vector<long long>b;
	vector<long long>c;
	long long n, m, k, t;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	scanf("%lld", &t);
	f(tt, t) {
		a.clear();
		b.clear();
		c.clear();
      	ans = 4000000000000000000;
		scanf("%lld %lld %lld", &n, &m, &k);
		f(i, n) {
			scanf("%lld", &x);
			a.push_back(x);
		}
		f(i, m) {
			scanf("%lld", &x);
			b.push_back(x);
		}
		f(i, k) {
			scanf("%lld", &x);
			c.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		x = 0;
		y = 0;
		z = 0;
		f(i, n) {
			while (x < (m-1)) {
				if (b[x] <= a[i])x++;
				else break;
			}
			if (x > 0) {
				s = a[i] + b[x - 1];
				while (y < (k-1)) {
					if (abs((c[y] * 2) - s) >= abs((c[y + 1] * 2) - s))y++;
					else break;
				}
				s = ((a[i] - b[x - 1])*(a[i] - b[x - 1]));
				s += ((c[y] - b[x - 1])*(c[y] - b[x - 1]));
				s += ((a[i] - c[y])*(a[i] - c[y]));
				ans = min(ans, s);
			}
			s = a[i] + b[x];
			while (z < (k - 1)) {
				if (abs((c[z] * 2) - s) >= abs((c[z + 1] * 2) - s))z++;
				else break;
			}
			s = ((a[i] - b[x])*(a[i] - b[x]));
			s += ((c[z] - b[x])*(c[z] - b[x]));
			s += ((a[i] - c[z])*(a[i] - c[z]));
			ans = min(ans, s);
		}

		x = 0;
		y = 0;
		z = 0;
		f(i, n) {
			while (x < (k-1)) {
				if (c[x] <= a[i])x++;
				else break;
			}
			if (x > 0) {
				s = a[i] + c[x - 1];
				while (y <(m - 1)) {
					if (abs((b[y] * 2) - s) >= abs((b[y + 1] * 2) - s))y++;
					else break;
				}
				s = ((a[i] - c[x - 1])*(a[i] - c[x - 1]));
				s += ((b[y] - c[x - 1])*(b[y] - c[x - 1]));
				s += ((a[i] - b[y])*(a[i] - b[y]));
				ans = min(ans, s);
			}
			s = a[i] + c[x];
			while (z < (m - 1)) {
				if (abs((b[z] * 2) - s) >= abs((b[z + 1] * 2) - s))z++;
				else break;
			}
			s = ((a[i] - c[x])*(a[i] - c[x]));
			s += ((b[z] - c[x])*(b[z] - c[x]));
			s += ((a[i] - b[z])*(a[i] - b[z]));
			ans = min(ans, s);
		}
		printf("%lld\n", ans);
	}

	return 0;
}