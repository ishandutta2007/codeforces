#pragma GCC optimize("O3")
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
#define N 1000100


int main() {
	vector<long long>a;
	long long p[30];
	long long n, k, t;
	long long x, y;
	long long pst;
	long long s, ans;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld", &n, &k);
		f(i, n) {
			scanf("%d", &x);
			a.push_back(x);
		}
		sort(a.begin(), a.end(), greater<long long>());
		p[0] = k;
		f(i, 29)p[i + 1] = (p[i] * p[i]) % MOD;
		s = 0;
		ans = 0;
		s = 1;
		x = a[0];
		y = 1;
		f(i, 20) {
			if (x % 2 == 1)y = (y*p[i]) % MOD;
			x /= 2;
		}
		ans = y;
		pst = y;
		f(i, n - 1) {
			if ((s > 0)&&(k>1)) {
				f(j, a[i] - a[i + 1]) {
					if (s > MOD)break;
					s = s * k;
				}
			}
			if (a[i] != a[i + 1]) {
				x = a[i + 1];
				y = 1;
				f(i, 20) {
					if (x % 2 == 1)y = (y*p[i]) % MOD;
					x /= 2;
				}
				pst = y;
			}
			else y = pst;
			if (s == 0) {
				s = 1;
				ans = y;
			}
			else {
				s--;
				ans = (ans + MOD - y) % MOD;
			}
		}
		printf("%lld\n", ans);
		a.clear();
	}

	return 0;
}