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
#define N 200000


int main() {
	long long n, l, r, m, x, y, z, s;
	char a[11] = "codeforces";
	scanf("%lld", &n);
	l = 9;
	r = 1000;
	while ((l + 1) < r) {
		m = (l + r) / 2;
		s = 1;
		f(i, 10) {
			x = (m + i) / 10;
			s *= x;
			if (s >= n)break;
		}
		if (s >= n)r = m;
		else l = m;
	}
	f(i, 10) {
		x = (r + i) / 10;
		f(j, x)printf("%c", a[i]);
	}
	printf("\n");

	return 0;
}