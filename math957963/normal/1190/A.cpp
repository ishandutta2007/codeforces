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
	long long n, m, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	f(i, m) {
		scanf("%I64d", &a[i]);
		a[i]--;
		a[i] -= i;
	}
	ans = 0;
	x = 0;
	while (x < m) {
		y = a[x] / k;
		y = (y*k);
		z = y + k;
		s = 0;
		while (a[x] + s < z) {
			s++;
			x++;
		}
		ans++;
	}

	printf("%I64d\n", ans);


	return 0;
}