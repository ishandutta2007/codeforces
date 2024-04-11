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
	vector<long long>c;
	f(i, N)a[i] = 0;
	long long n, k, q;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d", &n,&q);
	x = -1;
	k = -1;
	f(i, n) {
		scanf("%I64d", &a[i]);
		if (x < a[i]) {
			x = a[i];
			k = i;
		}
		if (i == 0) b[i] = a[i];
		else b[i] = max(b[i - 1], a[i]);
	}
	for (long long i = k + 1; i < n; i++)c.push_back(a[i]);
	for (long long i = 0; i < k; i++) {
		if (i == 0) {
			if (a[0] > a[1]) {
				c.push_back(a[1]);
				x = a[0];
			}
			else {
				c.push_back(a[0]);
				x = a[1];
			}
		}
		else {
			if (a[i + 1] > x) {
				c.push_back(x);
				x = a[i + 1];
			}
			else c.push_back(a[i + 1]);
		}
	}
	f(qq, q) {
		scanf("%I64d", &x);
		if (x > k) {
			x -= (k + 1);
			x = x % (n - 1);
			printf("%I64d %I64d\n", a[k], c[x]);
		}
		else {
			printf("%I64d %I64d\n", b[x - 1], a[x]);
		}
	}


	return 0;
}