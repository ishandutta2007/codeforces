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
#define N 700000


int main() {
	long long b[N];
	int a[N];
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
		scanf("%d", &a[i]);
		x = a[i] + (n - i);
		b[x] += ((long long)a[i]);
	}
	x = 0;
	ans = b[0];
	f(i, N) {
		if (b[i] > b[x]) {
			x = i;
			ans = b[i];
		}
	}

	printf("%I64d\n", ans);


	return 0;
}