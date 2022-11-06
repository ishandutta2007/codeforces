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
#define N 1010000

int main() {
	long long n, x;
	long long p[N];
	long long c[N];
	f(i, N)c[i] = 0;
	long long a, b;
	long long kk;
	long long ans, s;
  a=0;
  b=0;
	s = 0;
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &p[i]);
		p[i]--;
		s += ((long long)abs(p[i] - i));
		if (p[i] > i) {
			a++;
			c[p[i] - i]++;
		}
		else {
			b++;
			c[p[i] + n - i]++;
		}
	}
	kk = 0;
	ans = s;
	f(i, n-1) {
		s -= a;
		s += b;
		s -= (n - p[n - i - 1]);
		s += (p[n - i - 1]);
			b--;
			a++;
			x = (i + 1) % n;
			b += c[x];
			a -= c[x];
			if (s < ans) {
				ans = s;
				kk = i + 1;
			}
	}
	printf("%lld %lld\n", ans, kk);
	return 0;
}