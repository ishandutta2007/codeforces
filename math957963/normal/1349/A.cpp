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
#define N 200010


int main() {
	long long p[N];
	long long min1[N];
	long long min2[N];
	f(i, N) {
		min1[i] = 100;
		min2[i] = 100;
	}
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &a[i]);
	}
	f(i, N)p[i] = 0;
	f(j, n) {
		x = a[j];
		for (long long i = 2; (i*i) <= x; i++) {
			if (x%i == 0) {
				p[i]++;
				y = 0;
				while (x%i == 0) {
					x /= i;
					y++;
				}
				if (y < min1[i]) {
					min2[i] = min1[i];
					min1[i] = y;
				}
				else if (y < min2[i])min2[i] = y;
			}
		}
		if (x > 1) {
			p[x]++;
			y = 1;
			if (y < min1[x]) {
				min2[x] = min1[x];
				min1[x] = y;
			}
			else if (y < min2[x])min2[x] = y;
		}
	}
	ans = 1;
	f(i, N) {
		if (p[i] == n) {
			f(j, min2[i])ans *= i;
		}
		if (p[i] == (n - 1)) {
			f(j, min1[i])ans *= i;
		}
	}
	printf("%lld\n", ans);


	return 0;
}