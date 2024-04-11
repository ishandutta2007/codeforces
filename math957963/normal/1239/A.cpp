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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	int x, y, z;
	long long ans;
	long long a[N];
	scanf("%d %d", &x, &y);
	a[0] = 2;
	a[1] = 2;
	a[2] = 4;
	for (int i = 3; i < N; i++)a[i] = (a[i - 2] + a[i - 1]) % MOD;
	ans = (a[x] + a[y]) % MOD;
	ans = (ans - 2 + MOD) % MOD;
	printf("%I64d\n", ans);
	return 0;
}