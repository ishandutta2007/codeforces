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
	f(i, N)a[i] = 0;
	int n, k;
	int q;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &q);
	f(qq, q) {
		v = false;
		scanf("%d", &n);
		y = 0;
		z = 0;
		f(i, n) {
			scanf("%I64d", &x);
			y += x;
			z ^= x;
		}
		printf("2\n");
		printf("%I64d %I64d\n", z, y + z);
	}

	return 0;
}