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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	int a[N];
	int b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d", &a[i], &b[i]);
	}
	if (n % 2 != 0) {
		printf("NO\n");
		return 0;
	}
	k = n / 2;
	f(i, k) {
		if ((a[i] + a[i + k]) != (a[0] + a[k])) {
			printf("NO\n");
			return 0;
		}
		if ((b[i] + b[i + k]) != (b[0] + b[k])) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");


	return 0;
}