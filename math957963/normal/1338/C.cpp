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
	long long b[N];
	long long c[N];
	f(i, N)a[i] = 0;
	long long n, k, t;
	long long x, y, z;
	long long xx, yy, zz;
	long long s, ans;
	bool v = true;
	ans = 0;

	a[0] = 1;
	f(i, 30)a[i + 1] = a[i] * 4;



	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld", &n);
		k = (n + 2) % 3;
		n = (n + 2) / 3;
		x = 0;
		y = 0;
		while(true){
			y += a[x];
			if (n <= y)break;
			x++;
		}
		xx = a[x] * 2 - (y - n) - 1;
		z = a[x] - (y - n) - 1;
		yy = 2 * a[x];
		f(i, x) {
			c[i] = z % 4;
			z /= 4;
			if (c[i] == 1)c[i] = 2;
			else if (c[i] == 2)c[i] = 3;
			else if (c[i] == 3)c[i] = 1;
			yy += (c[i] * a[i]);
		}
		zz = xx ^ yy;
		if (k == 0)printf("%lld\n", xx);
		else if (k == 1)printf("%lld\n", yy);
		else if (k == 2)printf("%lld\n", zz);
	}

	return 0;
}