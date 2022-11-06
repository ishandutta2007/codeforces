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
#define N 400000


int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	x = -1;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
		if (a[i] != a[0]) {
			y = i;
			if (x < 0)x = i;
		}
	}
	
	if (a[0] != a[n - 1]) {
		printf("%d\n", n - 1);
		return 0;
	}
	ans = max(y, n - x - 1);
	printf("%d\n", ans);
	return 0;

	return 0;
}