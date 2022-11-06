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
#define N 200010


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
	x = 0;
	y = 0;
	f(i, n) {
		scanf("%d", &a[i]);
		if (a[i] >= 0) {
			x += a[i];
			b[i] = x;
		}
		else b[i] = x + a[i];
	}
	f(i, n) {
		printf("%d", b[i]);
		if (i < (n - 1))printf(" ");
		else printf("\n");
	}



	return 0;
}