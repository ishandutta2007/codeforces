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
	long long n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	x = 0;
	f(i, n) {
		scanf("%I64d", &k);
		if (k == 1)x++;
		else {
			if (k % 2 == 1) {
				k -= 3;
				ans++;
			}
			if (x <= (k / 2)) {
				ans += x;
				k -= (2 * x);
				ans += (k / 3);
				x = k % 3;
			}
			else {
				ans += (k / 2);
				x -= (k / 2);
			}
		}
	}


	printf("%I64d\n", ans);


	return 0;
}